#include"head.h"
int main()
{
	Teacher a;
	Student b;
	Teacher_Assistants c;
	cout << "该老师的信息为：\n";
	cout << "Name:"<<a.getN() << "  ID:" << a.getI() << "  WorkingHours:" << a.getwH() 
		<< "  Salary:$" << a.getSa()<< endl;
	cout << "\n该学生的信息为：\n";
	cout << "Name:" << b.getN() << "  ID:" << b.getI() << "  Class:" << b.getSC() 
		<< " Hours:" << b.getH() << endl;
	cout << "\n该助教的信息为：\n";
	cout << "Name:" << c.getN() << "  ID:" << c.getI() << "  Class:" << c.getSC() 
		<< "  Hours:" << c.getH() << "  WorkingHours:"<< c.getwH() << "  Salary:$" 
		<< c.getSa()<< endl;
	Teacher A("zhang", "160405319", 45);
	A.calculateSalary();
	Student B("sheng", "536", "class 3 grade 5", 100);
	Teacher_Assistants C("wang", "5689", "class 2 grade 6", 200, 50);
	C.calculateSalary();
	cout << "\n\n该老师的信息为：\n";
	cout << "Name:" << A.getN() << "  ID:" << A.getI() << "  WorkingHours:" << A.getwH()
		<< "  Salary:$" << A.getSa() << endl;
	cout << "\n该学生的信息为：\n";
	cout << "Name:" << B.getN() << "  ID:" << B.getI() << "  Class:" << B.getSC()
		<< " Hours:" << B.getH() << endl;
	cout << "\n该助教的信息为：\n";
	cout << "Name:" << C.getN() << "  ID:" << C.getI() << "  Class:" << C.getSC()
		<< "  Hours:" << C.getH() << "  WorkingHours:" << C.getwH() << "  Salary:$"
		<< C.getSa() << endl;
	return 0;
}