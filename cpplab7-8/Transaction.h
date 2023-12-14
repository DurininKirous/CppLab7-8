#ifndef Transaction_h
#define Transaction_h
#include "Customer.h"
class Transaction
{
	Customer Client;
public:
	Transaction(Customer Client);
	Transaction();
	void TransferMoneyToAnotherPerson(Customer Recipient);
	void TransferMoneyToAMobilePhoneNumber(size_t MobilePhoneNumber);
	void MakeADepositWithInterest();
	void WithdrawMoney();
};
#endif //Transaction_h