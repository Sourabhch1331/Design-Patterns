#include<iostream>
using namespace std;


// Here instead of Vehicle class handling and implementing a driving strategy
// We created an abstract class DriveStrategy and then implemented it with a diff
// drive functionalities

// so the object through constructor injection can create a driving strategy at runtime
// so strategy pattern is used to decide the behavior of objects at runtime


class DriveStrategy {
public:
	virtual void drive() = 0;
};


//Implementing drive strategy

class NormalDrive: public DriveStrategy {
public:
	void drive() {
		cout << "This is normal Drive Functionality\n";
	}
};

class SportDrive: public DriveStrategy {
public:
	void drive() {
		cout << "This is Sport Drive Functionality\n";
	}
};

class OffRoadDrive: public DriveStrategy {
public:
	void drive() {
		cout << "This is OffRoad Drive Functionality\n";
	}
};

class Vehicle {
public:
	string name;
	DriveStrategy* driveStrategyObj;

	Vehicle(DriveStrategy* requiredDriveStrategy) {
		this->name = name;
		this->driveStrategyObj = requiredDriveStrategy;
	}

	void drive() {
		driveStrategyObj->drive();
	}

	void printInfo() {
		cout << "Name of Car " << name << '\n';
	}
};


// child of a vehicle will decide which drive strategy they want


class SportCar: public Vehicle {
public:
	SportCar(): Vehicle(new SportDrive()) {}
};

class RegularCar: public Vehicle {
public:
	RegularCar(): Vehicle(new NormalDrive()) {}
};

class OffRoadCar: public Vehicle {
public:
	OffRoadCar(): Vehicle(new OffRoadDrive()) {}
};

int main() {
	Vehicle* myOffRoadCar = new OffRoadCar();
	Vehicle* mySportCar = new SportCar();           // i wish i had one :)
	Vehicle* myRegularCar = new RegularCar();

	myOffRoadCar->drive();
	mySportCar->drive();
	myRegularCar->drive();
}
