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

	void drawChar(int x, int y, char ch, string mode){
		if (common::equals(mode, "dark")){
			switch (ch){
				//letters
				case 'a':{drawImage(x, y, "nnnxnknxnnnxnknxnkn"); break;}
				case 'b':{drawImage(x, y, "nnnxnknxnnnnxnkknxnnnn"); break;}
				case 'c':{drawImage(x, y, "nnnxnxnxnxnnn"); break;}
				case 'd':{drawImage(x, y, "nnxnknxnknxnknxnn"); break;}
				case 'e':{drawImage(x, y, "nnnxnxnnnxnxnnn"); break;}
				case 'f':{drawImage(x, y, "nnnxnxnnnxnxn"); break;}
				case 'g':{drawImage(x, y, "nnnnxnxnknnxnkknxnnnn"); break;}
				case 'h':{drawImage(x, y, "nkknxnkknxnnnnxnkknxnkkn"); break;}
				case 'i':{drawImage(x, y, "kknxkknxkknxkknxkkn"); break;}
				case 'j':{drawImage(x, y, "kknxkknxkknxnknxnnn"); break;}
				case 'k':{drawImage(x, y, "nknxnknxnnxnknxnkn"); break;}
				case 'l':{drawImage(x, y, "nxnxnxnxnnn"); break;}
				case 'm':{drawImage(x, y, "nkkknxnnknnxnknknxnkkknxnkkkn"); break;}
				case 'n':{drawImage(x, y, "nkknxnnknxnknnxnkknxnkkn"); break;}
				case 'o':{drawImage(x, y, "nnnnxnkknxnkknxnkknxnnnn"); break;}
				case 'p':{drawImage(x, y, "nnnxnknxnnnxnxn"); break;}
				case 'q':{drawImage(x, y, "nnnxnknxnknxnknxnnnn"); break;}
				case 'r':{drawImage(x, y, "nnnxnknxnnxnknxnkn"); break;}
				case 's':{drawImage(x, y, "nnnxnxnnnxkknxnnn"); break;}
				case 't':{drawImage(x, y, "nnnxknxknxknxkn"); break;}
				case 'u':{drawImage(x, y, "nknxnknxnknxnknxnnn"); break;}
				case 'v':{drawImage(x, y, "nknxnknxnknxnknxkn"); break;}
				case 'w':{drawImage(x, y, "nknknxnknknxnknknxnknknxnnnnn"); break;}
				case 'x':{drawImage(x, y, "nknxnknxknxnknxnkn"); break;}
				case 'y':{drawImage(x, y, "nknxnknxknxknxkn"); break;}
				case 'z':{drawImage(x, y, "nnnxkknxknxnxnnn"); break;}

				//numbers
				case '0':{drawImage(x, y, "nnnxnknxnknxnknxnnn"); break;}
				case '1':{drawImage(x, y, "knnxkknxkknxkknxkkn"); break;}
				case '2':{drawImage(x, y, "nnnxkknxnnnxnxnnn"); break;}
				case '3':{drawImage(x, y, "nnnxkknxnnnxkknxnnn"); break;}
				case '4':{drawImage(x, y, "nknxnknxnnnxkknxkkn"); break;}
				case '5':{drawImage(x, y, "nnnxnxnnnxkknxnnn"); break;}
				case '6':{drawImage(x, y, "nxnxnnnxnknxnnn"); break;}
				case '7':{drawImage(x, y, "nnnxkknxknnxkknxkkn"); break;}
				case '8':{drawImage(x, y, "nnnxnknxnnnxnknxnnn"); break;}
				case '9':{drawImage(x, y, "nnnxnknxnnnxkknxkkn"); break;}

				//symbols
				case '.':{drawImage(x, y, "xxxxkkn"); break;}
				case ',':{drawImage(x, y, "xxxkknxkkn"); break;}
				case '!':{drawImage(x, y, "kknxkknxkknxxkkn"); break;}
				case '?':{drawImage(x, y, "nnnxkknxknnxxkn"); break;}
				case '-':{drawImage(x, y, "xxnnn"); break;}
				case '+':{drawImage(x, y, "xknkxnnnxkn"); break;}
				case '=':{drawImage(x, y, "xnnnxxnnn"); break;}
				case '*':{drawImage(x, y, "xnknxknxnkn"); break;}
				case '\\':{drawImage(x, y, "knxknxknnxkknxkkn"); break;}
				case '|':{drawImage(x, y, "kknxkknxkknxkknxkkn"); break;}
				case '[':{drawImage(x, y, "knnxknxknxknxknn"); break;}
				case ']':{drawImage(x, y, "knnxkknxkknxkknxknn"); break;}
				case '{':{drawImage(x, y, "knnxknxnxknxknn"); break;}
				case '}':{drawImage(x, y, "nnxknxkknxknxnn"); break;}
				case '\'':{drawImage(x, y, "kknxkkn"); break;}
				case '\"':{drawImage(x, y, "nknxnkn"); break;}
				case ';':{drawImage(x, y, "kknxxkknxkkn"); break;}
				case ':':{drawImage(x, y, "xkknxxkkn"); break;}
				case '<':{drawImage(x, y, "kknxknxnxknxkkn"); break;}
				case '>':{drawImage(x, y, "nxknxkknxknxn"); break;}
				case '@':{drawImage(x, y, "knnnnxnkkknxnknnnxnknknxnknn"); break;}
				case '#':{drawImage(x, y, "knknxnnnnnxknknxnnnnnxknkn"); break;}
				case '$':{drawImage(x, y, "knxknnxknxnnxkn"); break;}
				case '%':{drawImage(x, y, "nknxkknxknnxknxknkn"); break;}
				case '^':{drawImage(x, y, "knxnkn"); break;}
				case '&':{drawImage(x, y, "nnnxnknxknnnxnknxnnn"); break;}
				case '(':{drawImage(x, y, "kknxknxknxknxkkn"); break;}
				case ')':{drawImage(x, y, "knxkknxkknxkknxkn"); break;}
				case '/':{drawImage(x, y, "kknxkknxknnxknxkn"); break;}
				case '_':{drawImage(x, y, "xxxxnnnn"); break;}

				//default case (no character found to draw)
				default:{
		            drawChar(x, y, 'x', mode);
					break;
		        }
			}
		}
		else if (common::equals(mode, "light")){
			switch (ch){
				//letters
				case 'a':{drawImage(x, y, "wwwxwkwxwwwxwkwxwkw"); break;}
				case 'b':{drawImage(x, y, "wwwxwkwxwwwwxwkkwxwwww"); break;}
				case 'c':{drawImage(x, y, "wwwxwxwxwxwww"); break;}
				case 'd':{drawImage(x, y, "wwxwkwxwkwxwkwxww"); break;}
				case 'e':{drawImage(x, y, "wwwxwxwwwxwxwww"); break;}
				case 'f':{drawImage(x, y, "wwwxwxwwwxwxw"); break;}
				case 'g':{drawImage(x, y, "wwwwxwxwkwwxwkkwxwwww"); break;}
				case 'h':{drawImage(x, y, "wkkwxwkkwxwwwwxwkkwxwkkw"); break;}
				case 'i':{drawImage(x, y, "kkwxkkwxkkwxkkwxkkw"); break;}
				case 'j':{drawImage(x, y, "kkwxkkwxkkwxwkwxwww"); break;}
				case 'k':{drawImage(x, y, "wkwxwkwxwwxwkwxwkw"); break;}
				case 'l':{drawImage(x, y, "wxwxwxwxwww"); break;}
				case 'm':{drawImage(x, y, "wkkkwxwwkwwxwkwkwxwkkkwxwkkkw"); break;}
				case 'n':{drawImage(x, y, "wkkwxwwkwxwkwwxwkkwxwkkw"); break;}
				case 'o':{drawImage(x, y, "wwwwxwkkwxwkkwxwkkwxwwww"); break;}
				case 'p':{drawImage(x, y, "wwwxwkwxwwwxwxw"); break;}
				case 'q':{drawImage(x, y, "wwwxwkwxwkwxwkwxwwww"); break;}
				case 'r':{drawImage(x, y, "wwwxwkwxwwxwkwxwkw"); break;}
				case 's':{drawImage(x, y, "wwwxwxwwwxkkwxwww"); break;}
				case 't':{drawImage(x, y, "wwwxkwxkwxkwxkw"); break;}
				case 'u':{drawImage(x, y, "wkwxwkwxwkwxwkwxwww"); break;}
				case 'v':{drawImage(x, y, "wkwxwkwxwkwxwkwxkw"); break;}
				case 'w':{drawImage(x, y, "wkwkwxwkwkwxwkwkwxwkwkwxwwwww"); break;}
				case 'x':{drawImage(x, y, "wkwxwkwxkwxwkwxwkw"); break;}
				case 'y':{drawImage(x, y, "wkwxwkwxkwxkwxkw"); break;}
				case 'z':{drawImage(x, y, "wwwxkkwxkwxwxwww"); break;}

				//numbers
				case '0':{drawImage(x, y, "wwwxwkwxwkwxwkwxwww"); break;}
				case '1':{drawImage(x, y, "kwwxkkwxkkwxkkwxkkw"); break;}
				case '2':{drawImage(x, y, "wwwxkkwxwwwxwxwww"); break;}
				case '3':{drawImage(x, y, "wwwxkkwxwwwxkkwxwww"); break;}
				case '4':{drawImage(x, y, "wkwxwkwxwwwxkkwxkkw"); break;}
				case '5':{drawImage(x, y, "wwwxwxwwwxkkwxwww"); break;}
				case '6':{drawImage(x, y, "wxwxwwwxwkwxwww"); break;}
				case '7':{drawImage(x, y, "wwwxkkwxkwwxkkwxkkw"); break;}
				case '8':{drawImage(x, y, "wwwxwkwxwwwxwkwxwww"); break;}
				case '9':{drawImage(x, y, "wwwxwkwxwwwxkkwxkkw"); break;}

				//symbols
				case '.':{drawImage(x, y, "xxxxkkw"); break;}
				case ',':{drawImage(x, y, "xxxkkwxkkw"); break;}
				case '!':{drawImage(x, y, "kkwxkkwxkkwxxkkw"); break;}
				case '?':{drawImage(x, y, "wwwxkkwxkwwxxkw"); break;}
				case '-':{drawImage(x, y, "xxwww"); break;}
				case '+':{drawImage(x, y, "xkwkxwwwxkw"); break;}
				case '=':{drawImage(x, y, "xwwwxxwww"); break;}
				case '*':{drawImage(x, y, "xwkwxkwxwkw"); break;}
				case '\\':{drawImage(x, y, "kwxkwxkwwxkkwxkkw"); break;}
				case '|':{drawImage(x, y, "kkwxkkwxkkwxkkwxkkw"); break;}
				case '[':{drawImage(x, y, "kwwxkwxkwxkwxkww"); break;}
				case ']':{drawImage(x, y, "kwwxkkwxkkwxkkwxkww"); break;}
				case '{':{drawImage(x, y, "kwwxkwxwxkwxkww"); break;}
				case '}':{drawImage(x, y, "wwxkwxkkwxkwxww"); break;}
				case '\'':{drawImage(x, y, "kkwxkkw"); break;}
				case '\"':{drawImage(x, y, "wkwxwkw"); break;}
				case ';':{drawImage(x, y, "kkwxxkkwxkkw"); break;}
				case ':':{drawImage(x, y, "xkkwxxkkw"); break;}
				case '<':{drawImage(x, y, "kkwxkwxwxkwxkkw"); break;}
				case '>':{drawImage(x, y, "wxkwxkkwxkwxw"); break;}
				case '@':{drawImage(x, y, "kwwwwxwkkkwxwkwwwxwkwkwxwkww"); break;}
				case '#':{drawImage(x, y, "kwkwxwwwwwxkwkwxwwwwwxkwkw"); break;}
				case '$':{drawImage(x, y, "kwxkwwxkwxwwxkw"); break;}
				case '%':{drawImage(x, y, "wkwxkkwxkwwxkwxkwkw"); break;}
				case '^':{drawImage(x, y, "kwxwkw"); break;}
				case '&':{drawImage(x, y, "wwwxwkwxkwwwxwkwxwww"); break;}
				case '(':{drawImage(x, y, "kkwxkwxkwxkwxkkw"); break;}
				case ')':{drawImage(x, y, "kwxkkwxkkwxkkwxkw"); break;}
				case '/':{drawImage(x, y, "kkwxkkwxkwwxkwxkw"); break;}
				case '_':{drawImage(x, y, "xxxxwwww"); break;}

				//default case (no character found to draw)
				default:{
		            drawChar(x, y, 'x', mode);
					break;
		        }
			}
		}
	}    

    void drawString(int x, int y, string str, string mode){
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
                    drawChar(place, y, str[i], mode);
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



