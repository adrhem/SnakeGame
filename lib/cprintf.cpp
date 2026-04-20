#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  clrscr();
  int CARACTERES;
  CARACTERES = cprintf("Teste de \tuso \nde cprintf\r\n");
  cout << endl;
  cout << "Caracteres = " << CARACTERES << endl;
  cout << "Considerando a mensagem, \\r, \\n e \\t;" << endl;
  cout << "quando existirem." << endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
