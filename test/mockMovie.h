//
// Created by janis on 21.06.2020.
//

#ifndef GEN_LABO05_MOCKMOVIE_H
#define GEN_LABO05_MOCKMOVIE_H

#include "gmock/gmock.h"  // Brings in gMock.
#include "../Movie.h"

class mockMovie : public Movie {
public:
    MOCK_CONST_METHOD0(getPriceCode, int());
    MOCK_METHOD1(setPriceCode, void(int arg));
    MOCK_CONST_METHOD0(getTitle, std::string());

    mockMovie(const std::string& title, int priceCode = REGULAR ) : Movie(title, priceCode) {}
    mockMovie() : Movie("", int()) {}
};

#endif //GEN_LABO05_MOCKMOVIE_H
