#include<bits/stdc++.h>
using namespace std;

// It is a creational design pattern used when we only need one instance of the class(eg: DB connection,Logger).
// The constructor need to be private ,so no one can modify it

// Egar loading
// create instance of class as soon as app is up

class DBConnection {
private:
	string name;
	static DBConnection* instance;
	static mutex mtx;

	DBConnection(string name) {
		this->name = name;
	};

public:
	// Singletons should not be cloneable.
	DBConnection(DBConnection &other) = delete;

	// Singletons should not be assignable.
	void operator=(const DBConnection &) = delete;

	static DBConnection* getInstance(string name) {
		// aquire the lock
		unique_guard<mutex> lock(mtx);
		if (instance == NULL) {
			instance = new DBConnection(name);
		}
		return instance;
	}

	void print() {
		cout << "The name of this instance is " << name << '\n';
	}


	void someBusinessLogic() {
		// some business logic here....
	}
};

DBConnection* DBConnection::instance = NULL;
mutex DBConnection::mtx;


int main() {
	DBConnection* singleConnection = DBConnection::getInstance("one");
	DBConnection* singleConnection1 = DBConnection::getInstance("two");
	singleConnection->print();
	singleConnection1->print();
}