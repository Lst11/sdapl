#ifndef TOUR_H
#define TOUR_H

#include "user.h"
#include "QDate"
#include "QTextStream"


class Tour {

private:
    User *user;
    int hostelId;
    int flightId;
    int nightCounter;
    int personCounter;

public:
    Tour();

    virtual ~Tour();

    const User *Tour::getUser() const;

    void Tour::setUser(User *user);

    int getHostelId() const;

    void setHostelId(int hostelId);

    int getFlightId() const;

    void setFlightId(int flightId);

    int getNightCounter() const;

    void setNightCounter(int dateFrom);

    int getPersonCounter() const;

    void setPersonCounter(int personCounter);

    friend QDebug operator<<(QDebug debug, const Tour *tour);
};

#endif // TOUR_H
