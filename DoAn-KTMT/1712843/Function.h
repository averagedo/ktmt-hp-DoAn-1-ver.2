#include<iostream>
#include<string>

using namespace std;

class QInt
{
private:
	int qInt[4];
public:
	QInt();
	string getQInt();
	void setQInt(string a);
	
	void XuatStrBit(string a);
	

	void ScanQInt(string a, int n);
	string PrinQInt(int n);

	string DecToBin(string a);

	string BinToDec(string a);

	string BinToHex(string a);

	string HvsB(char a);
	string HexToBin(string a);

	QInt operator+(QInt a);
	QInt operator-(QInt a);
	int DemBit(string a);
	QInt operator*(QInt a);
	QInt operator/(QInt a);
	
};


string CongBit(string BitA, string BitB); //ca hai deu co 128 bit;
string BuHai(string a);	//Bieu dien so am
string CongHaiString(string a, string b);	//khong cung kich thuoc, so duog
string Mu(int k,int n);	//a^n
string ChiaHai(string a);
string Nhan(string a, int n);
string IntSgString(int a);
int StrSgInt(string a);

class QFloat
{
private:
	 int qFloat[4];
public:
	QFloat();
	void setQFloat(string a);
	string getQFloat();

	string BitSauPhay(string a);
	string BitTruocPhay(string a);
	string DecToBin(string a);
	void ScanQFloat(string a,int n);

	string SoPhay(string a);
	string BinToDec(string a);

	string PrintQFloat(int n);
};