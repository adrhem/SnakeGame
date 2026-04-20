#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  char MEMORIA[16];
  char *NOME;
  *MEMORIA = 14;
  clrscr();
  cout << "Informe seu nome: ";
  NOME = cgets(MEMORIA);
  cout << endl << endl;
  cout << "Nome fornecido ..............: " << NOME;
  cout << endl;
  cout << "Total maximo de caracteres ..: " << (int)MEMORIA[0];
  cout << endl;
  cout << "Total caracteres lidos ......: " << (int)MEMORIA[1];
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
