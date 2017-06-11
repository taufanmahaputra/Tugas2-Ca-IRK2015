// Nama/NIM 	: Taufan Mahaputra/13515028
// File				: DriverBigInt.cpp
// Topik			: Big Number

#include "BigInt.h"

int main() {
	/*Contoh bilangan*/
	cout << "test input" << endl;
	BigInt a(9999999999); //10 digit
	BigInt b("123123123123123123123123123281"); //30digit
	BigInt c(772); //3 digit
	BigInt d("831232138123812312893781273871273821737128378127312737128378127381278937812738912789738912783");
	cout << a << endl << b << endl << c << endl << d << endl;

	/*Contoh operator+*/
	cout << endl << "operator+" << endl; 
	BigInt e(125); BigInt f(50);
	cout << e << " + " << f << " = " << e+f << endl;
	BigInt op1("900"); BigInt op2("555");
	cout << op1 << " + " << op2 << " = " << op1+op2 << endl;
	BigInt op3("12312312312312312312"); BigInt op4("12312312312312312312");
	cout << op3 << " + " << op4 << " = " << op3+op4 << endl;

	/*Contoh operator* */
	cout << endl << "operator*" << endl;
	BigInt op5(5); BigInt op6(100); BigInt op7("900"); BigInt op8("1132"); 
	BigInt op9("12312312312312312312"); BigInt op10("12312312312312312312");
	cout << op5 << " * " << op6 << " = " << op5*op6 << endl;
	cout << op7 << " * " << op8 << " = " << op7*op8 << endl;
	cout << op9 << " * " << op10 << " = " << op9*op10 << endl;

	
	return 0;
}
