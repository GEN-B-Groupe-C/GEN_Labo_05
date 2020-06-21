//
// Created by janis on 21.06.2020.
//

#ifndef GEN_LABO05_NEWRELEASE_H
#define GEN_LABO05_NEWRELEASE_H

#include "Rental.h"

class NewRelease : public State {
public:
    double newRelease(Rental *r) {
        r->setCurrent(new NewRelease());
        return r->getDaysRented() * 3;
    }
};

#endif //GEN_LABO05_NEWRELEASE_H
