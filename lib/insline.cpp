#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  clrscr();
  cout << "Este texto terá uma linha em branco inserida" << endl;
  cout << "apos esta segunda linha e tera tres linhas." << endl;
  gotoxy(1,3);
  getch();  
  gotoxy(1,2); 
  insline();
  gotoxy(1,4); 
  getch();
  return 0;
}
