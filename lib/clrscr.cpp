#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  clrscr();
  cout << "Mensagem 1." <<  endl;
  cout << endl;
  cout << "Tecle <Enter> para continuar... ";
  cin.get();
  clrscr();
  cout << "Mensagem 2." <<  endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
