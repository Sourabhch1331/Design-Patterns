#include<iostream>
using namespace std;



class Vehicle {
public:
	virtual void printVehicleInfo() = 0;
};


class TwoWheeler: public Vehicle {
public:
	void printVehicleInfo() {
		cout << "This is a TwoWheeler\n";
	}
};

class FourWheeler: public Vehicle {
public:
	void printVehicleInfo() {
		cout << "This is a FourWheeler\n";
	}
};



// client intract with only this class
// so client don't have to worry about how to create object
// even if the method to create object changes, client dosn't have to change
// it's code, we have to change in VehicleFactory only
// also concete classes are implementing
class VehicleFactory {
public:
	Vehicle* buildVehicle(string VehicleName) {
		if (VehicleName == "TwoWheeler")
			return new TwoWheeler();
		else if (VehicleName == "FourWheeler")
			return new FourWheeler();
		else
			return NULL;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	VehicleFactory* vf = new VehicleFactory();

	Vehicle* myvehicle = vf->buildVehicle("TwoWheeler");

	myvehicle->printVehicleInfo();
}