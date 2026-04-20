#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  clrscr();
  cout << "Mensagem 1." <<  endl;
  delay(3000); // 3 segundos de espera
  cout << "Mensagem 2." <<  endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
