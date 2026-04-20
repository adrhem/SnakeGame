#include <iostream>
#include "conio_am.h"
using namespace std;

int main( void )
{
  int I = 0;
  char CARACTERE;
  puts("Entre valor inteiro, caractere alfa para sair:");
  /* leitura de digitos até ler caractere ou EOF */
  while ((CARACTERE = getche()) != EOF && isdigit(CARACTERE))
    I = 10 * I + CARACTERE - 48; /* converte ASCII para valor inteiro */
  /* Se a leitura for caractere, empurra para tras entrada do buffer */
  if (CARACTERE != EOF)
    ungetch(CARACTERE);
  cout << endl;
  cout << "I = " << I << ", proximo caractere do buffer = " << getch() << endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
