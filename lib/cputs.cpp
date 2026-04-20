#include "conio_am.h"
#include <iostream>
using namespace std;

int main(void)
{
  clrscr();
  cputs("Teste de \tuso de cputs 1\n");
  cputs("Teste de uso de cputs 2\r");
  cputs("Teste de uso de cputs 3\n\r");
  cputs("Teste de uso de cputs 4\r\n");
  cputs("Teste de uso de cputs 5\r");
  cputs("Teste de uso \nde cputs 6\n");
  cputs("Teste de uso de cputs 7\r\n");
  cputs("Teste de \nuso de cputs 8\r\n");
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
