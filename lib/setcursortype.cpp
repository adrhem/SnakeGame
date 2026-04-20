#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  clrscr();
  _setcursortype(_SOLIDCURSOR);
  cout << "tecle algo: ";
  while(!kbhit());
  cout << "\nFoi acionada a tecla: \'" << (char)getchar() << "\'" << endl;
  _setcursortype(_NOCURSOR);
  cout << "tecle algo: ";
  while(!kbhit());
  cout << "\nFoi acionada a tecla: \'" << (char)getchar() << "\'" << endl;
  _setcursortype(_NORMALCURSOR);
  cout << "tecle algo: ";
  while(!kbhit());
  cout << "\nFoi acionada a tecla: \'" << (char)getchar() << "\'" << endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
