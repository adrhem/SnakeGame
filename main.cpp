//Adrián M.
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <vector>
#define UP               72
#define LEFT             75
#define RIGHT            77
#define DOWN             80
#define ESC              27
#define SELECT           8
#define ENTER            13
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
using namespace std;

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
vector<Scores> high_scores;

//Functions
int gotoxy(SHORT x, SHORT y);
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
    srand(time(NULL));
    current_difficulty = MEDIUM;
    loadScores();
    do{
        selectOption();
        clearSnake();
        system("cls");
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

            Sleep(speed - current_difficulty);
        }
        if(key!=ESC)
            cin.get();
        saveNewScore();
    }while(key!=ESC);
    saveScores();
    return 0;
}

int gotoxy(SHORT x, SHORT y){
	COORD coord;
	HANDLE h_stdout;

	coord.X = x;
	coord.Y = y;

	if ((h_stdout = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE)
		return 0;

	if (SetConsoleCursorPosition(h_stdout, coord) == 0)
		return 0;

	return 1;
}


void intro(){
    system("cls");
    cout << "________________________________________________________________________________" << endl;
    cout << "                                                              -Snake Game- v2.0" << endl;
    cout << "                    _    _" << endl;
    cout << "                 ,-(|)--(|)-." << endl;
    cout << "                 \\_   ..   _/" << endl;
    cout << "                   \\______/" << endl;
    cout << "                     V  V                                  ____" << endl;
    cout << "                    `.^^`.                               /^,--`" << endl;
    cout << "                     \\^^^\\                             (^^\\" << endl;
    cout << "                     |^^^|                  _,-._       \\^^\\" << endl;
    cout << "                    (^^^^\\      __      _,-'^^^^^`.    _,'^^)" << endl;
    cout << "                     \\^^^^`._,-'^^`-._.'^^^^__^^^^ `--'^^^_/" << endl;
    cout << "                      \\^^^^^ ^^^_^^^^^^^_,-'  `.^^^^^^^^_/ " << endl;
    cout << "                       `.____,-' `-.__.'        `-.___.'   " << endl << endl << endl;
    cout << "                                 Start" << endl;
    cout << "                                 Difficulty" << endl;
    cout << "                                 Scores" << endl;
    cout << "                                 Credits" << endl;
    cout << "                                 Exit" << endl << endl;
    cout << "________________________________________________________________________________";
}

void selectOption(){
    int option;
    bool exit;
    do{
        intro();
        showDifficulty();
        option=1;
        exit = false;
        gotoxy(32,17); cout << "-";
        do
            if(kbhit()){
                gotoxy(32,17); cout << " ";
                gotoxy(32,18); cout << " ";
                gotoxy(32,19); cout << " ";
                gotoxy(32,20); cout << " ";
                gotoxy(32,21); cout << " ";
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
                        cout << "-";
                    break;
                    case UP:
                        if(option>1)
                            option--;
                        else
                            option=5;
                        gotoxy(32,16+option);
                        cout << "-";
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
    system("cls");

    cout << endl << endl << endl << endl;
    cout << "                               Select Difficulty:" << endl;
    cout << "                                Easy" << endl;
    cout << "                                Medium" << endl;
    cout << "                                Hard" << endl;
    cout << "                                Asiatic (not recommended)" << endl;

    int option;
    bool exit;

    option=1;
    exit = false;
    gotoxy(30,5); cout << "-";
    do
        if(kbhit()){
            gotoxy(30,5); cout << " ";
            gotoxy(30,6); cout << " ";
            gotoxy(30,7); cout << " ";
            gotoxy(30,8); cout << " ";
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
                    cout << "-";
                break;
                case UP:
                    if(option>1)
                        option--;
                    else
                        option=4;
                    gotoxy(30,4+option);
                    cout << "-";
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

    gotoxy(60,24);cout << "Difficulty: " << difficulties[current_difficulty];
}

void showCredits(){
    system("cls");
    gotoxy(45,21); cout << "Made by: Adri\240n M\202ndez";

    cin.get();
}

void drawFrame(){
    int i;

    for(i=LIMIT_MEN_X;i<LIMIT_SUP_X;i++){
        gotoxy(i,3); cout << (char)205;
        gotoxy(i,23); cout << (char)205;
    }

    for(i=LIMIT_MEN_Y;i<LIMIT_SUP_Y;i++){
        gotoxy(2,i); cout << (char)186;
        gotoxy(77,i); cout << (char)186;
    }

    gotoxy(2,3); cout << (char)201;
    gotoxy(2,23); cout << (char)200;
    gotoxy(77,3); cout << (char)187;
    gotoxy(77,23); cout << (char)188;
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
    cout << " ";
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    for(i=1;i<size_snake;i++){
        gotoxy(body[i][0],body[i][1]);
        cout << (char)254;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);cout << (char)219;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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
        Beep(1000,100);
        return true;
    }
    else
        return false;
}

void putScore(){
    gotoxy(0,0);
    cout << "Score: " << score;
}

bool gameOver(){
    int i;

    if(x == LIMIT_MEN_X || x == LIMIT_SUP_X || y == LIMIT_MEN_Y || y == LIMIT_SUP_Y){
        gotoxy(35,10);
        cout << "Game Over!" << endl;
        return true;
    }

    for(i=size_snake-1;i>0;i--)
        if(body[i][0] == x && body[i][1] == y){
            gotoxy(35,10);
            cout << "Game Over!" << endl;
            return true;
        }
    return false;
}


void loadScores(){
    int i;
    ifstream load("Scores.txt");
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
    system("cls");
    int i, pos=1;
    gotoxy(0,0);cout << "________________________________________________________________________________";
    gotoxy(32,pos-1);cout << "High Scores";
    i = 0;
    while((unsigned)i<MAX_SCORES){
        i++;
        pos++;
        gotoxy(23,pos);cout << i << ". " << high_scores[i-1].name ;
        gotoxy(47,pos);cout << high_scores[i-1].high_score;


    }

    cin.get();
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
        gotoxy(20,20);cout << "New high score!";
        gotoxy(20,21);cout << "Input your name: ";
                      cin.getline(high_scores[i].name,NAME_SIZE);
        high_scores[i].high_score=score;
    }

}

void saveScores(){
    int i;
    ofstream save("Scores.txt");
    for(i=0;i<MAX_SCORES;i++)
        save.write((char*)&high_scores[i],sizeof(Scores));
}
