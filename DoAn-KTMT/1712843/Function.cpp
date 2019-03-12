#include"Function.h"

QInt::QInt()
{
	for (int i = 0; i < 4; i++)
		qInt[i] = 0;
}

string QInt::getQInt()	//chi dung voi binary
{
	string a;
	for (int i = 0; i < 4; i++)
	{
		for (int j = i * 32; j < (i + 1) * 32; j++)
		{
			a.push_back(char(((qInt[i] >> (((i + 1) * 32 - 1) - j)) & 1) + 48));
		}
	}
	return a;
}

void QInt::setQInt(string a)	//chi dung voi binary
{
	for (int i = 0; i < 4; i++)	//Ghi lai gia tri khoi tao
	{
		qInt[i] = 0;
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (i > 127)//chuoi a khong qua 128 phan tu
		{
			cout << "Tran so" << endl;
			exit(1);
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = i * 32; j < (i + 1) * 32; j++)
			{
				if (int(a[j] - 48) == 1)
				{
					qInt[i] = (1 << ((i + 1) * 32 - 1 - j)) | qInt[i];
				}
			}
		}
	}
}

void QInt::XuatStrBit(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

string QInt::BuHai(string a)
{
	for (int i = 0; i < 128; i++)
		a[i] = (a[i] == '0') ? '1' : '0';
	string b = "1";
	b = DecToBin(b);
	return CongBit(a,b);
}

void QInt::ScanQInt(string a, int n)
{
	if (n == 2)
	{
		if (a.length() < 128)
		{
			for (int i = 0; i < 128 - a.length(); i++)
				a.insert(0, 1, '0');
		}
		setQInt(a);
	}
	if (n == 10)
	{
		a = DecToBin(a);
		setQInt(a);
	}
	if (n == 16);
}

string QInt::PrinQInt(int n)
{
	if (n == 2)
		return getQInt();
	if (n == 10)
	{
		string b = getQInt();
		if (b[0] == '1');
	}
	
}

string QInt::ChiaHai(string a)
{
	string b;
	int du = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (du == 0)
		{
			b.push_back((char)((((int)a[i] - 48) / 2) + 48));
			du = ((int)a[i] - 48) % 2;
		}
		else {
			du = du * 10 + ((int)a[i] - 48);
			b.push_back((char)((du / 2) + 48));
			du = du % 2;
		}
	}
	while (b[0] == '0')
		b.erase(b.begin());
	return b;
}

string QInt::DecToBin(string a)
{
	string b;
	int am = 0;
	for (int i = 0; i < 128; i++)
		b.push_back('0');
	if (a[0] == '-')
	{
		am = 1;
		a.erase(a.begin());
	}
	for (int i = 0; a != ""; i++)
	{
		b[128 - i - 1] = (a[a.length() - 1] % 2 == 0) ? '0' : '1';
		a = ChiaHai(a);
	}
	if (am == 1)
		b = BuHai(b);
	return b;
}

string QInt::NhanHai(string a)
{
	int *b = new int[a.length() + 1];
	string KQ;
	for (int i = 0; i < a.length() + 1; i++)
		b[i] = 0;
	for (int i = a.length() - 1; i >=0; i--)
	{
		b[i + 1] =b[i + 1] + (int(a[i] - 48) * 2);
		if (b[i + 1] >= 10 && i - 1 >= 0)
		{
			b[i] = 1;
			b[i + 1] = b[i + 1] % 10;
		}
		KQ.insert(0, 1, char(b[i + 1]) + 48);
	}
	if (KQ[0] == '0')
		KQ.erase(KQ.begin());
	delete[] b;
	return KQ;
}

string QInt::BinToDec(string a)
{
	return string();
}

string QInt::CongBit(string BitA, string BitB)
{
	int tong;
	string KQ;
	for (int i = 127; i >=0 ; i--)
	{
		tong = int(BitA[i] - 48) + int(BitB[i] - 48);
		if (tong < 2)
		{
			KQ.insert(0, 1, char(tong + 48));
		}
		else {
			if (tong == 2)
				KQ.insert(0, 1, '0');
			if(tong ==3)
				KQ.insert(0, 1, '1');
			if (i - 1 >= 0)
					BitA[i - 1] = BitA[i - 1] + 1;
		}
	}
	return KQ;
}



