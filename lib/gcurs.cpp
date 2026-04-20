#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  int COLUNA, LINHA;
  clrscr();
  gotoxy(20,12);
  gcurs(&COLUNA, &LINHA);
  cout << "Posicao atual X (coluna): " << COLUNA << " Y (linha): " << LINHA << endl;
  getch();
  return 0;
}
