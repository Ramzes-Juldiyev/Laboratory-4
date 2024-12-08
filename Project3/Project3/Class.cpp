#include "Class.h"
#include <vector>
#include <sstream>
using namespace std;
// Tariff class methods
Tariff::Tariff(Direction direction, double price, int id) : direction(direction), price(price), id(id) {}
Direction Tariff::getDirection() const { return direction; }
double Tariff::getPrice() const { return price; }
int Tariff::getId() const { return id; }

// Passenger class methods
Passenger::Passenger(std::string passportNumber, std::string name, std::string surname, int id)
    : passportNumber(passportNumber), name(name), surname(surname), id(id) {
}
std::string Passenger::getPassportNumber() const { return passportNumber; }
std::string Passenger::getName() const { return name; }
std::string Passenger::getSurname() const { return surname; }
int Passenger::getId() const { return id; }

// Ticket class methods
Ticket::Ticket(Tariff tariff, Passenger passenger, int id) : tariff(tariff), passenger(passenger), id(id) {}
Tariff Ticket::getTariff() const { return tariff; }
Passenger Ticket::getPassenger() const { return passenger; }
int Ticket::getId() const { return id; }

// Airport class methods
Airport& Airport::getInstance() {
    static Airport instance;
    return instance;
}

Airport::Airport() : nextTariffId(1), nextPassengerId(1), nextTicketId(1), totalSales(0.0) {}

void Airport::addTariff(Tariff tariff) {
    tariffs.push_back(tariff);
}

void Airport::sellTicket(Passenger passenger, Tariff tariff) {
    Ticket ticket(tariff, passenger, nextTicketId++);
    tickets.push_back(ticket);
    passengerTickets[passenger.getId()].push_back(ticket);
}

double Airport::getTotalSpentByPassenger(int passengerId) {
    double total = 0;
    for (const auto& ticket : passengerTickets[passengerId]) {
        total += ticket.getTariff().getPrice();
    }
    return total;
}

double Airport::getTotalSalesByPassportNumber(const std::string& passportNumber) {
    double total = 0;
    for (const auto& ticket : tickets) {
        if (ticket.getPassenger().getPassportNumber() == passportNumber) {
            total += ticket.getTariff().getPrice();
        }
    }
    return total;
}

double Airport::getTotalSalesByPassengerId(int passengerId) {
    return getTotalSpentByPassenger(passengerId);
}

double Airport::getTotalSales() {
    double total = 0;
    for (const auto& ticket : tickets) {
        total += ticket.getTariff().getPrice();
    }
    return total;
}

void Airport::reset() {
    tariffs.clear();
    tickets.clear();
    nextTariffId = 1;
    nextPassengerId = 1;
    nextTicketId = 1;
    totalSales = 0.0;
}

int Airport::getNextTariffId() {
    return nextTariffId;
}

int Airport::getNextPassengerId() {
    return nextPassengerId;
}

Tariff Airport::findTariffByDirection(Direction direction) {
    for (const auto& tariff : tariffs) {
        if (tariff.getDirection() == direction) {
            return tariff;
        }
    }
    Tariff newTariff(direction, 0, nextTariffId++);
    addTariff(newTariff);
    return newTariff;
}

/*void Airport::printAllTariffs() {
    std::cout << "All Tariffs:" << std::endl;
    for (const auto& tariff : tariffs) {
        std::cout << "Direction: ";
        switch (tariff.getDirection()) {
        case Direction::Domestic:
            std::cout << "Domestic";
            break;
        case Direction::International:
            std::cout << "International";
            break;
        case Direction::Regional:
            std::cout << "Regional";
            break;
        }
        std::cout << ", Price: " << tariff.getPrice() << ", ID: " << tariff.getId() << std::endl;
    }
}

void Airport::printAllPassengers() {
    std::cout << "All Passengers:" << std::endl;
    for (const auto& ticket : tickets) {
        std::cout << "Passport Number: " << ticket.getPassenger().getPassportNumber() << ", Name: " << ticket.getPassenger().getName() << ", Surname: " << ticket.getPassenger().getSurname() << std::endl;
        std::cout << "Tariff: ";
        switch (ticket.getTariff().getDirection()) {
        case Direction::Domestic:
            std::cout << "Domestic";
            break;
        case Direction::International:
            std::cout << "International";
            break;
        case Direction::Regional:
            std::cout << "Regional";
            break;
        }
        std::cout << ", Price: " << ticket.getTariff().getPrice() << std::endl;
    }

}*/
std::vector<std::string> Airport::getAllTariffsAsList() {
    std::vector<std::string> list;
    list.push_back("All Tariffs:");
    for (const auto& tariff : tariffs) {
        std::ostringstream line;
        line << "Direction: ";
        switch (tariff.getDirection()) {
        case Direction::Domestic:
            line << "Domestic";
            break;
        case Direction::International:
            line << "International";
            break;
        case Direction::Regional:
            line << "Regional";
            break;
        }
        line << ", Price: " << tariff.getPrice() << ", ID: " << tariff.getId();
        list.push_back(line.str());
    }
    return list;
}

std::vector<std::string> Airport::getAllPassengersAsList() {
    std::vector<std::string> list;
    list.push_back("All Passengers:");
    for (const auto& ticket : tickets) {
        std::ostringstream line1, line2;
        line1 << "Passport Number: "
            << ticket.getPassenger().getPassportNumber()
            << ", Name: " << ticket.getPassenger().getName()
            << ", Surname: " << ticket.getPassenger().getSurname();
        list.push_back(line1.str());

        line2 << "Tariff: ";
        switch (ticket.getTariff().getDirection()) {
        case Direction::Domestic:
            line2 << "Domestic";
            break;
        case Direction::International:
            line2 << "International";
            break;
        case Direction::Regional:
            line2 << "Regional";
            break;
        }
        line2 << ", Price: " << ticket.getTariff().getPrice();
        list.push_back(line2.str());
    }
    return list;
}
