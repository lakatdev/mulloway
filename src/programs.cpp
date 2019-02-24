#include <common/types.h>
#include <common/functions.h>
#include <common/programs.h>

static int runningProgram;

void exit(){
    runningProgram = 0;
    setHeader("Mulloway Acorn: 1.15", false);
    clear();
    print("Installed applications:\n -help (help)\n -calculator (calc)\n -text editor (edit)", 0,0);
}

//PROGRAMS START

class Prog_help {
    public:
        void main(){
            setHeader("Help 6.9", true);
            printCol("this is just an example program",30,10, colorGreen);
        }

        void inpt(string com, int key = 0){
            print("more help lmao",0,10);
        }
};

class Prog_calculator {
    public:
        void main(){
            setHeader("Calculator 1.0", true);
            print("This is a basic calculator built into the Mulloway System", 0, 5);
            print("THIS VERSION IS NOT FUNCTIONAL!", 0,6);
        }

        void inpt(string com, int key = 0){
            clear();
            string empty;
            print(intToString((stringToInt(com)), empty), 0,7);            
        }
};

class Prog_textEditor {
    int pointer = 5;
    string data;
    public:
        void main(){
            setHeader("Keszeg editor 0.1 (alpha)", true);
            print("<<", 78, pointer);
        }
        void inpt(string com, int key = 0){
            if (key == 1 || key == 2){
                if (key == 1 && pointer > 5){
                    pointer--;
                }
                else if (key == 2 && pointer < 24){
                    pointer++;
                }
                print("<<", 78, pointer);
            }
            else if (com != ""){
                print(com,0,pointer);
                if (pointer < 24)
                    pointer++;
                print("<<", 78, pointer);
            }
        }
};

//PROGRAMS END

Prog_help prog0;
Prog_calculator prog1;
Prog_textEditor prog2;

void executeProgram(int id){
    clear();
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
    if (equals(input, "exit")){
        exit();
    }
    else{
        switch(runningProgram){
            case 0:
                if (equals(input, "help"))
                    executeProgram(1);
                if (equals(input, "calc"))
                    executeProgram(2);
                if (equals(input, "edit"))
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