//Adrián HM. <dev.foe555@slmail.me>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "lib/conio_am.h" // https://sourceforge.net/projects/coniohcloneturboccpp/

#define UP               72
#define LEFT             75
#define RIGHT            77
#define DOWN             80
#define ESC              27
#define SELECT           8
#ifndef ENTER
#define ENTER            13
#endif
#define MOVE_UP          1
#define MOVE_DOWN        2
#define MOVE_RIGHT       3
#define MOVE_LEFT        4
#define MAX_SIZE         200
#define LIMIT_MEN_X      2
#define LIMIT_SUP_X      77
#define LIMIT_MEN_Y      3
#define LIMIT_SUP_Y      23
#define INITIAL_X_COORD  4
#define INITIAL_Y_COORD  4
#define INITIAL_SIZE     4
#define START            1
#define DIFFICULTY       2
#define SCORES           3
#define CREDITS          4
#define EXIT             5
#define NAME_SIZE        20
#define MAX_SCORES       5

//Var Types
typedef enum{EASY, MEDIUM, HARD, ASIATIC} Difficulty;
class Scores{
public:
    char name[NAME_SIZE];
    int high_score;
};

//Var definitions
int body[MAX_SIZE][2]; //Where 2 is coord
int n;
int size_snake;
int x, y;
int x_food, y_food;
int direction;
int score;
int speed;
Difficulty current_difficulty;
char key;
std::vector<Scores> high_scores;

//Functions
void intro();
void selectOption();
void changeDifficulty();
void showDifficulty();
void showCredits();
void clearSnake();
void drawFrame();
void eraseBody();
void savePositions();
void drawBody();
void keyPress();
void putFood();
void printFood();
bool hasEaten();
void putScore();
bool gameOver();
void loadScores();
void showScores();
void saveNewScore();
void saveScores();


int main(){
    setvbuf(stdout, NULL, _IONBF, 0); // flush every write immediately
    srand(time(NULL));
    current_difficulty = MEDIUM;
    loadScores();
    do{
        selectOption();
        clearSnake();
        clrscr();
        size_snake = INITIAL_SIZE + current_difficulty;
        n = 1;
        score = 0;
        speed = 70;
        y = INITIAL_Y_COORD;
        x = INITIAL_X_COORD;
        direction = MOVE_RIGHT;
        if(key!=ESC){
            drawFrame();
            putFood();
        }
        while(key!=ESC && !gameOver()){
            putScore();
            eraseBody();
            savePositions();
            drawBody();
            eraseBody();
            putScore();
            printFood();
            if(hasEaten())
                putFood();
            keyPress();
            keyPress();
            switch(direction){
                case MOVE_UP: y--;
                break;
                case MOVE_DOWN: y++;
                break;
                case MOVE_RIGHT: x++;
                break;
                case MOVE_LEFT: x--;
                break;
            }

            delay((speed - current_difficulty));
        }
        if(key!=ESC)
            std::cin.get();
        saveNewScore();
    }while(key!=ESC);
    saveScores();
    return 0;
}


void intro(){
    clrscr();
    std::cout << "________________________________________________________________________________" << std::endl;
    std::cout << "                                                              -Snake Game- v2.0" << std::endl;
    std::cout << "                    _    _" << std::endl;
    std::cout << "                 ,-(|)--(|)-." << std::endl;
    std::cout << "                 \\_   ..   _/" << std::endl;
    std::cout << "                   \\______/" << std::endl;
    std::cout << "                     V  V                                  ____" << std::endl;
    std::cout << "                    `.^^`.                               /^,--`" << std::endl;
    std::cout << "                     \\^^^\\                             (^^\\" << std::endl;
    std::cout << "                     |^^^|                  _,-._       \\^^\\" << std::endl;
    std::cout << "                    (^^^^\\      __      _,-'^^^^^`.    _,'^^)" << std::endl;
    std::cout << "                     \\^^^^`._,-'^^`-._.'^^^^__^^^^ `--'^^^_/" << std::endl;
    std::cout << "                      \\^^^^^ ^^^_^^^^^^^_,-'  `.^^^^^^^^_/ " << std::endl;
    std::cout << "                       `.____,-' `-.__.'        `-.___.'   " << std::endl << std::endl << std::endl;
    std::cout << "                                 Start" << std::endl;
    std::cout << "                                 Difficulty" << std::endl;
    std::cout << "                                 Scores" << std::endl;
    std::cout << "                                 Credits" << std::endl;
    std::cout << "                                 Exit" << std::endl << std::endl;
    std::cout << "________________________________________________________________________________";
}

