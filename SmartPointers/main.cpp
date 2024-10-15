#include<iostream>
#include "SharedPointer.h"

class TestSmatrPointrs {
private:
	int m_id;
	std::string m_name;
public:
	TestSmatrPointrs() = default;
	TestSmatrPointrs(int id, std::string name) :m_id(id), m_name(name) {
		std::cout << "TestSmatrPointrs : Parametrized ctor called\n";
	}
	void print() {
		std::cout << "Id : " << m_id << std::endl;
		std::cout << "Name : " << m_name << std::endl;
	}
};

int main() {
	SharedPointer<TestSmatrPointrs> ptr1; //default Ctor
	SharedPointer<TestSmatrPointrs> ptr2(new TestSmatrPointrs(1,"Abhay Kumar")); //parametrized Ctor
	SharedPointer<TestSmatrPointrs> ptr3(ptr2); //Copy Ctor
	ptr1 = ptr2; //Copy Assigmnet operator
	SharedPointer<TestSmatrPointrs> ptr4(std::move(ptr2)); //move copy ctor
	ptr2 = std::move(ptr3);

	ptr1.reset();
	ptr1.reset(new TestSmatrPointrs(2,"Annya Adarsh"));

	//std::cout << (*ptr1);
	ptr1->print();

	ptr1.get();

	SharedPointer<int> int1; //default Ctor
	SharedPointer<int> int2(new int(3));
	std::cout << std::endl << (*int2);

}
