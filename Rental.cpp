//
// Created by Pierre-Olivier on 21.06.2020.
//

#include "Rental.h"
#include "NewRelease.h"
#include "Children.h"
#include "Regular.h"

Rental::Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {
}

int Rental::getDaysRented() const { return _daysRented; }

const Movie& Rental::getMovie() const { return _movie; }

double Rental::children() {
    setCurrent(new Children());
    return current->children(this);
}

double Rental::newRelease() {
    setCurrent(new NewRelease());
    return current->newRelease(this);
}

double Rental::regular() {
    setCurrent(new Regular());
    return current->regular(this);
}

double Rental::getAmmount() {
    double (Rental::*ptrs[])() = {
      &Rental::regular, &Rental::newRelease, &Rental::children
    };

    return (this->*ptrs[_movie.getPriceCode()])();
}

std::string Rental::getFigures() {
    std::ostringstream result;

    result << "\t" << _movie.getTitle() << "\t"
           << getAmmount() << "\n";

    return result.str();
}

int Rental::getFrequentRenterPoint() const {
    return 1 + ((_movie.getPriceCode() == Movie::NEW_RELEASE && _daysRented > 1) ? 1 : 0);
}

void Rental::setCurrent(State *s) {
    current = s;
}
