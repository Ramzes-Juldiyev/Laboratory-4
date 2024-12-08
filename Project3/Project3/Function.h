#ifndef FUNCTION_H
#define FUNCTION_H

#include "Class.h"
#include "Class.h"
#include <string>
using namespace std;

void printMenu();
void addTariff(double price, Direction direction);
void sellTicket(string passportNumber, string name, string surname, Direction direction);
double getTotalSales(string passportNumber);
void clearData(Airport& airport);

#endif // FUNCTION_H
