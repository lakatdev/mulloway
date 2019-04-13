#include <drivers/vga.h>
#include <common/functions.h>

VideoGraphicsArray::VideoGraphicsArray() : 
    miscPort(0x3c2),
    crtcIndexPort(0x3d4),
    crtcDataPort(0x3d5),
    sequencerIndexPort(0x3c4),
    sequencerDataPort(0x3c5),
    graphicsControllerIndexPort(0x3ce),
    graphicsControllerDataPort(0x3cf),
    attributeControllerIndexPort(0x3c0),
    attributeControllerReadPort(0x3c1),
    attributeControllerWritePort(0x3c0),
    attributeControllerResetPort(0x3da)
{
}

VideoGraphicsArray::~VideoGraphicsArray(){
}



void VideoGraphicsArray::WriteRegisters(uint8_t* registers){
    miscPort.Write(*(registers++));

    for(uint8_t i = 0; i < 5; i++){
        sequencerIndexPort.Write(i);
        sequencerDataPort.Write(*(registers++));
    }

    crtcIndexPort.Write(0x03);
    crtcDataPort.Write(crtcDataPort.Read() | 0x80);
    crtcIndexPort.Write(0x11);
    crtcDataPort.Write(crtcDataPort.Read() & ~0x80);

    registers[0x03] = registers[0x03] | 0x80;
    registers[0x11] = registers[0x11] & ~0x80;

    for(uint8_t i = 0; i < 25; i++){
        crtcIndexPort.Write(i);
        crtcDataPort.Write(*(registers++));
    }
    for(uint8_t i = 0; i < 9; i++){
        graphicsControllerIndexPort.Write(i);
        graphicsControllerDataPort.Write(*(registers++));
    }
    for(uint8_t i = 0; i < 21; i++){
        attributeControllerResetPort.Read();
        attributeControllerIndexPort.Write(i);
        attributeControllerWritePort.Write(*(registers++));
    }

    attributeControllerResetPort.Read();
    attributeControllerIndexPort.Write(0x20);

}

bool VideoGraphicsArray::SupportsMode(uint32_t width, uint32_t height, uint32_t colordepth){
    return width == 320 && height == 200 && colordepth == 8;
}

bool VideoGraphicsArray::SetMode(uint32_t width, uint32_t height, uint32_t colordepth){
    if(!SupportsMode(width, height, colordepth))
        return false;

    /*unsigned char g_720x480x16[] =
    {
    // MISC 
        0xE7,
    // SEQ 
        0x03, 0x01, 0x08, 0x00, 0x06,
    // CRTC
        0x6B, 0x59, 0x5A, 0x82, 0x60, 0x8D, 0x0B, 0x3E,
        0x00, 0x40, 0x06, 0x07, 0x00, 0x00, 0x00, 0x00,
        0xEA, 0x0C, 0xDF, 0x2D, 0x08, 0xE8, 0x05, 0xE3,
        0xFF,
    // GC 
        0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x05, 0x0F,
        0xFF,
    // AC 
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x01, 0x00, 0x0F, 0x00, 0x00,
    };*/
    
    unsigned char g_320x200x256[] ={
        // MISC 
            0x63,
        // SEQ 
            0x03, 0x01, 0x0F, 0x00, 0x0E,
        // CRTC 
            0x5F, 0x4F, 0x50, 0x82, 0x54, 0x80, 0xBF, 0x1F,
            0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x9C, 0x0E, 0x8F, 0x28, 0x40, 0x96, 0xB9, 0xA3,
            0xFF,
        // GC 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x05, 0x0F,
            0xFF,
        // AC 
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
            0x41, 0x00, 0x0F, 0x00, 0x00
    };

    WriteRegisters(g_320x200x256);
    return true;
}


uint8_t* VideoGraphicsArray::GetFrameBufferSegment(){
    graphicsControllerIndexPort.Write(0x06);
    uint8_t segmentNumber = graphicsControllerDataPort.Read() & (3<<2);
    switch(segmentNumber){
        default:
        case 0<<2: return (uint8_t*)0x00000;
        case 1<<2: return (uint8_t*)0xA0000;
        case 2<<2: return (uint8_t*)0xB0000;
        case 3<<2: return (uint8_t*)0xB8000;
    }
}

void VideoGraphicsArray::PutPixel(uint32_t x, uint32_t y,  uint8_t colorIndex){
    uint8_t* pixelAddress = GetFrameBufferSegment() + 320*y + x;
    *pixelAddress = colorIndex;
}

uint8_t VideoGraphicsArray::GetColorIndex(string color){
    if(common::equals(color, "black"))
        return 0x00;
    else if(common::equals(color, "blue"))
        return 0x01;
    else if(common::equals(color, "green"))
        return 0x02;
    else if(common::equals(color, "cyan"))
        return 0x03;
    else if(common::equals(color, "red"))
        return 0x04;
    else if(common::equals(color, "magenta"))
        return 0x05;
    else if(common::equals(color, "brown"))
        return 0x06;
    else if(common::equals(color, "light_gray"))
        return 0x07;
    else if(common::equals(color, "dark_gray"))
        return 0x08;
    else if(common::equals(color, "light_blue"))
        return 0x09;
    else if(common::equals(color, "light_green"))
        return 0x0A;
    else if(common::equals(color, "light_cyan"))
        return 0x0B;
    else if(common::equals(color, "light_red"))
        return 0x0C;
    else if(common::equals(color, "light_magena"))
        return 0x0D;
    else if(common::equals(color, "yellow"))
        return 0x0E;
    else if(common::equals(color, "white"))
        return 0x0F;
    return 0x00;
}

/*
    Colors:
    0: Black
    1: Blue
    2: Green
    3: Cyan
    4: Red
    5: Magenta
    6: Brown
    7: Light Gray
    8: Dark Gray
    9: Light Blue
    10: Light Green
    11: Light Cyan
    12: Light Red
    13: Light Magenta
    14: Yellow
    15: White
*/
void VideoGraphicsArray::PutPixel(uint32_t x, uint32_t y,  string color){
    PutPixel(x,y, GetColorIndex(color));
} 
