//
// Created by janis on 21.06.2020.
//
#ifndef GEN_LABO05_CHILDREN_H
#define GEN_LABO05_CHILDREN_H


#include "Rental.h"

class Children : public State {
    double children(Rental *r) {
        double result = 1.5;
        if ( r->getDaysRented() > 3 )
            result += ( r->getDaysRented() - 3 ) * 1.5;
        return result;
    }
};

#endif