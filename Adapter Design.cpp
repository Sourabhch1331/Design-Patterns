#include <iostream>
#include<list>
using namespace std;

class Student {
public:
	virtual string getFirstName() = 0;
	virtual string getLastName() = 0;
	virtual int getRollNumber() = 0;
};


class SchoolStudent: public Student {
private:
	string firstName;
	string lastName;
	int rollNumber;

public:
	SchoolStudent(string firstName, string lastName, int rollNumber) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->rollNumber = rollNumber;
	}

	string getFirstName() {
		return firstName;
	}
	string getLastName() {
		return lastName;
	}
	int getRollNumber() {
		return rollNumber;
	}

};


class CollegeStudent {
private:
	string firstName;
	string lastName;
	int rollNumber;
public:

	CollegeStudent(string firstName, string lastName, int rollNumber) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->rollNumber = rollNumber;
	}

	string getName() {
		return firstName;
	}
	string getSurName() {
		return lastName;
	}
	int getRollID() {
		return rollNumber;
	}
};

// It is used to adapt between College student and Client
// in future if college student changes than we only need to change in adapter on in client code

class StudentAdapter: public Student {
private:
	CollegeStudent* collegeStudent;

public:
	StudentAdapter(CollegeStudent* collegeStudent) {
		this->collegeStudent = collegeStudent;
	}
	string getFirstName() {
		return collegeStudent->getName();
	}
	string getLastName() {
		return collegeStudent->getSurName();;
	}
	int getRollNumber() {
		return collegeStudent->getRollID();
	}
};

class Client {
public:
	list<Student*> studentList;

	Client() {}

	void addStudent(Student* s) {
		studentList.push_back(s);
	}

	void printStudentInfo() {
		cout << "Student(s) information:\n";
		cout << '\n';

		for (Student* s : studentList) {
			cout << s->getFirstName() << ' ' << s->getLastName() << '\n';
			cout << "Roll number: " << s->getRollNumber() << '\n';
			cout << '\n';
		}
	}

};

int main() {
	Client *client = new Client();

	client->addStudent(new SchoolStudent("chimtu", "vimdhayak", 14));
	client->addStudent(new SchoolStudent("chimki", "golddigger", 15));

	client->addStudent(new StudentAdapter(new CollegeStudent("Dogesh", "Chamatta", 7)));

	client->printStudentInfo();
}