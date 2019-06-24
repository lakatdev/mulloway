#include <common/types.h>
#include <common/functions.h>
#include <drivers/vga.h>
#include <common/programs.h>

namespace graphics{
    VideoGraphicsArray vga;

    void enable(int color){
        vga.SetMode(320,200,8);
        for(int y = 0; y < 200; y++)
            for(int x = 0; x < 320; x++)
                vga.PutPixel(x, y, color);
    }

    void drawScreen(int color){
        for(int y = 0; y < 200; y++)
                    for(int x = 0; x < 320; x++)
                        vga.PutPixel(x, y, color);
    }

    void drawPixel(int x, int y, int color){
        vga.PutPixel(x, y, color);
    }

    void drawRect(int x, int y, int w, int h, int color){
        for(int x1 = 0; x1 < w; x1++)
                        for(int y1 = 0; y1 < h; y1++)
                            vga.PutPixel(x1 + x, y1 + y, color);
    }
    
    void drawImage(int x, int y, string code){
        int og_x = x;
        string corset = "nbgcrmoldsezhfy\\jtvqipua/0123456789.,!?+=-*|[]{}'\";:<>@#$%^&()_w";
        for (int i = 0; code[i] != '\0'; ++i){
            switch (code[i]){
                case 'x':{
                    x = og_x;
                    y++;
                    break;
                }
                case 'k':{
                    x++;
                    break;
                }
                default:{
                    drawPixel(x, y, common::indexOf(corset, code[i]));
                    x++;
                    break;
                }
            }
        }
    }

