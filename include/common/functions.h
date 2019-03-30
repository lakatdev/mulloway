#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <drivers/vga.h>

namespace common {
    //string formatting
    bool equals(string arr1, string arr2);
    string replace(string str, char a, char b);
    int length(string str);
    string mergeString(string main, string bonus);
    string appendChar(string main, char bonus);
    int stringToInt(string str);
    string intToString(int val, string str);
    int count(string data, char symbol);
    bool contains(string str, char c);
    string substring(string base, int begin, int until);
    string clearEdge(string def, char del);
    string split(string def, char del, int which);

    //maths
    int power(int num, int pow);
    int numPlaces(int n);

    //system functions
    void print(string str, int x, int y);
    void setHeader(string str, bool ex);    
    void clear();
    void printChar(char str, int x, int y);
    void clearLine(int row, int start, int end);

    //values
    const int colorDef = 0xFF00;
    const int colorBlack = 0x0000;
    const int colorBlue = 0x1100;
    const int colorGreen = 0x2200;
    const int colorCyan = 0x3300;
    const int colorRed = 0x4400;
    const int colorPurple = 0x5500;
    const int colorOrange = 0x6600;

}
namespace graphics{
    void enable(string color);
    void drawScreen(string color);
    void drawPixel(int x, int y, string color);
    void drawRect(int x, int y, int w, int h, string color);
}
#endif
