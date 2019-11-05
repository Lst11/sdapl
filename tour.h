#ifndef TOUR_H
#define TOUR_H

#include "user.h"
#include "QDate"


class Tour {

private:
    User user;
    int hostelId;
    int flightId;
    int nightCounter;
    int personCounter;

public:
    Tour();

    Tour(const User &user, int hostelId, int flightId, int nightCounter, int personCounter);

    virtual ~Tour();

    const User &getUser() const;

    void setUser(const User &user);

    int getHostelId() const;

    void setHostelId(int hostelId);

    int getFlightId() const;

    void setFlightId(int flightId);

    int getNightCounter() const;

    void setNightCounter(int dateFrom);

    int getPersonCounter() const;

    void setPersonCounter(int personCounter);
};

#endif // TOUR_H
