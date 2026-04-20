#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  char CARACTERE;
  cout << "Entre um caractere ..: ";
  CARACTERE = getch();
  putch(CARACTERE);
  cout << endl;
  cout << "Entre uma cadeia ....: ";
  while (CARACTERE != ENTER) // Use a constante ENTER para validar <Enter>.
    {
      CARACTERE = getch();
      putch(CARACTERE);
    }
  #if defined _WIN32 || defined _WIN64
    cout << endl;
  #endif
  cout << "Entre um texto" << endl;
  cout << "<Enter>    = muda linha" << endl;
  cout << "<Backspace = retrocede sem apagar" << endl;
  cout << "<*>        = finaliza entrada" << endl;
  do
    {
      putch(CARACTERE = getch());
      #if defined _WIN32 || defined _WIN64
        if (CARACTERE == ENTER)
          {
            putch('\n');
          }
      #endif
    }
  while (CARACTERE != '*');
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
