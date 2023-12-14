#include "Customer.h"
Customer::Customer(std::string FirstName, std::string LastName, int Password, int NumberOfCheckingAccounts, int NumberOfSavingsAccounts) :
	FirstName(FirstName),
	LastName(LastName),
	Password(Password),
	ListOfCheckingAccounts(nullptr),
	ListOfSavingsAccounts(nullptr),
	NumberOfCheckingAccounts(NumberOfCheckingAccounts),
	NumberOfSavingsAccounts(NumberOfSavingsAccounts)
{
	ListOfCheckingAccounts = new CheckingAccount[NumberOfCheckingAccounts];
	ListOfSavingsAccounts = new SavingsAccount[NumberOfSavingsAccounts];
}
Customer::Customer(): FirstName("Unknown"),LastName("Unknown"), Password(0), ListOfCheckingAccounts(nullptr), ListOfSavingsAccounts(nullptr), NumberOfCheckingAccounts(0), NumberOfSavingsAccounts(0) {}
Customer::Customer(std::string FirstName, std::string LastName):
	FirstName(FirstName), 
	LastName(LastName), 
	ListOfCheckingAccounts(nullptr),
	ListOfSavingsAccounts(nullptr),
	NumberOfCheckingAccounts(0),
	NumberOfSavingsAccounts(0)
{}
Customer::~Customer()
{
	delete[] ListOfCheckingAccounts;
	delete[] ListOfSavingsAccounts;
}
void Customer::AddCheckingAccount()
{
	std::cout << "Type the password. You have 3 attempts!";
	int Attempt;
	int RemainingAttempts = 2;
	std::cin >> Attempt;
	while (Attempt != Password)
	{
		if (RemainingAttempts == 0) 
		{
			std::cerr << "You've run out of attempts! The operation was rejected.\n";
			return;
		}
		std::cerr << "Password is incorrect. You have " << RemainingAttempts-- << " attempts left. Try again!";
		std::cin >> Attempt;
	}
	CheckingAccount* NewList = new CheckingAccount[NumberOfCheckingAccounts + 1];
	int Cash; size_t AccountNumber;
	int CVV;
	CheckingAccount NewAccount;
	std::cout << "Enter the cash:";
	std::cin >> Cash; NewAccount.SetTheCash(Cash);
	std::cout << "Enter the Account Number:";
	std::cin >> AccountNumber; NewAccount.SetTheAccountNumber(AccountNumber);
	std::cout << "Enter the CVV:";
	std::cin >> CVV; NewAccount.SetTheCVV(CVV);
	NewList[NumberOfCheckingAccounts] = NewAccount;
	if (NumberOfCheckingAccounts != 0) 
	{
		for (int i = 0; i < NumberOfCheckingAccounts; i++)
		{
			NewList[i] = ListOfCheckingAccounts[i];
		}
		delete[] ListOfCheckingAccounts;
	}
	ListOfCheckingAccounts = NewList;
	NumberOfCheckingAccounts += 1;
}
void Customer::AddSavingsAccount()
{
	std::cout << "Type the password. You have 3 attempts!";
	int Attempt;
	int RemainingAttempts = 2;
	std::cin >> Attempt;
	while (Attempt != Password)
	{
		if (RemainingAttempts == 0)
		{
			std::cerr << "You've run out of attempts! The operation was rejected.\n";
			return;
		}
		std::cerr << "Password is incorrect. You have " << RemainingAttempts-- << " attempts left. Try again!";
		std::cin >> Attempt;
	}
	SavingsAccount* NewList = new SavingsAccount[NumberOfSavingsAccounts + 1];
	int Cash;size_t AccountNumber;
	double DepositRate;
	SavingsAccount NewAccount;
	std::cout << "Enter the cash:";
	std::cin >> Cash; NewAccount.SetTheCash(Cash);
	while (Cash < 0)
	{
		std::cerr << "Error. The value must be greater than zero\n";
		std::cin >> Cash;
	}
	std::cout << "Enter the Account Number:";
	std::cin >> AccountNumber; 
	while (AccountNumber < 0)
	{
		std::cerr << "Error. The number must be greater than zero\n";
		std::cin >> AccountNumber;
	}
	NewAccount.SetTheAccountNumber(AccountNumber);
	std::cout << "Enter the deposit rate:";
	std::cin >> DepositRate; 
	while (DepositRate < 0)
	{
		std::cerr << "Error. The deposit rate must be greater than zero\n";
		std::cin >> DepositRate;
	}
	NewAccount.SetTheDepositRate(DepositRate);
	NewList[NumberOfSavingsAccounts] = NewAccount;
	if (NumberOfSavingsAccounts != 0)
	{
		for (int i = 0; i < NumberOfSavingsAccounts; i++)
		{
			NewList[i] = ListOfSavingsAccounts[i];
		}
		delete[] ListOfSavingsAccounts;
	}
	ListOfSavingsAccounts = NewList;
	NumberOfSavingsAccounts += 1;
}
void Customer::AddSavingsAccount(double Deposit)
{
	std::cout << "Type the password. You have 3 attempts!";
	int Attempt;
	int RemainingAttempts = 2;
	std::cin >> Attempt;
	while (Attempt != Password)
	{
		if (RemainingAttempts == 0)
		{
			std::cerr << "You've run out of attempts! The operation was rejected.\n";
			return;
		}
		std::cerr << "Password is incorrect. You have " << RemainingAttempts-- << " attempts left. Try again!";
		std::cin >> Attempt;
	}
	SavingsAccount* NewList = new SavingsAccount[NumberOfSavingsAccounts + 1];
	int Cash; size_t AccountNumber;
	SavingsAccount NewAccount;
	std::cout << "Enter the cash:";
	std::cin >> Cash; 
	while (Cash<0) 
	{
		std::cerr << "Error. The value must be greater than zero\n";
		std::cin >> Cash;
	}
	NewAccount.SetTheCash(Cash);
	std::cout << "Enter the Account Number:";
	std::cin >> AccountNumber; 
	while (AccountNumber < 0)
	{
		std::cerr << "Error. The number must be greater than zero\n";
		std::cin >> AccountNumber;
	}
	NewAccount.SetTheAccountNumber(AccountNumber);
	NewAccount.SetTheDepositRate(Deposit);
	NewList[NumberOfSavingsAccounts] = NewAccount;
	if (NumberOfSavingsAccounts != 0)
	{
		for (int i = 0; i < NumberOfSavingsAccounts; i++)
		{
			NewList[i] = ListOfSavingsAccounts[i];
		}
		delete[] ListOfSavingsAccounts;
	}
	ListOfSavingsAccounts = NewList;
	NumberOfSavingsAccounts += 1;
}
CheckingAccount& Customer::GetCheckingAccountFromList(int index)
{
	return ListOfCheckingAccounts[index - 1];
}
SavingsAccount& Customer::GetSavingsAccountFromList(int index)
{
	return ListOfSavingsAccounts[index - 1];
}
void Customer::Print()
{
	std::cout << FirstName << " " << LastName << " Number of checking accounts:" << NumberOfCheckingAccounts << " Number of savings accounts:" << NumberOfSavingsAccounts << std::endl<<std::endl;
}
void Customer::PrintOneCheckingAccount(int index)
{
	(ListOfCheckingAccounts[index - 1]).Print();
}
void Customer::PrintOneSavingsAccount(int index)
{
	(ListOfSavingsAccounts[index - 1]).Print();
	std::cout << std::endl;
}
std::string Customer::GetName()
{
	return FirstName;
}
int Customer::GetNumberOfCheckingAccounts()
{
	return NumberOfCheckingAccounts;
}
int Customer::GetNumberOfSavingsAccounts()
{
	return NumberOfSavingsAccounts;
}
CheckingAccount* Customer::GetListOfCheckingAccounts()
{
	return ListOfCheckingAccounts;
}
SavingsAccount* Customer::GetListOfSavingsAccounts()
{
	return ListOfSavingsAccounts;
}