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

string BuHai(string a)
{
	QInt I;
	for (int i = 0; i < 128; i++)
		a[i] = (a[i] == '0') ? '1' : '0';
	string b = "1";
	b = I.DecToBin(b);
	return CongBit(a,b);
}

void QInt::ScanQInt(string a, int n)
{
	if (n == 2)
	{
		if (a.length() < 128)
		{
			int l = a.length();
			for (int i = 0; i < 128 - l; i++)
				a.insert(0, 1, '0');
		}
		setQInt(a);
	}
	if (n == 10)
		setQInt(DecToBin(a));
	if (n == 16)
		setQInt(HexToBin(a));
}

string QInt::PrinQInt(int n)
{
	if (n == 2)
		return getQInt();
	if (n == 10)
		return BinToDec(getQInt());
	if (n == 16)
		return BinToHex(getQInt());
}

string ChiaHai(string a)
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

string Nhan(string a,int n)
{
	int *b = new int[a.length() + 1];
	string KQ;
	for (int i = 0; i < a.length() + 1; i++)
		b[i] = 0;
	for (int i = a.length() - 1; i >=0; i--)
	{
		b[i + 1] =b[i + 1] + (int(a[i] - 48) * n);
		if (b[i + 1] >= 10 && i >= 0)
		{
			b[i] = b[i + 1] / 10;
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

string IntSgString(int a)
{
	int i = 0, du;
	string b;
	while (a != 0)
	{
		du = a % 10;
		b.insert(0, 1, char(du + 48));
		a = a / 10;
	}
	return b;
}

int StrSgInt(string a)
{
	int b = 0;
	for (int i = 0; i < a.length(); i++)
		b = (b + int(a[i] - 48)) * 10;
	b = b / 10;
	return b;
}

string Mu(int k,int n)
{
	string a="1";
	if (n == 0)
		return a;
	for (int i = 0; i < n; i++)
		a = Nhan(a, k);
	return a;
}

string CongHaiString(string a, string b)
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
			KQ = CongHaiString(KQ, Mu(2, 127 - i));
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
			b = CongHaiString(b, Mu(2, j));
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

string CongBit(string BitA, string BitB)
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

QInt& QInt::operator=(string a)
{
	if (a[0] == '0' && a[1] == 'x')// hệ 16
	{
		a.erase(0, 2);
		a = HexToBin(a);
		setQInt(a);
	}
	else if (a[0] == 'B' || a[0] == 'b')//hệ 2
	{
		a.erase(0, 1);
		char c;
		a.insert(0, 128 - a.length(), a[0]);// Thêm cho đủ 128 bit và bít đầu tiên sẽ là bít xét dấu
		setQInt(a);
	}
	else     //hệ 10
	{
		setQInt(DecToBin(a));
	}
	return *this;
}

bool QInt::operator<(QInt x)
{
	string a = BinToDec(getQInt());  // đổi ra hệ 10
	string b = x.BinToDec(x.getQInt());
	if (!SoSanh2ChuoiNguyen(a, b) && a != b)
		return true;
	return false;
}


bool QInt::operator<=(QInt x)
{
	string a = BinToDec(getQInt());
	string b = x.BinToDec(x.getQInt());
	if (!SoSanh2ChuoiNguyen(a, b) && a == b)
		return true;
	return false;
}


bool QInt::operator>(QInt x)
{
	string a = BinToDec(getQInt());
	string b = x.BinToDec(x.getQInt());
	if (SoSanh2ChuoiNguyen(a, b) && a != b)
		return true;
	return false;
}


bool QInt::operator>=(QInt x)
{
	string a = BinToDec(getQInt());
	string b = x.BinToDec(x.getQInt());
	if (SoSanh2ChuoiNguyen(a, b) && a == b)
		return true;
	return false;
}

bool QInt::operator==(QInt x)
{
	string a = BinToDec(getQInt());
	string b = x.BinToDec(x.getQInt());
	return a == b ? true : false;
}

bool QInt::operator!=(QInt x)
{
	string a = BinToDec(getQInt());
	string b = x.BinToDec(x.getQInt());
	return a != b ? true : false;
}

QInt QInt::operator&(QInt x)
{
	QInt k;
	string a = getQInt();
	string b = x.getQInt();
	string Temp = "";
	for (int i = 127; i >= 0; i--)
	{
		if (a[i] == '1'&& b[i] == '1')
			Temp.insert(0, 1, '1');
		else
			Temp.insert(0, 1, '0');
	}
	k.setQInt(Temp);
	return k;
}

QInt QInt::operator|(QInt x)
{
	QInt k;
	string a = getQInt();
	string b = x.getQInt();
	string Temp = "";
	for (int i = 127; i >= 0; i--)
	{
		if (a[i] == '0' && b[i] == '0')
			Temp.insert(0, 1, '0');
		else
			Temp.insert(0, 1, '1');
	}
	k.setQInt(Temp);
	return k;
}

QInt QInt::operator^(QInt x)
{
	QInt k;
	string a = getQInt();
	string b = x.getQInt();
	string Temp = "";
	for (int i = 127; i >= 0; i--)
	{
		if (a[i] == b[i])
			Temp.insert(0, 1, '0');
		else
			Temp.insert(0, 1, '1');
	}
	k.setQInt(Temp);
	return k;
}


QInt QInt::operator~()
{
	QInt k;
	string a = getQInt();
	string Temp = "";
	for (int i = 127; i >= 0; i--)
	{
		if (a[i] == '1')
			Temp.insert(0, 1, '0');
		else
			Temp.insert(0, 1, '1');
	}
	k.setQInt(Temp);
	return k;
}

QInt QInt::operator>>(int n)
{
	QInt x;
	string a = getQInt();
	for (int i = 127; i > 127 - n; i--)
	{
		a.erase(a.length() - 1, 1);
		a.insert(0, 1, a[0]);
	}
	x.setQInt(a);
	return x;
}

QInt QInt::operator<<(int n)
{
	QInt x;
	string a = getQInt();
	for(int i = 0; i < n; i++)
	{
		a.insert(128,1,'0');
		a.erase(a.begin());
	}
	x.setQInt(a);
	return x;
}

QInt QInt::Rol(int n)
{
	QInt k;
	string a = getQInt();
	int i = 0;
	while (i < n)
	{
		char c = a[0];
		a.erase(0, 1);
		a.insert(a.length(), 1, c);
		i++;
	}
	k.setQInt(a);
	return k;
}

QInt QInt::Ror(int n)
{
	QInt k;
	string a = getQInt();
	int i = 0;
	while (i < n)
	{
		char c = a[a.length() - 1];
		a.erase(a.length() - 1, 1);
		a.insert(0, 1, c);
		i++;
	}
	k.setQInt(a);
	return k;
}

bool SoSanh2ChuoiNguyen(string a, string b) // a có lớn hơn b hệ 10
{
	if (a[0] != '-' && b[0] == '-')
		return true;
	if (a[0] == '-'&& b[0] == '-')
	{
		if (a.length() < b.length())
			return true;
		else if (a.length() > b.length())
			return false;
		else
		{
			for (int i = 0; i < a.length(); i++)
				if ((a[i] - 48) < (b[i] + 48))
					return true;
		}
	}
	if (a[0] != '-'&& b[0] != '-')
	{
		if (a.length() > b.length())
			return true;
		else if (a.length() < b.length())
			return false;
		else
		{
			for (int i = 0; i < a.length(); i++)
				if ((a[i] - 48) > (b[i] + 48))
					return true;
		}
	}
	return false;
}

//bai02
QFloat::QFloat()
{
	for (int i = 0; i < 4; i++)
		qFloat[i] = 0;
}

void QFloat::setQFloat(string a)
{
	for (int i = 0; i < 4; i++)	//Ghi lai gia tri khoi tao
		qFloat[i] = 0;
	for (int i = 0; i < a.length(); i++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = i * 32; j < (i + 1) * 32; j++)
			{
				if (int(a[j] - 48) == 1)
					qFloat[i] = (1 << ((i + 1) * 32 - 1 - j)) | qFloat[i];
			}
		}
	}
}

string QFloat::getQFloat()
{
	string a;
	for (int i = 0; i < 4; i++)
	{
		for (int j = i * 32; j < (i + 1) * 32; j++)
			a.push_back(char(((qFloat[i] >> (((i + 1) * 32 - 1) - j)) & 1) + 48));
	}
	return a;
}

string QFloat::BitSauPhay(string a)
{
	string b;
	int length;;
	for (int i = 0; i < 16384; i++)//2^14=16384
	{
		length = a.length();
		a = Nhan(a, 2);
		if (a[0] == '1' && a.length() > length)
		{
			a.erase(a.begin());
			b.push_back('1');
		}
		else
			b.push_back('0');
		while (a!="" && a[a.length() - 1] == '0')
			a.erase(a.end() - 1);
		if (a == "")
			break;
	}
	return b;
}	

string QFloat::BitTruocPhay(string a)
{
	string b;
	for (int i = 0; a != ""; i++)
	{
		b.insert(0, 1, (a[a.length() - 1] % 2 == 0) ? '0' : '1');
		a = ChiaHai(a);
	}
	return b;
}

string QFloat::DecToBin(string a)
{
	string KQ;
	string dau, cuoi, ex ;
	int j = 0, mu = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '.')
		{
			j = i;
			break;
		}
	}
	dau.assign(a, 0, j);
	cuoi.assign(a, j + 1, a.length() - j);
	dau = BitTruocPhay(dau);
	cuoi = BitSauPhay(cuoi);
	if (dau == "0" && cuoi == "0")
	{
		string O;
		for (int i = 0; i < 128; i++)
			O.push_back('0');
		return O;
	}
	if (dau[0] == '-')
	{
		dau.erase(dau.begin());
		KQ.push_back('1');
	}
	else
		KQ.push_back('0');
	if (dau[0] == '0')
		for (int i = 0; dau[dau.length()-1] != '1'; i++)
		{
			dau.push_back(cuoi[0]);
			cuoi.erase(cuoi.begin());
			mu = mu - 1;
		}
	else
		for (int i = 0; dau.length() >= 2; i++)
		{
			cuoi.insert(0, 1, dau[dau.length() - 1]);
			dau.erase(dau.end() - 1);
			mu = mu + 1;
		}
	mu = mu + 16383;
	string strMu = IntSgString(mu);
	ex = BitTruocPhay(strMu);
	for (int i = ex.length(); i < 15; i++)
		ex.insert(0, 1, '0');
	KQ.append(ex);
	KQ.append(cuoi);
	for (int i = KQ.length() - 1; i < 128; i++)
		KQ.push_back('0');
	return KQ;
}

