#include "user.h"

User::User() {}

User::User(const string &name, const string &surname, const string &phone) : name(name), surname(surname),
                                                                             phone(phone) {}

User::~User() {
    cout << "Destructor for User\n";
}

int User::getId() const {
    return id;
}

void User::setId(int id) {
    User::id = id;
}

const string &User::getName() const {
    return name;
}

void User::setName(const string &name) {
    User::name = name;
}

const string &User::getSurname() const {
    return surname;
}

void User::setSurname(const string &surname) {
    User::surname = surname;
}

const string &User::getPhone() const {
    return phone;
}

void User::setPhone(const string &phone) {
    User::phone = phone;
}

QDebug operator<<(QDebug debug, const User *user) {
    QString name = QString::fromUtf8((user->getName()).c_str());
    QString surname = QString::fromUtf8((user->getSurname()).c_str());
    QString phone = QString::fromUtf8((user->getPhone()).c_str());

    debug.nospace() << "User: name: " << name << " surname: " << surname << " phone: " << phone;
    return debug.space();
}
