/*	Савченко Илья Владимирович
 *	М8О-208Б-19
 *	вар 13
 *	Создать класс Long для работы с целыми беззнаковыми числами из 64 бит.
 *	Число должно быть представлено двумя полями unsigned int.
 *	Должны быть реализованы арифметические операции,
 *	присутствующие в С++, и сравнения.
 */
#include<iostream>
#include"myLong.h"

using namespace std;

void myTest(uint64_t x, uint64_t y, uint64_t z, const Long &C, char op){
	uint64_t test = C.getUInt64();
	if(z == test){
		cout
			<< x <<" "<< op <<" "<< y
			<< "\n    = "
			<< z << endl;
		}
	else{
		cout << "FAIL: "
			<< x << " "<<op<<" " 
			<< y
			<< "\n  ! = "
			<< z
			<< "\n  ! = "
			<< test << endl;
		}
	}

int main(){
	uint64_t x, y, z, test;
	Long A, B, C;


	cin >> x >> y;
	A.setBy64(x);
	B.setBy64(y);

	z = x+y;
	C = A+B;
	myTest(x, y, z, C, '+');

	z = x-y;
	C = A-B;
	myTest(x, y, z, C, '-');

	z = x*y;
	C = A*B;
	myTest(x, y, z, C, '*');

	z = x/y;
	C = A/B;
	myTest(x, y, z, C, '/');

	z = x%y;
	C = A%B;
	myTest(x, y, z, C, '%');

	cout
		<< "A == B  " << (A==B) <<endl
		<< "A <  B  " << (A< B) <<endl
		<< "A >= B  " << (A>=B) <<endl;
	}
