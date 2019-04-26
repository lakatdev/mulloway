#include <common/types.h>
#include <common/functions.h>
#include <drivers/vga.h>
#include <common/programs.h>

namespace graphics{
    VideoGraphicsArray vga;

    void enable(string color){
        vga.SetMode(320,200,8);
        for(int y = 0; y < 200; y++)
            for(int x = 0; x < 320; x++)
                vga.PutPixel(x, y, color);
    }

    void drawScreen(string color){
        for(int y = 0; y < 200; y++)
                    for(int x = 0; x < 320; x++)
                        vga.PutPixel(x, y, color);
    }

    void drawPixel(int x, int y, string color){
        vga.PutPixel(x, y, color);
    }

    void drawRect(int x, int y, int w, int h, string color){
        for(int x1 = 0; x1 < w; x1++)
                        for(int y1 = 0; y1 < h; y1++)
                            vga.PutPixel(x1 + x, y1 + y, color);
    }
    
    void drawImage(int x, int y, string code){
        int og_x = x;
        for (int i = 0; code[i] != '\0'; ++i){
            switch (code[i]){
                case 'n':{
                    drawPixel(x, y, "black");
                    x++;
                    break;
                }
                case 'b':{
                    drawPixel(x, y, "blue");
                    x++;
                    break;
                }
                case 'g':{
                    drawPixel(x, y, "green");
                    x++;
                    break;
                }
                case 'c':{
                    drawPixel(x, y, "cyan");
                    x++;
                    break;
                }
                case 'r':{
                    drawPixel(x, y, "red");
                    x++;
                    break;
                }
                case 'm':{
                    drawPixel(x, y, "magenta");
                    x++;
                    break;
                }
                case 'o':{
                    drawPixel(x, y, "brown");
                    x++;
                    break;
                }
                case 'l':{
                    drawPixel(x, y, "light_gray");
                    x++;
                    break;
                }
                case 'd':{
                    drawPixel(x, y, "dark_gray");
                    x++;
                    break;
                }
                case 's':{
                    drawPixel(x, y, "light_blue");
                    x++;
                    break;
                }
                case 'e':{
                    drawPixel(x, y, "light_green");
                    x++;
                    break;
                }
                case 'z':{
                    drawPixel(x, y, "light_cyan");
                    x++;
                    break;
                }
                case 'h':{
                    drawPixel(x, y, "light_red");
                    x++;
                    break;
                }
                case 'f':{
                    drawPixel(x, y, "light_magenta");
                    x++;
                    break;
                }
                case 'y':{
                    drawPixel(x, y, "yellow");
                    x++;
                    break;
                }
                case 'w':{
                    drawPixel(x, y, "white");
                    x++;
                    break;
                }
                case 'x':{
                    x = og_x;
                    y++;
                    break;
                }
                case 'k':{
                    x++;
                    break;
                }
            }
        }
    }
    
    void drawString(int x, int y, string str, string color){
        if (x > 315)
            x = 315;
        int place = x;
        for (int i = 0; str[i] != '\0'; ++i){
            if (place > 315){
                place = x;
                y += 8;
            }
            switch (str[i]){
                case ' ':
                    place += 5;
                    break;
                case '\n':
                    y += 8;
                    place = x; 
                    break;
                default:
                    drawChar(place, y, str[i], color);
                    place += 5;
                    break;
            }
        }
    }
    
