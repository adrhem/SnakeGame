#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  short I;
  clrscr();
  textattr(BLUE << 4 | YELLOW);
  cout << "Fundo: Azul     | Texto: Amarelo" << endl;
  textattr(78);
  cout << "Fundo: Vermelho | Texto: Amarelo" << endl;
  textattr(WHITE | MAGENTA << 4);
  cout << "Fundo: Magenta  | Texto: Branco " << endl;
  normvideo();
  for (I = 0; I <= 8; ++I)
    {
      textattr(I + ((I + 1) << 4));
      cout << "Texto" << endl;
    }
  normvideo();
  cout << "Texto normal" << endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}


