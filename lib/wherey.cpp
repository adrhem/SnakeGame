#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  clrscr();
  gotoxy(26,12);
  cout << "Posicao atual Y (linha): " << wherey() << endl;
  getch();
  return 0;
}
