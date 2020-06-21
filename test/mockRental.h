//
// Created by janis on 21.06.2020.
//

#ifndef GEN_LABO05_MOCKRENTAL_H
#define GEN_LABO05_MOCKRENTAL_H

#include "gmock/gmock.h"  // Brings in Google Mock.

#include "../Rental.h"
#include "mockMovie.h"

class mockRental : Rental {
private :
    mockMovie movie;
public :
    MOCK_CONST_METHOD0(getMovie, const mockMovie&());
    MOCK_CONST_METHOD0(getDaysRented, int());
    MOCK_METHOD0(children, double());
    MOCK_METHOD0(newRelease, double());
    MOCK_METHOD0(regular, double());
    MOCK_METHOD0(getAmmount, double());
    MOCK_METHOD0(getFigures, std::string());
    MOCK_CONST_METHOD0(getFrequentRenterPoint, int());

    mockRental(const mockMovie& movie, int days) : Rental(movie, days) {}
    mockRental() : Rental(movie, int()) {}
};

#endif //GEN_LABO05_MOCKRENTAL_H
