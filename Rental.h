// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include <sstream>
#include <vector>
#include "Movie.h"
#include "Customer.h"

class State;
class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;
    double getAmmount() ;
    std::string getFigures() ;
    int getFrequentRenterPoint() const;
    void setCurrent(State *s);
    double children() ;
    double regular() ;
    double newRelease() ;
private:
    Movie _movie;
    int _daysRented;
    State *current;
};

class State
{
public :
    virtual double regular(Rental *r) {
    }

    virtual double newRelease(Rental *r) {
    }

    virtual double children(Rental *r) {
    }
};





#endif // RENTAL_H