#include<iostream>
using namespace std;



class MoneyWithdrawHandler {
public:
	MoneyWithdrawHandler* nextMoneyWithdrawHandler;
	int cntOfNotes;
	int currValue;
	MoneyWithdrawHandler(MoneyWithdrawHandler* nextMoneyWithdrawHandler, int cntOfNotes, int currValue) {
		this->nextMoneyWithdrawHandler = nextMoneyWithdrawHandler;
		this->cntOfNotes = cntOfNotes;
		this->currValue = currValue;
	}

	virtual bool handleMoneyReq(int amount) {
		if (nextMoneyWithdrawHandler != NULL) {
			return nextMoneyWithdrawHandler->handleMoneyReq(amount);
		}
		else {
			if (amount != 0) {
				cout << "Request can not be fullfilled!\n";
				return false;
			}
		}
		cout << "Success!\n";
		return true;
	}
};

class CurrValueHandler: public  MoneyWithdrawHandler {
public:
	CurrValueHandler(MoneyWithdrawHandler* next, int cntOfNotes, int currValue)
		: MoneyWithdrawHandler(next, cntOfNotes, currValue) {

	}

	bool handleMoneyReq(int amount) {

		if (amount < currValue || cntOfNotes == 0) {
			if (!MoneyWithdrawHandler::handleMoneyReq(amount))
				return false;

		}
		else {
			int currNotes = min(cntOfNotes, amount / currValue);
			int remAmount = amount - (currNotes * currValue);

			if (!MoneyWithdrawHandler::handleMoneyReq(remAmount)) {
				return false;
			}
			cntOfNotes -= currNotes;
			cout << currNotes << " Notes of " << currValue << '\n';

		}

		return true;
	}

};


int main() {
	MoneyWithdrawHandler* hundredValueHandler = new CurrValueHandler(NULL, 5, 100);
	MoneyWithdrawHandler* twoHundredValueHandler = new CurrValueHandler(hundredValueHandler, 1, 200);
	MoneyWithdrawHandler* fiveHundredValueHandler = new CurrValueHandler(twoHundredValueHandler, 4, 500);

	MoneyWithdrawHandler* moneyWithdrawHandler = new CurrValueHandler(fiveHundredValueHandler, 3, 2000);

	moneyWithdrawHandler->handleMoneyReq(3000);
	moneyWithdrawHandler->handleMoneyReq(3000);
	moneyWithdrawHandler->handleMoneyReq(50);
}