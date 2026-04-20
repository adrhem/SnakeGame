#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  char CADEIA[80];
  cout << "Entre uma cadeia sem espacos: ";
  cscanf("%s", CADEIA);
  cin.ignore(80, '\n');
  cout << endl;
  cout << "Cadeia informada: " << CADEIA << endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
