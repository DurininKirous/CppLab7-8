#ifndef Customer_h
#define Customer_h
#include "BankAccount.h"
#include <iostream>
#include <string>
class Customer
{
	std::string FirstName;
	std::string LastName;
	int Password;
	CheckingAccount* ListOfCheckingAccounts;
	SavingsAccount* ListOfSavingsAccounts;
	int NumberOfCheckingAccounts;
	int NumberOfSavingsAccounts;
public:
	Customer();
	Customer(std::string FirstName, std::string LastName, int Password, int NumberOfCheckingAccounts, int NumberOfSavingsAccounts);
	Customer(std::string FirstName, std::string LastName);
	~Customer();
	void AddCheckingAccount();
	void AddSavingsAccount();
	void AddSavingsAccount(double Deposit);
	CheckingAccount& GetCheckingAccountFromList(int index);
	SavingsAccount& GetSavingsAccountFromList(int index);
	void Print();
	void PrintOneCheckingAccount(int index);
	void PrintOneSavingsAccount(int index);
	std::string GetName();
	int GetNumberOfCheckingAccounts();
	int GetNumberOfSavingsAccounts();
	CheckingAccount* GetListOfCheckingAccounts();
	SavingsAccount* GetListOfSavingsAccounts();
}; 
#endif //Customer_h