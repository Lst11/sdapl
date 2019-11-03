#include "flight.h"

#include <iostream>

using namespace std;

Flight::Flight(const string &toCountry, const string &fromCountry, double price) : toCountry(toCountry),
                                                                                   fromCountry(fromCountry),
                                                                                   price(price) {}

Flight::~Flight() {
    cout << "Destructor for Flight\n";
}

void Flight::show() {
    cout << "To country: ";
    cout << toCountry;
    cout << "\nFrom country: ";
    cout << fromCountry;
    cout << "\nThe price is: ";
    cout << price << "\n";
}

const string &Flight::getToCountry() const {
    return toCountry;
}

void Flight::setToCountry(const string &toCountry) {
    Flight::toCountry = toCountry;
}

const string &Flight::getFromCountry() const {
    return fromCountry;
}

void Flight::setFromCountry(const string &fromCountry) {
    Flight::fromCountry = fromCountry;
}

double Flight::getPrice() const {
    return price;
}

void Flight::setPrice(double price) {
    Flight::price = price;
}