    void drawChar(int x, int y, char ch, string color){
        switch (ch){
            case 'a':{
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 4, y + 6, color);
                break;
            }
            case 'b':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 4, color);
                break;
            }
            case 'c':{
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case 'd':{
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 4, color);
                break;
            }
            case 'e':{
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 3, y + 3, color);
                break;
            }
            case 'f':{
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 3, y + 1, color);
                break;
            }
            case 'g':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case 'h':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 4, color);
                break;
            }
            case 'i':{
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case 'j':{
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case 'k':{
                vga.PutPixel(x, y + 1, color);
                vga.PutPixel(x, y + 2, color);
                vga.PutPixel(x, y + 3, color);
                vga.PutPixel(x, y + 4, color);
                vga.PutPixel(x, y + 5, color);
                vga.PutPixel(x, y + 6, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case 'l':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case 'm':{
                vga.PutPixel(x, y + 4, color);
                vga.PutPixel(x, y + 5, color);
                vga.PutPixel(x, y + 6, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 4, y + 4, color);
                vga.PutPixel(x + 4, y + 5, color);
                vga.PutPixel(x + 4, y + 6, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 3, y + 3, color);
                break;
            }
            case 'n':{
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 2, y + 3, color);
                break;
            }
            case 'o':{
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case 'p':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 2, y + 4, color);
                break;
            }
            case 'q':{
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 4, color);
                break;
            }
            case 'r':{
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 3, y + 2, color);
                break;
            }
            case 's':{
                vga.PutPixel(x, y + 3, color);
                vga.PutPixel(x, y + 6, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case 't':{
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 3, y + 2, color);
                break;
            }
            case 'u':{
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case 'v':{
                vga.PutPixel(x, y + 2, color);
                vga.PutPixel(x, y + 3, color);
                vga.PutPixel(x, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                break;
            }
            case 'w':{
                vga.PutPixel(x, y + 3, color);
                vga.PutPixel(x, y + 4, color);
                vga.PutPixel(x, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 4, y + 3, color);
                vga.PutPixel(x + 4, y + 4, color);
                vga.PutPixel(x + 4, y + 5, color);
                break;
            }
            case 'x':{
                vga.PutPixel(x, y + 2, color);
                vga.PutPixel(x, y + 6, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 4, y + 2, color);
                vga.PutPixel(x + 4, y + 6, color);
                break;
            }
            case 'y':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 3, y + 3, color);
                break;
            }
            case 'z':{
                vga.PutPixel(x, y + 2, color);
                vga.PutPixel(x, y + 5, color);
                vga.PutPixel(x, y + 6, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case '/':{
                vga.PutPixel(x, y + 6, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 3, y + 1, color);
                break;
            }
            case '1':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case '2':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case '3':{
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case '4':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case '5':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case '6':{
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case '7':{
                vga.PutPixel(x, y + 1, color);
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 4, color);
                break;
            }
            case '8':{
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 3, y + 3, color);
                break;
            }
            case '9':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 3, y + 3, color);
                break;
            }
            case '0':{
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 3, y + 3, color);
                break;
            }
            case '.':{
                vga.PutPixel(x + 1, y + 6, color);
                break;
            }
            case ',':{
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case '!':{
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case '?':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 1, y + 6, color);
                break;
            }
            case '-':{
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 4, color);
                break; 
            }
            case '+':{
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 4, color);
                break;
            }
            case '=':{
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 3, y + 5, color);
                break;
            }
            case '*':{
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 3, y + 2, color);
                break;
            }
            case '\\':{
                vga.PutPixel(x, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case '|':{
                vga.PutPixel(x + 2, y + 0, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case '[':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case ']':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case '{':{
                vga.PutPixel(x + 0, y + 3, color);
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 3, y + 0, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case '}':{
                vga.PutPixel(x + 0, y + 0, color);
                vga.PutPixel(x + 0, y + 6, color);
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 3, y + 3, color);
                break;
            }
            case '\'':{
                vga.PutPixel(x + 2, y + 0, color);
                vga.PutPixel(x + 2, y + 1, color);
                break;
            }
            case '\"':{
                vga.PutPixel(x + 1, y + 0, color);
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 3, y + 0, color);
                vga.PutPixel(x + 3, y + 1, color);
                break;
            }
            case ';':{
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case ':':{
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 5, color);
                break;
            }
            case '<':{
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 3, y + 5, color);
                break;
            }
            case '>':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 3, color);
                break;
            }
            case '@':{
                vga.PutPixel(x + 0, y + 2, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 0, y + 3, color);
                vga.PutPixel(x + 0, y + 4, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 0, y + 5, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 0, y + 6, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case '#':{
                vga.PutPixel(x + 0, y + 1, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 0, y + 2, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 0, y + 3, color);
                vga.PutPixel(x + 3, y + 3, color);
                vga.PutPixel(x + 0, y + 4, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 0, y + 5, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 0, y + 6, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case '$':{
                vga.PutPixel(x + 2, y + 0, color);
                vga.PutPixel(x + 0, y + 1, color);
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 3, y + 1, color);
                vga.PutPixel(x + 0, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 0, y + 5, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case '%':{
                vga.PutPixel(x + 0, y + 1, color);
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 0, y + 2, color);
                vga.PutPixel(x + 3, y + 2, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 0, y + 5, color);
                vga.PutPixel(x + 3, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case '^':{
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 3, y + 2, color);
                break;
            }
            case '(':{
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 1, y + 2, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 1, y + 4, color);
                vga.PutPixel(x + 1, y + 5, color);
                vga.PutPixel(x + 2, y + 6, color);
                break;
            }
            case ')':{
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 1, y + 6, color);
                break;
            }
            case '_':{
                vga.PutPixel(x + 0, y + 6, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            case '&':{
                vga.PutPixel(x + 0, y + 1, color);
                vga.PutPixel(x + 1, y + 1, color);
                vga.PutPixel(x + 2, y + 1, color);
                vga.PutPixel(x + 0, y + 2, color);
                vga.PutPixel(x + 2, y + 2, color);
                vga.PutPixel(x + 0, y + 3, color);
                vga.PutPixel(x + 1, y + 3, color);
                vga.PutPixel(x + 2, y + 3, color);
                vga.PutPixel(x + 0, y + 4, color);
                vga.PutPixel(x + 2, y + 4, color);
                vga.PutPixel(x + 3, y + 4, color);
                vga.PutPixel(x + 0, y + 5, color);
                vga.PutPixel(x + 2, y + 5, color);
                vga.PutPixel(x + 0, y + 6, color);
                vga.PutPixel(x + 1, y + 6, color);
                vga.PutPixel(x + 2, y + 6, color);
                vga.PutPixel(x + 3, y + 6, color);
                break;
            }
            default:{
                drawChar(x, y, 'x', color);
            }
        }
    }
}

namespace common{

    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

    void print(string str, int x, int y){
        if (y < 5){
            y = 5;
        }

        for(int i = 0; str[i] != '\0'; ++i) {
            switch(str[i]){
                case '\n':
                    x = 0;
                    y++;
                    break;
                case '\b':
                    if (x > 0){
                        x--;
                        VideoMemory[80*y+x] = (VideoMemory[80*y+x] & colorDef) | '\0';
                        break;
                    }
                    else if (x == 0 && y > 5){
                        y--;
                        x = 79;
                        VideoMemory[80*y+x] = (VideoMemory[80*y+x] & colorDef) | '\0';
                        break;
                    }
                    break;
                default:
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & colorDef) | str[i];
                    x++;
                    break;
            }
            
            if (x >= 80){
                x = 0;
                y++;
            }
        }
    }

    void printChar(char str, int x, int y){
        if (y < 5){
            y = 5;
        }
        switch(str){
            case '\n':
                x = 0;
                y++;
                break;
            case '\b':
                if (x > 0){
                    x--;
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & colorDef) | '\0';
                    break;
                }
                else if (x == 0 && y > 5){
                    y--;
                    x = 79;
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & colorDef) | '\0';
                    break;
                }
                break;
            default:
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & colorDef) | str;
                x++;
                break;
        }
            
            if (x >= 80){
                x = 0;
                y++;
            }
    }

    bool contains(string str, char c){
        for(int i = 0; str[i] != '\0'; ++i) {
            if (str[i] == c){
                return true;
            }
        }
        return false;
    }

    bool equals(string arr1, string arr2){
        for(int i = 0; arr1[i] != '\0'; ++i) {
            if (arr1[i] != arr2[i]){
                return false;
            }
        }
        for(int i = 0; arr2[i] != '\0'; ++i) {
            if (arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }

    void setHeader(string str, bool ex){
        for (int i = 0; i < 5; ++i){
            if (i != 1 && i != 3){
                for (int j = 0; j < 80; j++){
                    VideoMemory[80*i+j] = (VideoMemory[80*i+j] & colorDef) | '-';
                }
            }
            else if (i != 3){
                int length = 0;
                for(int j = 0; str[j] != '\0'; ++j) {
                    VideoMemory[80*i+j] = (VideoMemory[80*i+j] & colorDef) | str[j];
                    length++;
                }
                for (int j = length; j < 80; ++j){
                    VideoMemory[80*i+j] = (VideoMemory[80*i+j] & colorDef) | '\0';
                }
            }
        }
        if (ex){
            VideoMemory[155] = (VideoMemory[155] & colorRed) | 'e';
            VideoMemory[156] = (VideoMemory[156] & colorRed) | 'x';
            VideoMemory[157] = (VideoMemory[157] & colorRed) | 'i';
            VideoMemory[158] = (VideoMemory[158] & colorRed) | 't';
        }
    }

    int length(string str){
        int i = 0;
        for(int j = 0; str[j] != '\0'; ++j) {
            i++;
        }
        return i;
    }

    string appendChar(string main, char bonus){
        int len = length(main) + 1;
        char function[len + 1];
        for (int i = 0; i < len; ++i){
            if (i != len - 1){
                function[i] = main[i];
            }
            else {
                function[i] = bonus;
            }
        }
        function[len] = '\0';
        main = function;
        return main;
    }

    int power(int num, int pow){
        int val = 1;
        bool neg = false;
        if (pow < 0){
            pow = -pow;
            neg = true;
        }
        for (int i = 0; i < pow; ++i){
            val = val * num;
        }
        if (neg){
            val = 1 / val;
        }
        return val;
    }

    int stringToInt(string str){
        char numChars[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int len = length(str);
        int sum = 0;
        for (int i = len - 1; i >= 0; --i){
            if (!contains(numChars, str[i])){
                return 0;
            }
            int curInt = str[i] - '0';
            sum = sum + power(10, len - i - 1) * curInt;
        }
        return sum;
    }

    int numPlaces(int n){
        if (n < 0) return numPlaces (-n);
        if (n < 10) return 1;
        return 1 + numPlaces (n / 10);
    }

    string intToString(int val, string str){
        int bonus = 0;
        if (val < 0){
            val = -val;
            bonus = 1;
        }
        int np = numPlaces(val);
        char ret[np + bonus];
        for (int i = 1; i <= np; i++){
            int cur = (val % power(10, i));
            val = val - cur;
            cur = cur / power(10, i - 1);
            ret[np - i + bonus] = cur + '0';
        }
        ret[np + bonus] = '\0';
        if (bonus == 1){
            ret[0] = '-';
        }
        str = ret;
        return str;
    }

    string mergeString(string main, string bonus){
        int maxLength = length(main) + length(bonus);
        char function[maxLength];
        for (int i = 0; i < length(main); i++){
            function[i] = main[i];
        }
        for (int i = 0; i < length(bonus); i++){
            function[i + length(main)] = bonus[i];
        }
        function[maxLength] = '\0';
        main = function;
        return main;
    }

    string replace(string str, char a, char b){
        int len = length(str);
        for(int i = 0; i < len; ++i) {
            if (str[i] == a){
                str[i] = b;
            } 
        }
        return str;
    }

    void clear(){
        static uint8_t x=0,y=5;
        for (y = 5; y < 25; y++){
            for(x = 0; x < 80; x++){
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & colorDef) | '\0';
            }
        }
    }

    void clearLine(int row, int start, int end){
        if (start > 80){start = 80;}
        if (start > end){start = end;}
        for(int x = start; x < end; x++){
            VideoMemory[80*row+x] = (VideoMemory[80*row+x] & colorDef) | '\0';
        }
    }

    int count(string data, char symbol){
        int num = 0;
        for (int i = 0; data[i] != '\0'; i++){
            if (data[i] == symbol){
                num++;
            }
        }
        return num;
    }

    string substring(string base, int begin, int until){
        char retur[until - begin + 1];
        int j = 0;
        for (int i = begin; i < until; ++i){
            retur[j] = base[i];
            j++;
        }
        base = retur;
        base[length(base)] = '\0';
        return base;
    }

    string clearEdge(string def, char del){
        if (def[0] == del || def[length(def) - 1] == del){
            if (def[0] == del){
                int len = length(def);
                for (int i = 0; i < len; ++i){
                    if (i < len - 1){
                        def[i] = def[i + 1];
                    }
                    else{
                        def[i] = '\0';
                    }
                }
            }
            else if (def[length(def) - 1] == del){
                def[length(def) - 1] = '\0';
            }
            clearEdge(def, del);
        }
        else{
            return def;
        }
    }

    string split(string def, char del, int which){
        def = clearEdge(def, del);
        int count = 0;
        int lastChar = 0;
        for (int i = 0; def[i] != '\0'; ++i){
            if (def[i] == del){
                if (count >= which){
                    return substring(def, lastChar, i);
                }
                else{
                    count++;
                    lastChar = i + 1;
                }
            }
        }
        return "";
    }
    
    int indexOf(string str, char del){
        for (int i = 0; str[i] != '\0'; ++i){
            if (str[i] == del){
                return i;
            }
        }
    }
    
    int secIndexOf(string str, char del, int place){
        int count = -1;
        for (int i = 0; str[i] != '\0'; ++i){
            if (str[i] == del){
                count++;
                if (count == place){
                    return i;
                }
            }
        }
    }
}



