#include <iostream>
#include <regex>
#include "Function.h"
#include "Class.h"
using namespace std;
Airport& airport = Airport::getInstance();
void printMenu() {

    
}

bool isValidName(const std::string& name) {
    // ���������, ��� ��� ������� ������ �� ���� � ��������
    return std::regex_match(name, std::regex("^[A-Za-z�-��-���\\s]+$"));
}

bool isValidPrice(double price) {
    return price > 0; // ���������, ��� ���� ������ ����
}

int getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear(); // ������� ����� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������������� ������������� �����
            std::cout << "Invalid input. Please enter a number." << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������ �����
            return value;
        }
    }
}

double getDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear(); // ������� ����� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������������� ������������� �����
            std::cout << "Invalid input. Please enter a number." << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������ �����
            return value;
        }
    }
}

void addTariff(double price, Direction direction) {
    Tariff tariff(direction, price, airport.getNextTariffId());
    airport.addTariff(tariff);
}

void sellTicket(string passportNumber, string name, string surname, Direction direction) {
    
    int passengerId = airport.getNextPassengerId();
    Passenger passenger(passportNumber, name, surname, passengerId);
    Tariff tariff = airport.findTariffByDirection(direction);
    airport.sellTicket(passenger, tariff);
}

double getTotalSales(string passportNumber) {
        double totalSalesByPassenger = airport.getTotalSalesByPassportNumber(passportNumber);
        return totalSalesByPassenger;
}

void clearData(Airport& airport) {
        airport.reset();
}
