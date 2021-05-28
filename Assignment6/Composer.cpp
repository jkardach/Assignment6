//
//  Composer.cpp
//  Assignment6
//
//  5/27/21.
//

#include "Composer.hpp"
Composer::Composer():name(""), deathYear(0) {}
Composer::Composer(string name, int year): name(name), deathYear(year) {}
// destructor
//Composer::~Composer() {}

// copy constructor
//Composer::Composer(const Composer &obj) {
//    name = obj.name;
//    deathYear = obj.deathYear;
//}

// sets composers name
void Composer::setName(string name) {
    this->name = name;
}

// gets composers name
string Composer::getName() const {
    return this->name;
}

// sets year of death
void Composer::setYear(int year) {
    this->deathYear = year;
}

// gets year of death
int Composer::getYear() const {
    return this->deathYear;
}

// assignment overloaded
const Composer& Composer::operator=(const Composer &right) {
    this->name = right.name;
    this->deathYear = right.deathYear;
    return *this;
}

// overload "<" checks the years of death
bool Composer::operator<(const Composer &right) const {
    return (deathYear < right.deathYear);
}


// determines if two Composer names are not equal
bool Composer::operator!=(const Composer &right) const {
    return (name != right.name) ? true : false;
}

// determines if two Composer names are equal
bool Composer::operator==(const Composer &right) const {
    return (name == right.name) ? true : false;
}

// overloaded out operator, creates "composerName, year" output
ostream& operator<<(ostream &out, const Composer &right) {
    out << right.name << " - " << right.getYear() << endl;
    return out;
}
