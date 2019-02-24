#include <common/types.h>
#include <common/functions.h>

void print(string str, int x, int y){
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

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

void printCol(string str, int x, int y, int col){
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

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
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & col) | '\0';
                    break;
                }
                else if (x == 0 && y > 5){
                    y--;
                    x = 79;
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & col) | '\0';
                    break;
                }
                break;
            default:
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & col) | str[i];
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
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

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

void printCharCol(char str, int x, int y, int color){
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

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
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & color) | '\0';
                break;
            }
            else if (x == 0 && y > 5){
                y--;
                x = 79;
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & color) | '\0';
                break;
            }
            break;
        default:
            VideoMemory[80*y+x] = (VideoMemory[80*y+x] & color) | str;
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
	static uint16_t* VideoMemory = (uint16_t*)0xb8000;
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
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;
    static uint8_t x=0,y=5;
    for (y = 5; y < 25; y++){
        for(x = 0; x < 80; x++){
            VideoMemory[80*y+x] = (VideoMemory[80*y+x] & colorDef) | '\0';
        }
    }
}

