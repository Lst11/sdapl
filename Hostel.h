#ifndef TRAVELAGENTASSISTANT_HOSTEL_H
#define TRAVELAGENTASSISTANT_HOSTEL_H
#include <string>

using namespace std;

class Hostel
{

private:
    string name;
    int costPerNight;
    string country;
    string city;

public:

    Hostel(string name, int costPerNight, string country, string city);

    virtual ~Hostel();

    void show();

    const string &getName() const;

        void setName(const string &name);

        double getCostPerNight() const;

        void setCostPerNight(double costPerNight);

        const string &getCountry() const;

        void setCountry(const string &country);

        const string &getCity() const;

        void setCity(const string &city);

};

#endif //TRAVELAGENTASSISTANT_HOSTEL_H