void selectOption(){
    int option;
    bool exit;
    do{
        intro();
        showDifficulty();
        option=1;
        exit = false;
        gotoxy(32,17); std::cout << "-";
        do
            if(kbhit()){
                gotoxy(32,17); std::cout << " ";
                gotoxy(32,18); std::cout << " ";
                gotoxy(32,19); std::cout << " ";
                gotoxy(32,20); std::cout << " ";
                gotoxy(32,21); std::cout << " ";
                key = getch();
                switch(key){
                    case ESC:
                        exit=true;
                    break;
                    case DOWN:
                    case SELECT:
                        if(option<5)
                            option++;
                        else
                            option=1;
                        gotoxy(32,16+option);
                        std::cout << "-";
                    break;
                    case UP:
                        if(option>1)
                            option--;
                        else
                            option=5;
                        gotoxy(32,16+option);
                        std::cout << "-";
                    break;
                    case ENTER:
                        exit = true;
                    break;
                    default:
                    break;
                }
            }
        while(!exit);

        switch(option){
            case DIFFICULTY:
                changeDifficulty();
            break;
            case SCORES:
                showScores();
            break;
            case CREDITS:
                showCredits();
            break;
            case EXIT:
                key=ESC;
            break;
            default:
            break;
        }
    }while(option!=START&&option!=EXIT);
}

void changeDifficulty(){
    clrscr();

    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "                               Select Difficulty:" << std::endl;
    std::cout << "                                Easy" << std::endl;
    std::cout << "                                Medium" << std::endl;
    std::cout << "                                Hard" << std::endl;
    std::cout << "                                Asiatic (not recommended)" << std::endl;

    int option;
    bool exit;

    option=1;
    exit = false;
    gotoxy(30,5); std::cout << "-";
    do
        if(kbhit()){
            gotoxy(30,5); std::cout << " ";
            gotoxy(30,6); std::cout << " ";
            gotoxy(30,7); std::cout << " ";
            gotoxy(30,8); std::cout << " ";
            key = getch();
            switch(key){
                case ESC:
                    exit=true;
                break;
                case DOWN:
                case SELECT:
                    if(option<4)
                        option++;
                    else
                        option=1;
                    gotoxy(30,4+option);
                    std::cout << "-";
                break;
                case UP:
                    if(option>1)
                        option--;
                    else
                        option=4;
                    gotoxy(30,4+option);
                    std::cout << "-";
                break;
                case ENTER:
                    exit = true;
                break;
                default:
                break;
            }
        }
    while(!exit);
    option-=1;
    switch(option){
        case EASY:
            current_difficulty = EASY;
        break;
        case MEDIUM:
            current_difficulty = MEDIUM;
        break;
        case HARD:
            current_difficulty = HARD;
        break;
        case ASIATIC:
            current_difficulty = ASIATIC;
        break;
        default:
        break;
    }

}

void showDifficulty(){

    const char* difficulties[] = {"Easy","Medium","Hard","Asiatic"};

    gotoxy(60,24);std::cout << "Difficulty: " << difficulties[current_difficulty];
}

void showCredits(){
    clrscr();
    gotoxy(45,21); std::cout << "Made by: Adrián HM <dev.foe555@slmail.me>";

    std::cin.get();
}

void drawFrame(){
    int i;

    for(i=LIMIT_MEN_X;i<LIMIT_SUP_X;i++){
        gotoxy(i,3); std::cout << "═";
        gotoxy(i,23); std::cout << "═";
    }

    for(i=LIMIT_MEN_Y;i<LIMIT_SUP_Y;i++){
        gotoxy(2,i); std::cout << "║";
        gotoxy(77,i); std::cout << "║";
    }

    gotoxy(2,3); std::cout << "╔";
    gotoxy(2,23); std::cout << "╚";
    gotoxy(77,3); std::cout << "╗";
    gotoxy(77,23); std::cout << "╝";
}

void clearSnake(){
    int i;

    for(i=0;i<MAX_SIZE;i++){
        body[i][0]=0;
        body[i][1]=0;
    }
}

void eraseBody(){
    gotoxy(body[n][0],body[n][1]);
    std::cout << " ";
}

void savePositions(){
    body[n][0] = x;
    body[n][1] = y;
    n++;

    if(n == size_snake)
        n = 1;
}

void drawBody(){
    int i;
    textcolor(10);
    for(i=1;i<size_snake;i++){
        gotoxy(body[i][0],body[i][1]);
        std::cout << "■";
    }
    textcolor(7);
}

