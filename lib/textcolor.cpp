#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  short I;
  clrscr();
  for (I = 1; I <= 15; ++I)
    {
      textcolor(I);
      cout << "Texto" << endl;
    }
  normvideo();
  cout << "Texto normal" << endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}

