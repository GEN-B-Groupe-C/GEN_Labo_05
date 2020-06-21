// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include <sstream>
#include <vector>
#include "Movie.h"
#include "Customer.h"

class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;
    double getAmmount() const;
    std::string getFigures() const;
    int getFrequentRenterPoint() const;

private:
    Movie _movie;
    int _daysRented;
};
#endif // RENTAL_H