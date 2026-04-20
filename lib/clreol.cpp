#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  clrscr();
  gotoxy( 1,  1);
  gotoxy( 1,  2);
  cout << "0000000000111111111122222222223" <<  endl;
  cout << "0123456789012345678901234567890" <<  endl;
  cout << endl;
  cout << "Tecle <Enter> para continuar... ";
  cin.get();
  gotoxy( 10, 2);
  clreol();
  cout << endl << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
