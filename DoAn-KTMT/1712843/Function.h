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
	string BuHai(string a);	//Bieu dien so am

	void ScanQInt(string a, int n);
	string PrinQInt(int n);

	string ChiaHai(string a);
	string DecToBin(string a);

	string NhanHai(string a);
	string HaiMu(int n);
	string CongHaiString(string a, string b);	//khong cung kich thuoc
	string BinToDec(string a);

	string BinToHex(string a);

	string HvsB(char a);
	string HexToBin(string a);

	string CongBit(string BitA, string BitB); //ca hai deu co 128 bit;

	QInt operator+(QInt a);
	QInt operator-(QInt a);
	int DemBit(string a);
	QInt operator*(QInt a);
	QInt operator/(QInt a);
	
	//Nhap Xuat
	
};