#include <iostream>
#include "conio_am.h"
using namespace std;

int main(void)
{
  clrscr();
	cout << "Linha 1." << endl;
	cout << "Linha 2." << endl;
	cout << "Linha 3." << endl;
	cout << "Linha 4." << endl;
	getch();
	gotoxy(1,2);
	cout << "Linha 5." << endl;
  gotoxy(1,5);
	getch();
	gotoxy(1,2);
	delline();
  gotoxy(1,5);
	getch();
	return 0;
}
