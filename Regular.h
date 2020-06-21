//
// Created by janis on 21.06.2020.
//
#ifndef GEN_LABO05_REGULAR_H
#define GEN_LABO05_REGULAR_H


#include "Rental.h"

class Regular : public State {
    double regular(Rental *r) {
        double result = 2;
        if ( r->getDaysRented() > 2 )
            result += ( r->getDaysRented() - 2 ) * 1.5 ;
        return result;
    }
};

#endif