#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  char CARACTERE;
  clrscr();
  cout << "Entre caractere: ";
  CARACTERE = getch();
  cout << endl;
  cout << "Informou " << CARACTERE << endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
