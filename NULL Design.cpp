#include<iostream>
using namespace std;

enum VehicleType
{
	CAR, TRUCK
};

class Vehicle {
public:
	virtual int getTankCapacity() = 0;
	virtual int getCountOfWheels() = 0;
	void PrintInfo() {
		cout << "Number of Wheels:\n";
		cout << this->getCountOfWheels() << '\n';


		cout << "Tank Capacity:\n";
		cout << this->getTankCapacity() << '\n';
	}
};


class Car: public Vehicle {
public:

	int getTankCapacity() {
		return 38;
	}

	int getCountOfWheels() {
		return 4;
	}
};

class Truck: public Vehicle {
public:

	int getTankCapacity() {
		return 150;
	}

	int getCountOfWheels() {
		return 8;
	}
};

class NULLVehicleObject: public Vehicle {
public:
	int getTankCapacity() {
		return -1;
	}

	int getCountOfWheels() {
		return -1;
	}
};

class VehicleFactory {
public:

	Vehicle* buildVehicle(string type) {
		if (type == "CAR")
			return new Car();
		if (type == "TRUCK")
			return new Truck();

		return new NULLVehicleObject();
	}

};



int main() {
	VehicleFactory* vehicleFactory = new VehicleFactory();

	Vehicle* myVehicle1 = vehicleFactory->buildVehicle("CAR");

	Vehicle* myVehicle2 = vehicleFactory->buildVehicle("TRUCK");

	Vehicle* myVehicle3 = vehicleFactory->buildVehicle("CHANDRAYAAN");

	myVehicle1->PrintInfo();
	myVehicle2->PrintInfo();
	myVehicle3->PrintInfo();

}