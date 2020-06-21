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

    virtual int getDaysRented() const;
    virtual const Movie& getMovie() const;
    virtual double getAmmount() ;
    virtual std::string getFigures() ;
    virtual int getFrequentRenterPoint() const;
    virtual void setCurrent(State *s);
    virtual double children() ;
    virtual double regular() ;
    virtual double newRelease() ;
private:
    const Movie& _movie;
    int _daysRented;
    State *current;
};

class State
{
public :
    virtual double regular(Rental *r) {
        return 0;
    }

    virtual double newRelease(Rental *r) {
        return 0;
    }

    virtual double children(Rental *r) {
        return 0;
    }
};





#endif // RENTAL_H