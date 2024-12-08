#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

enum class Direction {
    Domestic,
    International,
    Regional
};

class Tariff {
public:
    Tariff(Direction direction, double price, int id);
    Direction getDirection() const;
    double getPrice() const;
    int getId() const;

private:
    Direction direction;
    double price;
    int id;
};

class Passenger {
public:
    Passenger(std::string passportNumber, std::string name, std::string surname, int id);
    std::string getPassportNumber() const;
    std::string getName() const;
    std::string getSurname() const;
    int getId() const;

private:
    std::string passportNumber;
    std::string name;
    std::string surname;
    int id;
};

class Ticket {
public:
    Ticket(Tariff tariff, Passenger passenger, int id);
    Tariff getTariff() const;
    Passenger getPassenger() const;
    int getId() const;

private:
    Tariff tariff;
    Passenger passenger;
    int id;
};

class Airport {
public:
    static Airport& getInstance();
    void addTariff(Tariff tariff);
    void sellTicket(Passenger passenger, Tariff tariff);
    double getTotalSpentByPassenger(int passengerId);
    double getTotalSalesByPassportNumber(const std::string& passportNumber);
    double getTotalSalesByPassengerId(int passengerId);
    double getTotalSales();
    void reset();
    int getNextTariffId();
    int getNextPassengerId();
    Tariff findTariffByDirection(Direction direction);
    std::vector<std::string> getAllTariffsAsList();
    std::vector<std::string> getAllPassengersAsList();
    /*void printAllTariffs();
    void printAllPassengers();*/

private:
    Airport();
    std::vector<Tariff> tariffs;
    std::vector<Ticket> tickets;
    int nextTariffId;
    int nextPassengerId;
    int nextTicketId;
    double totalSales;
    std::map<int, std::vector<Ticket>> passengerTickets;
    Airport(const Airport&) = delete;
    Airport& operator=(const Airport&) = delete;
};

#endif // CLASS_H