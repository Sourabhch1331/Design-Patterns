#include<iostream>
using namespace std;

class User {
public:
	string name;
	string password;
	string passwordConfirm;
	int age;

	User(string name, string password, string passwordConfirm, int age) {
		this->name = name;
		this->password = password;
		this->passwordConfirm = passwordConfirm;
		this->age = age;
	}
};

class AuthenticationHandler {
public:
	AuthenticationHandler* nextHandler;

	AuthenticationHandler(AuthenticationHandler* nextHandler) {
		this->nextHandler = nextHandler;
	}

	virtual void authenticate(User* user) {
		if (nextHandler != NULL) {
			nextHandler->authenticate(user);
		}
		else {
			cout << "Authentication succesful\n";
		}
	}
};


class NameVerifier: public AuthenticationHandler {
public:
	NameVerifier(AuthenticationHandler* nextAuthHandler): AuthenticationHandler(nextAuthHandler) {}

	void authenticate(User* user) {
		if (user->name.size() <= 5) {
			cout << "Name should have more than 5 characters\n";
			return;
		}
		AuthenticationHandler::authenticate(user);
	}

};

class PasswordVerifier: public AuthenticationHandler {
public:
	PasswordVerifier(AuthenticationHandler* nextAuthHandler): AuthenticationHandler(nextAuthHandler) {}

	void authenticate(User* user) {
		if (user->password != user->passwordConfirm || user->password.size() < 8) {
			cout << "Password not same or length is smaller than 8\n";
			return;
		}
		AuthenticationHandler::authenticate(user);
	}

};


class AgeVerifier: public AuthenticationHandler {
public:
	AgeVerifier(AuthenticationHandler* nextAuthHandler): AuthenticationHandler(nextAuthHandler) {}

	void authenticate(User* user) {
		if (user->age < 18) {
			cout << "Under age \nGo watch Chhota bheem\n";
			return;
		}
		AuthenticationHandler::authenticate(user);
	}

};

int main() {
	User* user1 = new User("Dogesh", "12345678", "12345678", 18);
	User* user2 = new User("Chimtu", "chimki4thclasswali", "chimki4thclasswali", 11);
	AuthenticationHandler* authHandler = new NameVerifier(new AgeVerifier(new PasswordVerifier(NULL)));
	authHandler->authenticate(user1);
	authHandler->authenticate(user2);
}