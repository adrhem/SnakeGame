#include <iostream>
#include <cstring>
#include "conio_am.h"
using namespace std;

int main(void)
{
  char SENHA[9];
  clrscr();
  strcpy(SENHA, getpass("Entre senha: "));
  cout << endl;
  if (strcmp(SENHA, getpass("Confirme senha: ")) != 0)
    {
      cout << endl;
      cout << "Senha incorreta";
      cout << endl;
    }
   else
    {
      cout << endl;
      cout << "Senha OK";
      cout << endl;
    }
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
