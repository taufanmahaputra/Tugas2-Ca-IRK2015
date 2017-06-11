// Nama/NIM 	: Taufan Mahaputra/13515028
// File				: BigInt.h
// Topik			: Big Number

#include <bits/stdc++.h>
#include <iostream>
#include <vector> 
#include <string>

using namespace std;

class BigInt {
public:
	/*Constructor*/
	BigInt();
	BigInt(long long lvalue);
	BigInt(string svalue);
	BigInt(const BigInt& bigNum);

	/* Operators */
	BigInt& operator=(const BigInt& bigNum);
	/*Artihmatic Operators*/
	BigInt operator+(const BigInt& bigNum);
	BigInt operator-(const BigInt& bigNum);
	BigInt operator/(const BigInt& bigNum);
	BigInt operator*(const BigInt& bigNum);

	/* Procedure */
	void set(BigInt& B);

	/* IO */
	friend ostream& operator<<(ostream &out, const BigInt& val);

private:
	vector<int> value;
	static const int base = 10;
};