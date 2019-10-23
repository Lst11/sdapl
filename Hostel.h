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
};

#endif //TRAVELAGENTASSISTANT_HOSTEL_H
