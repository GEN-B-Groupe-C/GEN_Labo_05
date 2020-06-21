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

inline Rental::
Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie& Rental::
getMovie() const { return _movie; }

inline double Rental::getAmmount() const {
    double result = 0;
    switch ( _movie.getPriceCode() ) {
        case Movie::REGULAR:
            result += 2;
            if ( _daysRented > 2 )
                result += ( _daysRented - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            result += _daysRented * 3;
            break;
        case Movie::CHILDRENS:
            result += 1.5;
            if ( _daysRented > 3 )
                result += ( _daysRented - 3 ) * 1.5;
            break;
    }
    return result;
}

inline std::string Rental::getFigures() const{
    std::ostringstream result;

    result << "\t" << _movie.getTitle() << "\t"
        << getAmmount() << "\n";

    return result.str();
}

inline int Rental::getFrequentRenterPoint() const {
    return 1 + ((_movie.getPriceCode() == Movie::NEW_RELEASE && _daysRented > 1) ? 1 : 0);
}

#endif // RENTAL_H