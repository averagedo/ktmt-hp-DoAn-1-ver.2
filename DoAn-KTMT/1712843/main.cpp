#include"Function.h"

void main()
{
	QInt I, E, V;
	I.ScanQInt("11", 2);
	E.ScanQInt("010", 2);
	V = I * E;
	cout << V.PrinQInt(10) << endl;
	system("pause");
}