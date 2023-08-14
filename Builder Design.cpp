#include<iostream>
using namespace std;


// here if student have a lot properties and some of them are not optional,
// then we have to write many constructors for combination of those properties.

// to overcome that we create a studentBuilder class that can help us create a student object step by step
// by only add those properties that we need

// Que. why not use setters instead of builder
// Ans. we use setters to build a mutable object but builder to use immutable objects and they both can co-exist.


class Student {
public:
	int roll;
	string name;
	string fatherName;
	string montherName;
	string gender;
	int age;

	void print() {
		cout << "roll :" << roll << '\n';
		cout << "name :" << name << '\n';
		cout << "fatherName :" << fatherName << '\n';
		cout << "montherName :" << montherName << '\n';
		cout << "gender :" << gender << '\n';
		cout << "age :" << age << '\n';
	}
};

class StudentBuilder {
public:
	Student student;

	StudentBuilder* setRoll(int roll) {
		this->student.roll = roll;
		return this;
	}
	StudentBuilder* setName(string name) {
		this->student.name = name;
		return this;
	}
	StudentBuilder* setFatherName(string fatherName) {
		this->student.fatherName = fatherName;
		return this;
	}
	StudentBuilder* setMontherName(string montherName) {
		this->student.montherName = montherName;
		return this;
	}
	StudentBuilder* setGender(string gender) {
		this->student.gender = gender;
		return this;
	}
	StudentBuilder* setAge(int age) {
		this->student.age = age;
		return this;
	}

	Student build() {
		return student;
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	StudentBuilder* studentBuilder = new StudentBuilder();

	Student s1 = studentBuilder->setRoll(123)
	             ->setName("Sourabh")
	             ->setGender("Male")
	             ->setAge(21)
	             ->build();

	s1.print();

}