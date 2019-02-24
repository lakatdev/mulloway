#ifndef FUNCTIONS_H
#define FUNCTIONS_H

    //string formatting
    bool equals(string arr1, string arr2);
    string replace(string str, char a, char b);
    int length(string str);
    string mergeString(string main, string bonus);
    string appendChar(string main, char bonus);
    int stringToInt(string str);
    string intToString(int val, string str);
    bool contains(string str, char c);

    //maths
    int power(int num, int pow);
    int numPlaces(int n);

    //system functions
    void print(string str, int x, int y);
    void setHeader(string str, bool ex);    
    void clear();
    void printChar(char str, int x, int y);
    void printCharCol(char str, int x, int y, int col);
    void printCol(string str, int x, int y, int col);

    //values
    const int colorDef = 0xFF00;
    const int colorBlack = 0x0000;
    const int colorBlue = 0x1100;
    const int colorGreen = 0x2200;
    const int colorCyan = 0x3300;
    const int colorRed = 0x4400;
    const int colorPurple = 0x5500;
    const int colorOrange = 0x6600;

#endif