void QFloat::ScanQFloat(string a,int n)
{
	if (n == 2)
		setQFloat(a);
	if (n == 10)
		setQFloat(DecToBin(a));
}

string QFloat::SoPhay(string a)
{
	string KQ = "0";
	string mu;
	for (int i = 0; i < a.length(); i++)
	{
		KQ.push_back('0');
		if (a[i] == '1')
		{
			mu = Mu(5, i + 1);
			KQ = CongHaiString(KQ,mu);
		}

	}
	for (int i = KQ.length(); i < a.length(); i++)
		KQ.insert(0, 1, '0');
	while (KQ.length() > a.length())
		KQ.erase(KQ.begin());
	KQ.insert(0, 1, '.');
	return KQ;
}

string QFloat::BinToDec(string a)
{
	QInt M;
	string KQ, ex, dau ,cuoi;
	int mu, test=0;
	if(a[0] == '1') 
		KQ.insert(0, 1, '-');
	for (int i = 0; i < 128; i++)
	{
		if (a[i] == '1')
			test = 1;
	}
	if (test == 0)
		return "0.0";
	for (int i = 1; i < 16; i++)
		ex.push_back(a[i]);
	for (int i = 0; i < 128 - 16 + 1; i++)
		ex.insert(0, 1, '0');
	mu = StrSgInt(M.BinToDec(ex));
	mu = mu - 16383;
	for (int i = 0; i < 16; i++)
		a.erase(a.begin());
	if (mu < 0)
	{
		mu = mu * (-1);
		for (int i = 0; i < mu; i++)
		{
			if (i == 0)
				a.insert(0, 1, '1');
			else
				a.insert(0, 1, '0');
		}
		a.insert(0, 1, '.');
	}
	else
	{
		a.insert(0, 1, '1');
		a.insert(mu + 1, 1, '.');
	}
	while (a[a.length() - 1] == '0')
		a.erase(a.end() - 1);
	for (int i = a.length() - 1; a[i] != '.'; i--)
		cuoi.insert(0, 1, a[i]);
	cuoi = SoPhay(cuoi);
	for (int i = 0; a[i] != '.'; i++)
		dau.push_back(a[i]);
	for (int i = dau.length(); i < 128; i++)
		dau.insert(0, 1, '0');
	QInt V;
	dau = V.BinToDec(dau);
	KQ.append(dau);
	KQ.append(cuoi);
	return KQ;
}

string QFloat::PrintQFloat(int n)
{
	if (n == 2)
		return getQFloat();
	if (n == 10)
		return BinToDec(getQFloat());
}
