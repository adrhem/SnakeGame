#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  long ENTRA;
  char CADEIA[63];
  clrscr();
  cout << "Informe um valor inteiro ..: "; cin >> ENTRA;
  cin.ignore(80, '\n');
  cout << endl;
  ltoav(ENTRA, CADEIA, 2);
  cout << "Valor em binario ..........: " << CADEIA << endl;
  itoav(ENTRA, CADEIA, 62);
  cout << "Valor em base 62 ..........: " << CADEIA << endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
