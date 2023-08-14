#include<iostream>
using namespace std;

// Abstract Factory is a factory of factory which in turn create object


// client --> Abtract factory  --> Factory1,Factory2 ====> actual object class (concrete class)




// Light Vehicles

class Vehicle {
public:
	virtual void printInfo() = 0;
};

class  Motorbike: public Vehicle {
public:
	void printInfo() {
		cout << "This is a Motorbike\n";
	}
};

class Car: public Vehicle {
public:
	void printInfo() {
		cout << "This is a Car\n";
	}
};

class Auto: public Vehicle {
public:
	void printInfo() {
		cout << "This is an Auto\n";
	}
};


// Heavy vehicles

class Truck: public Vehicle {
public:
	void printInfo() {
		cout << "This is a Truck\n";
	}
};

class Bus: public Vehicle {
public:
	void printInfo() {
		cout << "This is a Bus\n";
	}
};

class Helicopter: public Vehicle {
public:
	void printInfo() {
		cout << "This is a Helicopter\n";
	}
};


// Factory 1
class LightVehicleFactory {
public:
	Vehicle* BuildLightWeightVehicle(int wheel) {
		if (wheel == 2) {
			return new Motorbike();
		}
		else if (wheel == 3) {
			return new Auto();
		}
		else if (wheel == 4) {
			return new Car();
		}
		else {
			return NULL;
		}
	}
};
// Factory 2
class HeavyVehicleFactory {
public:
	Vehicle* BuildHeavyWeightVehicle(int wheel) {
		if (wheel == 4) {
			return new Bus();
		}
		else if (wheel == 8) {
			return new Truck();
		}
		else if (wheel == 0) {
			return new Helicopter();
		}
		else {
			return NULL;
		}
	}
};


// Abstract Factory

class vehicleFactory {
public:

	Vehicle* buildVehicle(string cat, int wheelNumber) {
		if (cat == "LightWeight") {
			return (new LightVehicleFactory())->BuildLightWeightVehicle(wheelNumber);
		}
		else if (cat == "HeavyWeight") {
			return (new HeavyVehicleFactory())->BuildHeavyWeightVehicle(wheelNumber);
		}
		else return NULL;
	}
};




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	Vehicle* myVehicle = (new vehicleFactory())->buildVehicle("HeavyWeight", 0);
	if (myVehicle) myVehicle->printInfo();
	else cout << "No sunch Vehicle exist!\n";
}