#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  clrscr();
  gotoxy(1,5);
  highvideo();
  cout << "Texto escrito com efeito de maior luminosidade.";
  gotoxy(1,7);
  lowvideo();
  cout << "Texto escrito sem efeito de maior luminosidade.";
  gotoxy(1,9);
  normvideo();
  cout << "Texto escrito com efeito de luminosidade normal." << endl;
  cout << endl;
  cout << "Tecle <Enter> para encerrar... ";
  cin.get();
  return 0;
}
