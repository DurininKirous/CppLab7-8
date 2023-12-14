#pragma once
#include <iostream>
#include "Customer.h"
#include "Transaction.h"
#include "menu.h"
int main()
{
    int NumberOfUsers = 0;
    Customer* ListOfUsers = new Customer[1];
    menu(NumberOfUsers, ListOfUsers);
    delete[] ListOfUsers;
}
