#include "tour.h"

#include <iostream>
#include <QDate>
#include <QString>
#include "tour.h"
#include <QDebugStateSaver>

using namespace std;

Tour::Tour() {}

Tour::~Tour() {
    qDebug() << "Destructor for Tour";
}

const User *Tour::getUser() const {
    return user;
}

void Tour::setUser(User *user) {
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

QDebug operator<<(QDebug debug, const Tour *tour) {
    debug.nospace() << "Tour: " << tour->getUser() << " hostelId: " << tour->getHostelId()
                    << " flightId: " << tour->getFlightId() << " nightCounter: "
                    << tour->getNightCounter() << " personCounter: " << tour->getPersonCounter();
    return debug.space();
}
