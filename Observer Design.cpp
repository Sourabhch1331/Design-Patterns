#include<iostream>
#include<list>
using namespace std;


// There are 2 main components in the Observer design pattern
// 1) Observable
// 2) Observer

//Here the observer observes the observable, if there is any change in data in the observable then
// observable notify all observer that it stores in a list


// example: Walmart interview problem
// Design a Notify Me Functionality

// interface
class NotificationAlertObserver {
public:
	virtual void update() = 0;
};

// Interface
class StockObservable {
public:
	virtual void registerObserver(NotificationAlertObserver* observer) = 0;
	virtual void unregisterObserver(NotificationAlertObserver* observer) = 0;
	virtual void notifySubscribers() = 0;
	virtual int getStockCount() = 0;
	virtual void setStockCount(int newStockCount) = 0;
};

class IPhoneObservable: public StockObservable {
public:
	list<NotificationAlertObserver*> *observerList;
	int stockCount;

	IPhoneObservable() {
		observerList = new list<NotificationAlertObserver*>();
		this->stockCount = 0;
	}

	void registerObserver(NotificationAlertObserver* observer) {
		observerList->push_back(observer);
	}

	void unregisterObserver(NotificationAlertObserver* observer) {
		observerList->remove(observer);
	}

	void notifySubscribers() {
		for (NotificationAlertObserver* observer : *observerList) {
			observer->update();
		}
	}

	void setStockCount(int newStockCount) {
		if (stockCount == 0) {
			stockCount = newStockCount;
			notifySubscribers();
		}
		else stockCount += newStockCount;
	}

	int getStockCount() {
		return stockCount;
	}
};


// Diffrent Observer implementing NotificationAlertObserver

class EmailAlertObserver: public NotificationAlertObserver {
public:
	StockObservable* observable;
	string emailId;

	EmailAlertObserver(StockObservable* observable, string emailId) {
		this->observable = observable;
		this->emailId = emailId;
	}

	void update() {
		sendMail();
	}

private:
	void sendMail() {
		cout << "Mail: Item is available in stock, Hurry up!\n";
		cout << "Total " << observable->getStockCount() << " Items available.\n";
		cout << "Mail sent to emailId:" << emailId << '\n';
		cout << '\n';
	}
};

class TextMessageObserver: public NotificationAlertObserver {
public:
	StockObservable* observable;
	string phoneNumber;

	TextMessageObserver(StockObservable* observable, string phoneNumber) {
		this->observable = observable;
		this->phoneNumber = phoneNumber;
	}
	void update() {
		sendTextMessage();
	}

private:
	void sendTextMessage() {
		cout << "Message: Item is available in stock, Hurry up!\n";
		cout << "Total " << observable->getStockCount() << " Items available.\n";
		cout << "Message sent to phoneNumber:" << phoneNumber << '\n';
		cout << '\n';
	}
};



int main() {
	StockObservable* iPhoneObservable = new IPhoneObservable();

	NotificationAlertObserver* customer1 = new EmailAlertObserver(iPhoneObservable, "sourabhchxyz@gmail.com");
	NotificationAlertObserver* customer2 = new TextMessageObserver(iPhoneObservable, "881757xxxx");

	iPhoneObservable->registerObserver(customer1);
	iPhoneObservable->registerObserver(customer2);

	iPhoneObservable->setStockCount(10);
	iPhoneObservable->setStockCount(-10);

	iPhoneObservable->unregisterObserver(customer1);


	iPhoneObservable->setStockCount(1);
}
