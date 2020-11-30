#include"myLong.h"

Long Long::operator<<(unsigned int value){
	Long toRet;
	if(value == 0){
		toRet.a = a;
		toRet.b = b;
		return toRet;
		}
	if(value < 32){
		toRet.a =  (a << value);
		toRet.a += (b >> (32-value));
		toRet.b =  (b << value);
		}
	else if(value < 64)
		toRet.a =  (b << (value-32));
	
	return toRet;
	}
Long Long::operator>>(unsigned int value){
	Long toRet;
	if(value == 0){
		toRet.a = a;
		toRet.b = b;
		return toRet;
		}
	if(value < 32){
		toRet.b =  (b >> value);
		toRet.b += (a << (32-value));
		toRet.a =  (a >> value);
		}
	else if(value < 64)
		toRet.b =  (a >> (value-32));

	return toRet;
	}

Long operator&(const Long &X, const Long &Y){
	Long toRet;
	toRet.a = ( X.a & Y.a );
	toRet.b = ( X.b & Y.b );
	return toRet;
	}

Long& Long::operator++(){
	++b;
	if(b == 0)
		++a;
	return *this;
	}
Long& Long::operator--(){
	if(b == 0)
		--a;
	--b;
	return *this;
	}

bool operator==(const Long &X, const Long &Y)
	{return ((X.a == Y.a) && (X.b == Y.b));}
bool operator!=(const Long &X, const Long &Y)
	{return !(X==Y);}
bool operator< (const Long &X, const Long &Y){
	if(X.a == Y.a)
		return (X.b < Y.b);
	return (X.a < Y.a);
	}
bool operator> (const Long &X, const Long &Y)
	{return (Y<X);}
bool operator<=(const Long &X, const Long &Y)
	{return !(Y<X);}
bool operator>=(const Long &X, const Long &Y)
	{return !(X<Y);}


Long operator+(const Long &X, const Long &Y){
	Long toRet;
	toRet.a = X.a + Y.a;
	if(X.b > UINT32_MAX - Y.b)
		++toRet.a;
	toRet.b = X.b + Y.b;
	return toRet;
	}
Long operator-(const Long &X, const Long &Y){
	Long toRet = X;
	if(toRet.b < Y.b)
		--toRet.a;
	toRet.b -= Y.b;
	toRet.a -= Y.a;
	return toRet;
	}

Long& Long::operator+=(const Long &v){
	a += v.a;
	if(b > UINT32_MAX - v.b)
		++a;
	b += v.b;
	return *this;
	}
Long& Long::operator-=(const Long &v){
	a -= v.a;
	if(b < v.b)
		--a;
	b -= v.b;
	return *this;
	}

Long helpMul(uint32_t x, uint32_t y){
	Long toRet, middle;
	
	// X.b * Y.b
	toRet.b = (x % (1<<16)) * (y % (1<<16));
	toRet.a = (x >> 16) * (y >> 16);
	middle.b = (x >> 16) * (y % (1<<16));
	middle += (x % (1<<16)) * (y >> 16);
	toRet += (middle << 16);

	return toRet;
	}

void divideLong(const Long &X, const Long &Y, Long &Q, Long &R){
	Q.a = 0;
	Q.b = 0;
	R.a = 0;
	R.b = 0;

	Long cX = X; // copy of X

	for(int i=63; i>=0; --i){
		R = R << 1;
		R += ((cX>>i).b % 2);
		if(R >= Y){
			R -= Y;
			Q += Long(0, 1) << i;
			}
		}
	}

Long operator*(const Long &X, const Long &Y){
	Long toRet;

	toRet  = helpMul(X.b, Y.b);
	toRet += helpMul(X.a, Y.b) << 32;
	toRet += helpMul(X.b, Y.a) << 32;

	return toRet;
	}

Long operator/(const Long &X, const Long &Y){
	Long Q, R;
	divideLong(X, Y, Q, R);
	return Q;
	}
Long operator%(const Long &X, const Long &Y){
	Long Q, R;
	divideLong(X, Y, Q, R);
	return R;
	}
