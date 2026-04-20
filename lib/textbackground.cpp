#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  short I, J;
  clrscr();
  textbackground(RED);
  cout << "Texto 1 ";
  textbackground(3);
  cout << "Texto 2 ";
  textbackground(6);
  cout << "Texto 3" << endl;
  normvideo();
  cout << endl;
  for (I = 0; I <= 7; ++I)
  {
    for (J = 1; J <= 80; ++J)
      {
        cout << "X";
      }
    cout << endl;
    textcolor(I + 1);
    textbackground(I);
  }
  normvideo();
  cout << "Texto normal" << endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}

