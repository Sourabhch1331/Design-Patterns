#include<iostream>
using namespace std;


// Decorator pattern is used when we want add extensions to functionalities of base class object,
// it is different from builder pattern as builder pattern allows to create object with combination if different attributes
// but in decorator, we first have a base object and we decorate it later with additional functionalities

// eg we first create a base pizza then only we can add topings

// This is perfect example of Open closed principle
// here toppings are extending the capability of parent class(open for extension), but not narrowing down(closed for modification)


// Abstract class
class BasePizza {
public:
	virtual int cost() = 0;
};

// Abstract class
class ToppingsDecorator: public BasePizza {
public:
	virtual int cost() = 0;
};

class Margharita: public BasePizza {
public:
	int cost() {
		return 100;
	}
};

class PeppyPaneer: public BasePizza {
public:
	int cost() {
		return 150;
	}
};

class VegiDelite: public BasePizza {
public:
	int cost() {
		return 120;
	}
};


class ExtraCheese: public ToppingsDecorator {
public:
	BasePizza* basePizza;

	ExtraCheese(BasePizza* basePizza): basePizza(basePizza) {}

	int cost() {
		return basePizza->cost() + 30;
	}
};

class Paneer: public ToppingsDecorator {
public:
	BasePizza* basePizza;

	Paneer(BasePizza* basePizza): basePizza(basePizza) {}

	int cost() {
		return basePizza->cost() + 40;
	}
};

class Jalapeno: public ToppingsDecorator {
public:
	BasePizza* basePizza;

	Jalapeno(BasePizza* basePizza): basePizza(basePizza) {}

	int cost() {
		return basePizza->cost() + 20;
	}
};

class Capsicum: public ToppingsDecorator {
public:
	BasePizza* basePizza;

	Capsicum(BasePizza* basePizza): basePizza(basePizza) {}

	int cost() {
		return basePizza->cost() + 25;
	}
};


int main() {
	BasePizza* myPizza = new ExtraCheese(new Paneer(new VegiDelite()));

	cout << "The cost of final pizza with/without toppings is:\n";
	cout << myPizza->cost() << '\n';

}