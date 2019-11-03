#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

using namespace std;

class Flight {
private:
    string toCountry;
    string fromCountry;
    double price;
public:
    Flight(const string &toCountry, const string &fromCountry, double price);

    virtual ~Flight();

    void show();

    const string &getToCountry() const;

    void setToCountry(const string &toCountry);

    const string &getFromCountry() const;

    void setFromCountry(const string &fromCountry);

    double getPrice() const;

    void setPrice(double price);

};

#endif // FLIGHT_H
