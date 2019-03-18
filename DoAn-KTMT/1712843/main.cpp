<<<<<<< HEAD
#include"Function.h"

void main()
{
	QInt I, E, V;
	/*string a,b;
	for (int i = 0; i < 128; i++)
	{
		a.push_back('0');
	}
	a[126] = '1'; a[125] = '1';
	I.XuatStrBit(a);
	I.setQInt(a);
	b=I.getQInt();
	I.XuatStrBit(b);*/

	/*string c = "-1000";
	cout << I.DecToBin(c) << endl;*/

	/*string a = "123";
	string b = "56";
	a = I.DecToBin(a);
	b = I.DecToBin(b);
	string c = I.CongBit(a, b);
	cout << c << endl;*/

	/*string a = "1000645";
	string b = "5161";
	I.ScanQInt(a, 10);
	E.ScanQInt(b, 10);
	V = I - E;
	cout << V.PrinQInt(10) << endl;*/

	/*string a = "512";
	string b = "6";
	cout << I.CongHaiString(a, b) << endl;*/

	/*string a = "129";
	string b = "-3";
	I.ScanQInt(a, 10);
	E.ScanQInt(b, 10);
	V = I / E;
	cout << V.PrinQInt(10) << endl;*/

	QFloat Z, X, C;
	QInt A;
	A = "-5";
	A = A >> 1;
	cout << A.PrinQInt(10) << endl;
	//b= Z.DecToBin(a);
	/*for (int i = 0; i < 128; i++)
	{
		b.push_back('0');
	}
	b[1] = '1';
	b[15] = '1';
	b[127] = '1';
	cout << Z.BinToDec(b) << endl;*/

	//cout << Z.SoPhay(a) << endl;
	
	system("pause");
=======
#include"Function.h"

void main()
{
	QInt I, E, V;
	/*string a,b;
	for (int i = 0; i < 128; i++)
	{
		a.push_back('0');
	}
	a[126] = '1'; a[125] = '1';
	I.XuatStrBit(a);
	I.setQInt(a);
	b=I.getQInt();
	I.XuatStrBit(b);*/

	/*string c = "-1000";
	cout << I.DecToBin(c) << endl;*/

	/*string a = "123";
	string b = "56";
	a = I.DecToBin(a);
	b = I.DecToBin(b);
	string c = I.CongBit(a, b);
	cout << c << endl;*/

	/*string a = "1000645";
	string b = "5161";
	I.ScanQInt(a, 10);
	E.ScanQInt(b, 10);
	V = I - E;
	cout << V.PrinQInt(10) << endl;*/

	/*string a = "512";
	string b = "6";
	cout << I.CongHaiString(a, b) << endl;*/

	/*string a = "129";
	string b = "-3";
	I.ScanQInt(a, 10);
	E.ScanQInt(b, 10);
	V = I / E;
	cout << V.PrinQInt(10) << endl;*/

	QFloat Z, X, C;
	string a = "0.0";
	string b;
	b= Z.DecToBin(a);
	cout << Z.BinToDec(b) << endl;
	//cout << Z.SoPhay(a) << endl;
	
	system("pause");
>>>>>>> 0ed505653179250343810a0c812d843f4d3daf5e
}