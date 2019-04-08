#include"标头.h"
MyInteger::MyInteger(int m)
{
	value = m;
}
int MyInteger::get()
{
	return value;
}
bool MyInteger::isEven() const
{
	if (value % 2 == 0)
		return true;
	else
		return false;
}
bool MyInteger::isEven(int n)
{
	if (n % 2 == 0)
		return true;
	else
		return false;
}
bool MyInteger::isEqual(const MyInteger& integer) const
{
	if (this->value == integer.value)
		return true;
	else
		return false;
}
MyInteger& MyInteger::parseInt(const string& str)
{
	int sum = 0, n;
	n = str.length();
	for (int i = 0; i < n; i++)
		sum += (str[i] - '0')*pow(10, n - i - 1);
	value = sum;
	return *this;
}
int main()
{
	int m;
	cout << "To create an object, enter an integer\n";
	cin >> m;
	MyInteger* intP = new MyInteger(m);

	cout << intP->get() << endl;
	if (intP->isEven())
		cout << "It is an even\n";
	else
		cout << "It is an odd\n";

	cout << "Create another object\n";
	cin >> m;
	MyInteger intV(m);
	if (intP->isEqual(intV))
		cout << "The object is equal to another\n";
	else
		cout << "The object is unequal to another\n";

	cout << MyInteger::isEven(34) << endl;

	string st;
	cout << "Enter a digital string\n";
	cin >> st;
	int i = 0;
	while (i < st.length())
	{
		if (!isdigit(st[i]))
		{
			cout << "Retyping a digital string\n";
			cin >> st;
			i = 0;
		}
		else
			i++;
	}
	cout << intP->parseInt(st).get() << endl;  // 这个过程相当于atoi(st.c_str())
	delete intP;
	return 0;
}