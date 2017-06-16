// Nama/NIM 	: Taufan Mahaputra/13515028
// File				: BigInt.cpp
// Topik			: Big Number

#include "BigInt.h"

#define phb push_back
#define pob pop_back
using namespace std;

/*Constructor*/
BigInt::BigInt() {
}

BigInt::BigInt(long long lvalue) {
	while(lvalue != 0) {
		int num = lvalue % base;
		value.phb(num);
		lvalue = lvalue/base;
	}
	set(*this);
}

BigInt::BigInt(int lvalue) {
	while(lvalue != 0) {
		int num = lvalue % base;
		value.phb(num);
		lvalue = lvalue/base;
	}
	set(*this);	
}

BigInt::BigInt(string svalue) {
	if(svalue.length() == 0) {
		value.phb(0);
	}
	else {
		for(int i = svalue.length()-1; i >= 0; i--) {
			int num = svalue[i] - '0';
			value.phb(num);
		}
	}
	set(*this);
}

BigInt::BigInt(const BigInt& bigNum): value(bigNum.value) {
}


/* Operators */
BigInt& BigInt::operator=(const BigInt& bigNum) {
	value = bigNum.value;
	return *this;
}


/*Arithmatic Operators*/
BigInt BigInt::operator+(const BigInt& bigNum) {
	int len = (value.size() > bigNum.value.size()) ? value.size() : bigNum.value.size();
	int rem = 0; //menyimpan hasil sisa dari akhir perhitungan
	BigInt temp = bigNum;
		for(int i = 0; i < len; i++) {
			if(i == bigNum.value.size())
				temp.value.phb(0);
			temp.value[i] = value[i] + (i < bigNum.value.size() ? bigNum.value[i] : 0);
		}
		for(int i = 0; i < len; i++) {
			temp.value[i+1] += temp.value[i]/base;
			rem = temp.value[i]/base;
			temp.value[i] %= base;
		}
	if(rem)
		temp.value.phb(rem);
	set(temp);
	return temp;
}

BigInt BigInt::operator-(const BigInt& bigNum) {
	BigInt temp;
	int len = (value.size() > bigNum.value.size()) ? value.size() : bigNum.value.size();
	if(value.size() > bigNum.value.size()) {
		temp = *this;
		for(int i = 0; i < len; i++) {
			temp.value[i] = value[i] - (i < bigNum.value.size() ? bigNum.value[i] : 0);
		}
	}
	else {
		temp = bigNum;
		for(int i = 0; i < len; i++) {
			temp.value[i] = (i < value.size() ? value[i] : 0) - bigNum.value[i];
		}
	}

	for(int i = 0; i < len; i++) {
		if(temp.value[i] < 0) {
			temp.value[i] += base;
			temp.value[i+1] -= 1;
		}
	}
	set(temp);
	return temp;
}

BigInt BigInt::operator/(const BigInt& bigNum) {
	BigInt temp;
	temp = *this;
	int x = 0;
	while(temp >= bigNum) {
		temp = temp - bigNum;
		x++;
	}
	BigInt res(x);
	return res;
}

BigInt BigInt::operator*(const BigInt& bigNum) {
	BigInt temp;
	temp.value.assign(value.size()+bigNum.value.size(), 0);
		for(int i = 0; i < value.size(); i++) {
			int carry = 0;
			for(int j = 0; j < bigNum.value.size() || carry > 0; j++) {
				int res = temp.value[i+j] + carry + value[i]*(j < bigNum.value.size() ? bigNum.value[j] : 0);
				temp.value[i+j] = res % base;
				carry = res/base;
			}
		}
	set(temp);
 	return temp;
}

/* Comparison */
bool operator < (BigInt a, BigInt b) {
	if(a.value.size() != b.value.size())
		return a.value.size() < b.value.size();
	for(int i = a.value.size()-1; i >= 0;i--) {
		if(a.value[i] != b.value[i])
			return a.value[i] < b.value[i];
	}
	return false;
}

bool operator> (BigInt a, BigInt b) {
	return (b < a);
}

bool operator== (BigInt a, BigInt b) {
	return (!(a < b) && !(b < a));
}

bool operator<= (BigInt a, BigInt b) {
	return ((a < b) || (a == b));
}

bool operator>= (BigInt a, BigInt b) {
	return ((b < a) || (a == b));
}

/* Procedure */
void BigInt::set(BigInt& B) {
	while (B.value.size() > 1 && B.value.back() == 0)
		B.value.pob();
}


/* IO */
ostream& operator<<(ostream &out, const BigInt& val) {
	for(int i = val.value.size()-1; i >= 0; i--) 
		out << val.value[i];
	return out;
}