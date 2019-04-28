#include <common/types.h>
#include <common/functions.h>
#include <common/programs.h>
#include <common/images.h>

static int runningProgram;

void exit(){
    runningProgram = 0;
    common::setHeader("Mulloway Acorn: 1.17f", false);
    common::clear();
    common::print("Installed applications:\n -Terminal (term)\n -Graphics Mode (graf)\n -text editor (edit)", 0,0);
}

//PROGRAMS START

class Prog_term {
    public:
        void main(){
            common::setHeader("Keszeg Terminal", true);
            
        }

        void inpt(string com, int key = 0){
    
        }
};

class Prog_grafikon {
    bool grafMode = false;
    int x = 100;
    int y = 100;
    public:
        void main(){
            common::setHeader("Graphics Mode Demo", true);
            common::print("use the command \";graf0\" to enter VGA graphics mode and move a rectangle", 0, 5);
            common::print("use the command \";graf1\" to show graphics demo", 0, 6);
            common::print("use the arrow keys to move the rectangle while in graphics mode", 0, 7);
            common::print("Warning! You can't exit graphics mode!", 0, 8);
        }
        void inpt(string com, int key = 0){
            if (grafMode){
                switch (key){
                case 1:
                    graphics::drawRect(x, y, 30, 30, 1);
                    y -= 10;
                    graphics::drawRect(x, y, 30, 30, 4);
                    break;
                case 2:
                    graphics::drawRect(x, y, 30, 30, 1);
                    y += 10;
                    graphics::drawRect(x, y, 30, 30, 4);
                    break;
                case 3:
                    graphics::drawRect(x, y, 30, 30, 1);
                    x -= 10;
                    graphics::drawRect(x, y, 30, 30, 4);
                    break;
                case 4:
                    graphics::drawRect(x, y, 30, 30, 1);
                    x += 10;
                    graphics::drawRect(x, y, 30, 30, 4);
                    break;
            }
            }
            if (common::equals(com, ";graf0")){
                graphics::enable(1);
                grafMode = true;
                graphics::drawRect(x,y,30,30,4);
            }
            if (common::equals(com, ";graf1")){
                grafMode = false;
                graphics::enable(15);
                graphics::drawImage(0, 0, images::catImage);
                for (int i = 0; i < 64; ++i){
                    graphics::drawRect(171 + i * 2, 0, 2, 10, i);
                }
                graphics::drawString(200, 50, "mulloway 1.7f", 0);
                graphics::drawString(175, 150, "abcdefghijklmnopqrstuv\nwxyz/0123456789.,!?+=-*\n\\|[]{}\'\";:<>@#$%^&()_", 0);
            }
        }
};

class Prog_textEditor {
    int pointer = 5;
    string data[25];
    public:
        void main(){
            common::setHeader("Keszeg editor 0.1 (alpha)", true);
            common::print("<<", 78, pointer);
        }
        void inpt(string com, int key = 0){
            if (key == 1 || key == 2){
                if (key == 1 && pointer > 5){
                    common::clearLine(pointer, 78, 80);
                    pointer--;
                }
                else if (key == 2 && pointer < 24){
                    common::clearLine(pointer, 78, 80);
                    pointer++;
                }
                common::print("<<", 78, pointer);
            }
            else if (com != ""){
                data[pointer - 5] = com;
                common::print(data[pointer - 5],0,pointer);
                if (pointer < 24){
                    common::clearLine(pointer, 78, 80);
                    pointer++;
                }
                common::print("<<", 78, pointer);
            }
        }
};

//PROGRAMS END

Prog_term prog0;
Prog_grafikon prog1;
Prog_textEditor prog2;

void executeProgram(int id){
    common::clear();
    runningProgram = id;
    switch (id){
        case 0:
            exit();
            break;
        case 1:
            prog0.main();
            break;
        case 2:
            prog1.main();
            break;
        case 3:
            prog2.main();
            break;
    }
}

void handleInput(string input){
    if (common::equals(input, "exit")){
        exit();
    }
    else{
        switch(runningProgram){
            case 0:
                if (common::equals(input, "term"))
                    executeProgram(1);
                if (common::equals(input, "graf"))
                    executeProgram(2);
                if (common::equals(input, "edit"))
                    executeProgram(3);
                break;
            case 1:
                prog0.inpt(input);
                break;
            case 2:
                prog1.inpt(input);
                break;
            case 3:
                prog2.inpt(input);
                break;
        }
    }
}

void handleAction(int key){
    int arrow = 0;
    switch(key){
        case 0: //up
            arrow = 1;
            break;
        case 1: //down
            arrow = 2;
            break;
        case 2: //left
            arrow = 3;
            break;  
        case 3: //right
            arrow = 4;
            break;
        case 4:  //exit
            exit();
            break;
        case 5:  //home
            exit();
            break;
    }
    if (arrow != 0){
        switch(runningProgram){
            case 0:
                break;
            case 1:
                prog0.inpt("",arrow);
                break;
            case 2:
                prog1.inpt("",arrow);
                break;
            case 3:
                prog2.inpt("",arrow);
                break;
        }
    }
}
