#include "Customer.h"
#include <iostream>
BankAccount::BankAccount(double Cash, size_t AccountNumber): Cash(Cash),AccountNumber(AccountNumber) {}
void BankAccount::ShowTheAccountNumber() { std::cout << AccountNumber; }
void BankAccount::ShowTheCurrentBalance() { std::cout << Cash; }
void BankAccount::SetTheAccountNumber(size_t AccountNumber) { this->AccountNumber = AccountNumber; }
void BankAccount::SetTheCash(double Cash) { this->Cash = Cash; }
void BankAccount::Print()
{
	std::cout << "Account Number: " << AccountNumber << std::endl
		<< "Cash: " << Cash << std::endl;
}
CheckingAccount::CheckingAccount() : BankAccount(0,0)
{
	this->CVV = 0;
}
CheckingAccount::CheckingAccount(double Cash, size_t AccountNumber, int CVV): BankAccount(Cash,AccountNumber)
{
	this->CVV = CVV;
}
void CheckingAccount::SetTheCVV(int CVV) { this->CVV = CVV; }
void CheckingAccount::ShowTheCVVNumber() { std::cout << CVV; }
void CheckingAccount::Print()
{
	std::cout << "Account Number: " << AccountNumber << std::endl
	<< "Cash: " << Cash << std::endl
	<< "CVV Number: " << CVV << std::endl;
}
double& CheckingAccount::GetCash()
{
	return Cash;
}
bool CheckingAccount::operator==(CheckingAccount Account)
{
	if (Cash == Account.Cash)
	{
		return true;
	}
	else
	{
		return false;
	}
}
SavingsAccount::SavingsAccount() : BankAccount(0,0)
{
	this->DepositRate = 0;
}
SavingsAccount::SavingsAccount(double Cash, size_t AccountNumber, double DepositRate): BankAccount(Cash,AccountNumber)
{
	this->DepositRate = DepositRate;
}
void SavingsAccount::ShowThePercentageOfTheDeposit() { std::cout << DepositRate; }
void SavingsAccount::SetTheDepositRate(double DepositRate) { this->DepositRate = DepositRate; }
void SavingsAccount::Print()
{
	std::cout << "Account Number: " << AccountNumber << std::endl
		<< "Cash: " << Cash << std::endl
		<< "Deposit Rate: " << DepositRate << std::endl;
}
bool SavingsAccount::operator==(SavingsAccount Account)
{
	if (Cash == Account.Cash && DepositRate == Account.DepositRate)
	{
		return true;
	}
	else
	{
		return false;
	}
}