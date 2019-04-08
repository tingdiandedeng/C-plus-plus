#include<string>
#include<iostream>
using namespace std;

class MyInteger {
private:
	int value;
public:
	MyInteger(int);
	int get();
	bool isEven() const;
	static bool isEven(int) ;
	bool isEqual(const MyInteger&) const;
	MyInteger& parseInt(const string&);
};
