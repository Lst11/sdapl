#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User {

private:
    int id;
    string name;
    string surname;
    string phone;

public:

    User();

    User(const string &name, const string &surname, const string &phone);

    virtual ~User();

    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    const string &getPhone() const;

    void setPhone(const string &phone);
};

#endif // USER_H
