#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  clrscr();
  cout << "tecle algo: ";
  while(!kbhit());
  cout << "\nFoi acionada a tecla: \'" << (char)getchar() << "\'" << endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
