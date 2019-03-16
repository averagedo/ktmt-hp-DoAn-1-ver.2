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
			a.push_back(char(((qInt[i] >> (((i + 1) * 32 - 1) - j)) & 1) + 48));
	}
	return a;
}

void QInt::setQInt(string a)	//chi dung voi binary
{
	for (int i = 0; i < 4; i++)	//Ghi lai gia tri khoi tao
		qInt[i] = 0;
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
					qInt[i] = (1 << ((i + 1) * 32 - 1 - j)) | qInt[i];
			}
		}
	}
}

void QInt::XuatStrBit(string a)
{
	for (int i = 0; i < a.length(); i++)
		cout << a[i] << " ";
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
		return BinToDec(getQInt());
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
		if (b[i + 1] >= 10 && i >= 0)
		{
			b[i] = 1;
			b[i + 1] = b[i + 1] % 10;
		}
		KQ.insert(0, 1, char(b[i + 1]) + 48);
	}
	KQ.insert(0, 1, char(b[0]) + 48);
	if (KQ[0] == '0')
		KQ.erase(KQ.begin());
	delete[] b;
	return KQ;
}

string QInt::HaiMu(int n)
{
	string a="1";
	if (n == 0)
		return a;
	for (int i = 0; i < n; i++)
		a = NhanHai(a);
	return a;
}

string QInt::CongHaiString(string a, string b)
{
	if (a.length() < b.length())
		a.swap(b);
	int size = a.length() - b.length();
	for (int i = 0; i < size; i++)
		b.insert(0, 1, '0');
	for (int i = a.length() - 1; i >= 0; i--)
	{
		a[i] = char(int((int)(a[i] - 48) + (int)(b[i] - 48)) + 48);
		if (a[i] > 57)
		{
			a[i] = a[i] - 10;
			if (i - 1 < 0)
				a.insert(0, 1, '1');
			else
				a[i - 1]++;
		}
	}
	return a;
}

string QInt::BinToDec(string a)
{
	string KQ = "0";
	int am = 0;
	if (a[0] == '1')
	{
		am = 1;
		a = BuHai(a);
	}
	for (int i = 127; i >= 0; i--)
	{
		if (a[i] == '1')
			KQ = CongHaiString(KQ, HaiMu(127 - i));
	}
	if (am == 1)
		KQ.insert(0, 1, '-');
	return KQ;
}

string QInt::BinToHex(string a)
{
	string b = "0", KQ;
	int j = 0;
	for (int i = 127; i >=0; i--)
	{
		if (a[i] == '1')
			b = CongHaiString(b, HaiMu(j));
		j++;
		if (j == 4)
		{
			if (b.length() == 2)
				KQ.insert(0, 1, (b[1] + 17));
			else
				KQ.insert(0, b);
			j = 0;
			b = "0";
		}
	}
	return KQ;
}

string QInt::HvsB(char a)
{
	string KQ;
	if ((int)a > 57)
	{
		KQ.push_back(a - 17);
		KQ.insert(0, 1, '1');
	}
	else
		KQ.insert(0, 1, a);
	return KQ;
}

string QInt::HexToBin(string a)
{
	string b, c, KQ;
	for (int i = 0; i < 32; i++)
	{
		b = HvsB(a[i]);
		for (int j = 0; b != ""; j++)
		{
			c.insert(0, 1, (b[b.length() - 1] % 2 == 0) ? '0' : '1');
			b = ChiaHai(b);
		}
		for (int j = 0; c.length() < 4; j++)
			c.insert(0, 1, '0');
		KQ = KQ + c;
		c.clear();
	}
	return KQ;
}

string QInt::CongBit(string BitA, string BitB)
{
	int tong;
	string KQ;
	for (int i = 127; i >=0 ; i--)
	{
		tong = int(BitA[i] - 48) + int(BitB[i] - 48);
		if (tong < 2)
			KQ.insert(0, 1, char(tong + 48));
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

QInt QInt::operator+(QInt a)
{
	string str1 = this->getQInt();
	string str2 = a.getQInt();
	a.setQInt(CongBit(str1, str2));
	return a;
}

QInt QInt::operator-(QInt a)
{
	string str = a.getQInt();
	str = BuHai(str);
	a.setQInt(str);
	return a + *this;
}

int QInt::DemBit(string a)
{
	if (a[0] == '1')
		a = BuHai(a);
	for (int i = 0; i < 128; i++)
	{
		if (a[i] == '1')
			return i;
	}
}

QInt QInt::operator*(QInt a)
{
	string M = this->getQInt();
	string Q = a.getQInt();
	string Q0 = "0", A;
	int n, j1, j2;
	j1 = DemBit(M);
	j2 = DemBit(Q);
	n = (j1 < j2) ? 128 - j1 + 1 : 128 - j2 + 1;	//So bit su dung
	for (int i = 0; i < 128; i++)
		A.push_back('0');
	for (int i = 0; i < n; i++)
	{
		if (Q[127] == '1' && Q0[0] == '0')
			A = CongBit(A, BuHai(M));
		if (Q[127] == '0' && Q0[0] == '1')
			A = CongBit(A, M);
		//shift right
		Q0[0] = Q[127];
		Q.erase(Q.end()-1);
		Q.insert(128 - n, 1, A[127]);
		A.erase(A.end()-1);
		if (A[128 - n] == '0')
			A.insert(128 - n, 1, '0');
		else
			A.insert(128 - n, 1, '1');
		if (A[128 - n - 1] == '1')
			A[128 - n - 1] = '0';
	}
	string KQ;
	for (int i = 0; i < 128; i++)
		KQ.push_back('0');
	KQ.replace(128 - n, n, Q, 128 - n, n);
	KQ.replace(128 - 2 * n, n, A, 128 - n, n);
	if (KQ[128 - 2 * n] == '1')
		for (int i = 0; i < 128 - 2 * n; i++)
			KQ[i] = '1';
	a.setQInt(KQ);
	return a;
}

QInt QInt::operator/(QInt a)
{
	string Q = this->getQInt();
	string M = a.getQInt();
	string A;
	int n, j1, j2, am1 = 0, am2 = 0;
	j1 = DemBit(M);
	j2 = DemBit(Q);
	n = (j1 < j2) ? 128 - j1 + 1 : 128 - j2 + 1;	//So bit su dung
	if (Q[0] == '1')
	{
		Q = BuHai(Q);
		am1 = 1;
	}
	if (M[0] == '1')
	{
		M = BuHai(M);
		am2 = 1;
	}
	for (int i = 0; i < 128; i++)
		A.push_back('0');
	for (int i = 0; i < n; i++)
	{
		A.erase(A.begin() + 128 - n);
		A.insert(127, 1, Q[128 - n]);
		Q.erase(Q.end() - n);
		Q.insert(127, 1, '0');
		A = CongBit(A, BuHai(M));
		if (A[128 - n] == '1')
			A = CongBit(A , M);
		else
			Q[127] = '1';
	}
	string KQ;
	for (int i = 0; i < 128; i++)
		KQ.push_back('0');
	KQ.replace(128 - n, n, Q, 128 - n, n);
	if (KQ[128 - 2 * n] == '1')
		for (int i = 0; i < 128 - 2 * n; i++)
			KQ[i] = '1';
	if ((am1 == 1 && am2 == 0) || (am1 == 0 && am2 == 1))
		KQ = BuHai(KQ);
	a.setQInt(KQ);
	return a;
}



