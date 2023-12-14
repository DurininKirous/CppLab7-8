#ifndef BankAccount_h
#define BankAccount_h
class BankAccount 
{
protected:
	double Cash;
	size_t AccountNumber;
public:
	BankAccount(double Cash, size_t AccountNumber);
	BankAccount();
	virtual void Print();
	void ShowTheCurrentBalance();
	void ShowTheAccountNumber();
	void SetTheCash(double Cash);
	void SetTheAccountNumber(size_t AccountNumber);
};
class CheckingAccount : public BankAccount
{
private:
	int CVV;
public:
	void Print();
	double& GetCash();
	CheckingAccount();
	CheckingAccount(double Cash, size_t AccountNumber, int CVV);
	void ShowTheCVVNumber();
	void SetTheCVV(int CVV);
	bool operator ==(CheckingAccount Account);
};
class SavingsAccount : public BankAccount
{
private:
	double DepositRate;
public:
	void Print();
	SavingsAccount();
	SavingsAccount(double Cash, size_t AccountNumber, double DepositRate);
	void ShowThePercentageOfTheDeposit();
	void SetTheDepositRate(double DepositRate);
	bool operator ==(SavingsAccount Account);
};
#endif //BankAccount_h