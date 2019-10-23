//
// Created by 1 on 20.10.2019.
//

#include "Hostel.h"
#include <iostream>
#include <utility>

using namespace std;

Hostel::Hostel(string name, int costPerNight, string country, string city) : name(std::move(name)),
                                                                                costPerNight(
                                                                                        costPerNight),
                                                                                country(std::move(country)),
                                                                                city(std::move(city)) {}

void Hostel::show()
{
    cout << "The name of the hostel is: ";
    cout << name;
    cout << "\nThe cost per night is: ";
    cout << costPerNight;
    cout << "\nThe country is: ";
    cout << country;
    cout << "\nThe city is: ";
    cout << city << "\n";
}

Hostel::~Hostel()
{
    cout << "Destructor for Hostel\n";
}