void keyPress(){
    if(kbhit()){
        key = getch();
        switch(key){
            case UP:
                if(direction != MOVE_DOWN)
                    direction = MOVE_UP;
            break;

            case DOWN:
                if(direction != MOVE_UP)
                    direction = MOVE_DOWN;
            break;

            case RIGHT:
                if(direction != MOVE_LEFT)
                    direction = MOVE_RIGHT;
            break;

            case LEFT:
                if(direction != MOVE_RIGHT)
                    direction = MOVE_LEFT;
            break;

            default:
            break;
        }
    }
}

void putFood(){
    do{
        x_food = rand()%73 + 4;
        y_food = rand()%19 + 4;
    }while(x_food == x && y_food == y);
}

void printFood(){
    int color;
    color = rand()%6+9;
    gotoxy(x_food,y_food);
    textcolor(color);
    std::cout << "●";
    textcolor(7);
}

bool hasEaten(){
    int increment;
    int speed_difficulty;
    if(x_food == x && y_food == y){
        switch(current_difficulty){
            case EASY:
                size_snake+=current_difficulty+2;
                increment = 10;
                speed_difficulty = 55;
            break;
            case MEDIUM:
                size_snake+=current_difficulty+2;
                increment = 15;
                speed_difficulty = 45;
            break;
            case HARD:
                size_snake+=current_difficulty+2;
                increment = 25;
                speed_difficulty = 35;
            break;
            case ASIATIC:
                size_snake+=current_difficulty+2;
                increment = 35;
                speed_difficulty = 25;
            break;
            default:
            break;
        }

        if(score<50){
            score+=increment;
            speed = speed_difficulty - current_difficulty;
        }


        else if(score < 100){
            score +=increment+10;
            speed = speed_difficulty - current_difficulty*2;
        }
        else if(score < 200){
            score +=increment+20;
            speed = speed_difficulty - current_difficulty*3;
        }
        else{
            score += increment+30;
            speed = speed_difficulty - current_difficulty*4;
        }
        #if (defined _WIN32 || defined _WIN64)
        beep(1000,100);
        #else
        std::cout << "\a";
        #endif
        return true;
    }
    else
        return false;
}

void putScore(){
    gotoxy(1,1);
    std::cout << "Score: " << score;
}

bool gameOver(){
    int i;

    if(x == LIMIT_MEN_X || x == LIMIT_SUP_X || y == LIMIT_MEN_Y || y == LIMIT_SUP_Y){
        gotoxy(35,10);
        std::cout << "Game Over!" << std::endl;
        return true;
    }

    for(i=size_snake-1;i>0;i--)
        if(body[i][0] == x && body[i][1] == y){
            gotoxy(35,10);
            std::cout << "Game Over!" << std::endl;
            return true;
        }
    return false;
}


void loadScores(){
    int i;
    std::ifstream load("Scores.txt");
    high_scores.resize(MAX_SCORES);
    if(load.good())
        for(i=0;i<MAX_SCORES;i++)
            load.read((char*)&high_scores[i],sizeof(Scores));

    else
        for(i=0;i<MAX_SCORES;i++){
            high_scores[i].name[0]='\0';
            high_scores[i].high_score=0;
        }


}

void showScores(){
    clrscr();
    int i, pos=1;
    gotoxy(0,0);std::cout << "________________________________________________________________________________";
    gotoxy(32,pos-1);std::cout << "High Scores";
    i = 0;
    while((unsigned)i<MAX_SCORES){
        i++;
        pos++;
        gotoxy(23,pos);std::cout << i << ". " << high_scores[i-1].name ;
        gotoxy(47,pos);std::cout << high_scores[i-1].high_score;


    }

    std::cin.get();
}

void saveNewScore(){
    int i, j;
    bool newHighScore=false;

    for(i=0;i<MAX_SCORES&&!newHighScore;i++)
        if(score>high_scores[i].high_score)
            newHighScore=true;
    i--;

    if(newHighScore){
        j=high_scores.size()-1;
        while(i!=j){
            high_scores[j]=high_scores[j-1];
            j--;
        }
        gotoxy(20,20);std::cout << "New high score!";
        gotoxy(20,21);std::cout << "Input your name: ";
                      std::cin.getline(high_scores[i].name,NAME_SIZE);
        high_scores[i].high_score=score;
    }

}

void saveScores(){
    int i;
    std::ofstream save("Scores.txt");
    for(i=0;i<MAX_SCORES;i++)
        save.write((char*)&high_scores[i],sizeof(Scores));
}
