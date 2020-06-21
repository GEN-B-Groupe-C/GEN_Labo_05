//
// Created by janis on 21.06.2020.
//

#ifndef GEN_LABO05_RENTALTEST_H
#define GEN_LABO05_RENTALTEST_H

#include "mockMovie.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../Rental.h"

using ::testing::Exactly;
using ::testing::Return;


TEST(RentalTest, rentalPointCalculCorrect) {
    int price = 0;
    mockMovie movie("test", price);

    EXPECT_CALL(movie, getPriceCode())
        .Times(Exactly(4))
        .WillOnce(Return(1))
        .WillOnce(Return(0))
        .WillOnce(Return(1))
        .WillOnce(Return(2));

    Rental r1(movie, 1);
    Rental r2(movie, 15);

    EXPECT_EQ(r1.getFrequentRenterPoint(), 1);
    EXPECT_EQ(r1.getFrequentRenterPoint(), 1);

    EXPECT_EQ(r2.getFrequentRenterPoint(), 2);
    EXPECT_EQ(r2.getFrequentRenterPoint(), 1);
}

#endif //GEN_LABO05_RENTALTEST_H
