#include <common/types.h>
#include <common/functions.h>
#include <common/programs.h>

static int runningProgram;

void exit(){
    runningProgram = 0;
    common::setHeader("Mulloway Acorn: 1.16", false);
    common::clear();
    common::print("Installed applications:\n -help (help)\n -grafikon (graf)\n -text editor (edit)", 0,0);
}

//PROGRAMS START

class Prog_help {
    public:
        void main(){
            common::setHeader("Help 6.9", true);
            common::printCol("this is just an example program",30,10, common::colorGreen);
        }

        void inpt(string com, int key = 0){
            common::print("more help lmao",0,10);
        }
};

class Prog_grafikon {
    public:
        void main(){
            common::setHeader("Grafikon 1.0", true);
        }
        void inpt(string com, int key = 0){
            common::print(common::split(com, ';', 0), 0, 5);
        }
};

class Prog_textEditor {
    int pointer = 5;
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
                common::print(com,0,pointer);
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
