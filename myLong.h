// Савченко И. В.

#ifndef _MY_LONG_
#define _MY_LONG_

#include<cstdint>


class Long{
private:
	uint32_t a, b; // a - старший разряд
public:
	Long() : a(0), b(0)
		{}
	Long(uint64_t x) // для тестов
		{setBy64(x);}
	Long(uint32_t _a, uint32_t _b) : a(_a), b(_b)
		{}

	uint64_t getUInt64() const{ // для тестов
		uint64_t toRet = a;
		toRet = toRet << 32;
		toRet += b;
		return toRet;
		}

	void setBy64(uint64_t x){
		b = x;
		a = x >> 32;
		}

	friend Long operator+(const Long &X, const Long &Y);
	friend Long operator-(const Long &X, const Long &Y);
	friend Long operator*(const Long &X, const Long &Y);
	friend Long operator/(const Long &X, const Long &Y);
	friend Long operator%(const Long &X, const Long &Y);

	friend Long helpMul(uint32_t x, uint32_t y);
	friend void divideLong(const Long &X, const Long &Y, Long &Q, Long &R);

	Long& operator++();
	Long& operator--();
	Long& operator+=(const Long &v);
	Long& operator-=(const Long &v);

	Long operator<<(unsigned int value);
	Long operator>>(unsigned int value);
	friend Long operator&(const Long &X, const Long &Y);

	friend bool operator==(const Long &X, const Long &Y);
	friend bool operator!=(const Long &X, const Long &Y);
	friend bool operator< (const Long &X, const Long &Y);
	friend bool operator> (const Long &X, const Long &Y);
	friend bool operator<=(const Long &X, const Long &Y);
	friend bool operator>=(const Long &X, const Long &Y);
};

#endif
