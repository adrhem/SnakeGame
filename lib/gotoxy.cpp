#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  clrscr();
  gotoxy( 3,  5);
  cout << "Linha  3 - Coluna  5" <<  endl;
  gotoxy( 8, 10);
  cout << "Linha  8 - Coluna 10" <<  endl;
  gotoxy(21,  1);
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
