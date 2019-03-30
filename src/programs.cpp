#include <common/types.h>
#include <common/functions.h>
#include <common/programs.h>

static int runningProgram;

void exit(){
    runningProgram = 0;
    common::setHeader("Mulloway Acorn: 1.17b", false);
    common::clear();
    common::print("Installed applications:\n -help (help)\n -Graphics Mode (graf)\n -text editor (edit)", 0,0);
}

//PROGRAMS START

class Prog_help {
    public:
        void main(){
            common::setHeader("Help 6.9", true);
            common::print("this is just an example program",30,10);
        }

        void inpt(string com, int key = 0){
            common::print("more help lmao",0,10);
        }
};

class Prog_grafikon {
    bool grafMode = false;
    public:
        void main(){
            common::setHeader("Graphics Mode Demo", true);
            common::print("use the command \";graf0\" to enter VGA graphics mode", 0, 5);
            common::print("use the arrow keys to do something while in graphics mode", 0, 6);
            common::print("Warning! You can't exit graphics mode!", 0, 7);
        }
        void inpt(string com, int key = 0){
            if (grafMode){
                switch (key){
                case 1:
                    graphics::drawRect(100, 100, 50, 75, "green");
                    break;
                case 2:
                    graphics::drawRect(200, 50, 69, 20, "red");
                    break;
                case 3:
                    graphics::drawScreen("yellow");
                    break;
                case 4:
                    graphics::drawScreen("magenta");
                    break;
            }
            }
            if (common::equals(com, ";graf0")){
                graphics::enable("blue");
                grafMode = true;
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

Prog_help prog0;
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
                if (common::equals(input, "help"))
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