	void drawChar(int x, int y, char ch, char color){
		switch (ch){
			//letters
			case 'a':{drawImage(x, y, common::replace("nnnxnknxnnnxnknxnkn", 'n', color)); break;}
			case 'b':{drawImage(x, y, common::replace("nnnxnknxnnnnxnkknxnnnn", 'n', color)); break;}
			case 'c':{drawImage(x, y, common::replace("nnnxnxnxnxnnn", 'n', color)); break;}
			case 'd':{drawImage(x, y, common::replace("nnxnknxnknxnknxnn", 'n', color)); break;}
			case 'e':{drawImage(x, y, common::replace("nnnxnxnnnxnxnnn", 'n', color)); break;}
			case 'f':{drawImage(x, y, common::replace("nnnxnxnnnxnxn", 'n', color)); break;}
			case 'g':{drawImage(x, y, common::replace("nnnnxnxnknnxnkknxnnnn", 'n', color)); break;}
			case 'h':{drawImage(x, y, common::replace("nkknxnkknxnnnnxnkknxnkkn", 'n', color)); break;}
			case 'i':{drawImage(x, y, common::replace("kknxkknxkknxkknxkkn", 'n', color)); break;}
			case 'j':{drawImage(x, y, common::replace("kknxkknxkknxnknxnnn", 'n', color)); break;}
			case 'k':{drawImage(x, y, common::replace("nknxnknxnnxnknxnkn", 'n', color)); break;}
			case 'l':{drawImage(x, y, common::replace("nxnxnxnxnnn", 'n', color)); break;}
			case 'm':{drawImage(x, y, common::replace("nkkknxnnknnxnknknxnkkknxnkkkn", 'n', color)); break;}
			case 'n':{drawImage(x, y, common::replace("nkknxnnknxnknnxnkknxnkkn", 'n', color)); break;}
			case 'o':{drawImage(x, y, common::replace("nnnnxnkknxnkknxnkknxnnnn", 'n', color)); break;}
			case 'p':{drawImage(x, y, common::replace("nnnxnknxnnnxnxn", 'n', color)); break;}
			case 'q':{drawImage(x, y, common::replace("nnnxnknxnknxnknxnnnn", 'n', color)); break;}
			case 'r':{drawImage(x, y, common::replace("nnnxnknxnnxnknxnkn", 'n', color)); break;}
			case 's':{drawImage(x, y, common::replace("nnnxnxnnnxkknxnnn", 'n', color)); break;}
			case 't':{drawImage(x, y, common::replace("nnnxknxknxknxkn", 'n', color)); break;}
			case 'u':{drawImage(x, y, common::replace("nknxnknxnknxnknxnnn", 'n', color)); break;}
			case 'v':{drawImage(x, y, common::replace("nknxnknxnknxnknxkn", 'n', color)); break;}
			case 'w':{drawImage(x, y, common::replace("nknknxnknknxnknknxnknknxnnnnn", 'n', color)); break;}
			case 'x':{drawImage(x, y, common::replace("nknxnknxknxnknxnkn", 'n', color)); break;}
			case 'y':{drawImage(x, y, common::replace("nknxnknxknxknxkn", 'n', color)); break;}
			case 'z':{drawImage(x, y, common::replace("nnnxkknxknxnxnnn", 'n', color)); break;}

			//numbers
			case '0':{drawImage(x, y, common::replace("nnnxnknxnknxnknxnnn", 'n', color)); break;}
			case '1':{drawImage(x, y, common::replace("knnxkknxkknxkknxkkn", 'n', color)); break;}
			case '2':{drawImage(x, y, common::replace("nnnxkknxnnnxnxnnn", 'n', color)); break;}
			case '3':{drawImage(x, y, common::replace("nnnxkknxnnnxkknxnnn", 'n', color)); break;}
			case '4':{drawImage(x, y, common::replace("nknxnknxnnnxkknxkkn", 'n', color)); break;}
			case '5':{drawImage(x, y, common::replace("nnnxnxnnnxkknxnnn", 'n', color)); break;}
			case '6':{drawImage(x, y, common::replace("nxnxnnnxnknxnnn", 'n', color)); break;}
			case '7':{drawImage(x, y, common::replace("nnnxkknxknnxkknxkkn", 'n', color)); break;}
			case '8':{drawImage(x, y, common::replace("nnnxnknxnnnxnknxnnn", 'n', color)); break;}
			case '9':{drawImage(x, y, common::replace("nnnxnknxnnnxkknxkkn", 'n', color)); break;}

			//symbols
			case '.':{drawImage(x, y, common::replace("xxxxkkn", 'n', color)); break;}
			case ',':{drawImage(x, y, common::replace("xxxkknxkkn", 'n', color)); break;}
			case '!':{drawImage(x, y, common::replace("kknxkknxkknxxkkn", 'n', color)); break;}
			case '?':{drawImage(x, y, common::replace("nnnxkknxknnxxkn", 'n', color)); break;}
			case '-':{drawImage(x, y, common::replace("xxnnn", 'n', color)); break;}
			case '+':{drawImage(x, y, common::replace("xknkxnnnxkn", 'n', color)); break;}
			case '=':{drawImage(x, y, common::replace("xnnnxxnnn", 'n', color)); break;}
			case '*':{drawImage(x, y, common::replace("xnknxknxnkn", 'n', color)); break;}
			case '\\':{drawImage(x, y, common::replace("knxknxknnxkknxkkn", 'n', color)); break;}
			case '|':{drawImage(x, y, common::replace("kknxkknxkknxkknxkkn", 'n', color)); break;}
			case '[':{drawImage(x, y, common::replace("knnxknxknxknxknn", 'n', color)); break;}
			case ']':{drawImage(x, y, common::replace("knnxkknxkknxkknxknn", 'n', color)); break;}
			case '{':{drawImage(x, y, common::replace("knnxknxnxknxknn", 'n', color)); break;}
			case '}':{drawImage(x, y, common::replace("nnxknxkknxknxnn", 'n', color)); break;}
			case '\'':{drawImage(x, y, common::replace("kknxkkn", 'n', color)); break;}
			case '\"':{drawImage(x, y, common::replace("nknxnkn", 'n', color)); break;}
			case ';':{drawImage(x, y, common::replace("kknxxkknxkkn", 'n', color)); break;}
			case ':':{drawImage(x, y, common::replace("xkknxxkkn", 'n', color)); break;}
			case '<':{drawImage(x, y, common::replace("kknxknxnxknxkkn", 'n', color)); break;}
			case '>':{drawImage(x, y, common::replace("nxknxkknxknxn", 'n', color)); break;}
			case '@':{drawImage(x, y, common::replace("knnnnxnkkknxnknnnxnknknxnknn", 'n', color)); break;}
			case '#':{drawImage(x, y, common::replace("knknxnnnnnxknknxnnnnnxknkn", 'n', color)); break;}
			case '$':{drawImage(x, y, common::replace("knxknnxknxnnxkn", 'n', color)); break;}
			case '%':{drawImage(x, y, common::replace("nknxkknxknnxknxknkn", 'n', color)); break;}
			case '^':{drawImage(x, y, common::replace("knxnkn", 'n', color)); break;}
			case '&':{drawImage(x, y, common::replace("nnnxnknxknnnxnknxnnn", 'n', color)); break;}
			case '(':{drawImage(x, y, common::replace("kknxknxknxknxkkn", 'n', color)); break;}
			case ')':{drawImage(x, y, common::replace("knxkknxkknxkknxkn", 'n', color)); break;}
			case '/':{drawImage(x, y, common::replace("kknxkknxknnxknxkn", 'n', color)); break;}
			case '_':{drawImage(x, y, common::replace("xxxxnnnn", 'n', color)); break;}

			//default case (no character found to draw)
			default:{
                drawChar(x, y, 'x', color);
				break;
            }
		}
	}    

    void drawString(int x, int y, string str, char color){
        if (x > 314)
            x = 314;
        int place = x;
        for (int i = 0; str[i] != '\0'; ++i){
            if (place > 314){
                place = x;
                y += 6;
            }
            switch (str[i]){
                case ' ':
                    place += 6;
                    break;
                case '\n':
                    y += 6;
                    place = x; 
                    break;
                default:
                    drawChar(place, y, str[i], color);
                    place += 6;
                    break;
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
        str = clearEdge(str, ' ');
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
        def = appendChar(def, del);
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
        return -1;
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
        return -1;
    }
}



