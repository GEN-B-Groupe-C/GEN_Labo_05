//
// Created by Pierre-Olivier on 21.06.2020.
//

#include "Rental.h"

Rental::Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

int Rental::getDaysRented() const { return _daysRented; }

const Movie& Rental::getMovie() const { return _movie; }

double Rental::getAmmount() const {
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

std::string Rental::getFigures() const{
    std::ostringstream result;

    result << "\t" << _movie.getTitle() << "\t"
           << getAmmount() << "\n";

    return result.str();
}

int Rental::getFrequentRenterPoint() const {
    return 1 + ((_movie.getPriceCode() == Movie::NEW_RELEASE && _daysRented > 1) ? 1 : 0);
}