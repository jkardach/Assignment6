//
//  Composer.hpp
//  Assignment6
//
//  5/27/21.
//

#ifndef Composer_hpp
#define Composer_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Composer {
private:
    string name = "";
    int deathYear = 0;
public:
    Composer();
    Composer(string name, int year);
//    ~Composer();
//    Composer(const Composer &obj);  // copy constructor
    void setName(string name);  // sets composers name
    string getName() const;     // gets composers name
    void setYear(int year);     // sets year of death
    int getYear() const;        // gets year of death
    
    
    const Composer& operator= (const Composer &right);
    bool operator<(const Composer &right) const;
    bool operator==(const Composer &right) const;
    bool operator!=(const Composer &right) const;
    friend ostream& operator<<(ostream &out, const Composer &right);
    
};


#endif /* Composer_hpp */
