#include "tour.h"

#include <iostream>
#include <QDate>
#include "tour.h"

using namespace std;

Tour::Tour() {}

Tour::Tour(const User &user, int hostelId, int flightId, int nightCounter, int personCounter)
        : user(user), hostelId(hostelId), flightId(flightId), nightCounter(nightCounter),
          personCounter(personCounter) {}


Tour::~Tour() {
    cout << "Destructor for Tour\n";
}

const User &Tour::getUser() const {
    return user;
}

void Tour::setUser(const User &user) {
    Tour::user = user;
}

int Tour::getHostelId() const {
    return hostelId;
}

void Tour::setHostelId(int hostelId) {
    Tour::hostelId = hostelId;
}

int Tour::getFlightId() const {
    return flightId;
}

void Tour::setFlightId(int flightId) {
    Tour::flightId = flightId;
}

int Tour::getNightCounter() const {
    return nightCounter;
}

void Tour::setNightCounter(int nightCounter) {
    Tour::nightCounter = nightCounter;
}

int Tour::getPersonCounter() const {
    return personCounter;
}

void Tour::setPersonCounter(int personCounter) {
    Tour::personCounter = personCounter;
}
