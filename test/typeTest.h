//
// Created by janis on 21.06.2020.
//

#ifndef GEN_LABO05_TYPETEST_H
#define GEN_LABO05_TYPETEST_H

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "mockRental.h"
#include "mockMovie.h"

#include "../Rental.h"
#include "../Children.h"
#include "../Regular.h"
#include "../NewRelease.h"

using ::testing::Exactly;
using ::testing::Return;

TEST(typeTest, childrenTest) {
    int price = 0, day = 0;
    mockMovie movie("test", price);
    mockRental rental(movie, day);

    EXPECT_CALL(rental, getDaysRented())
            .Times(Exactly(3))
            .WillOnce(Return(2))
            .WillOnce(Return(5))
            .WillOnce(Return(5));


    Rental r1(movie, 2);
    Rental r2(movie, 5);
    Children c;

    EXPECT_EQ(c.children(&r1), 1.5);
    EXPECT_EQ(c.children(&r2), 4.5);
}

TEST(typeTest, regularTest) {
    int price = 0, day = 0;
    mockMovie movie("test", price);
    mockRental rental(movie, day);

    EXPECT_CALL(rental, getDaysRented())
            .Times(Exactly(3))
            .WillOnce(Return(2))
            .WillOnce(Return(5))
            .WillOnce(Return(5));


    Rental r1(movie, 2);
    Rental r2(movie, 5);
    Regular r;

    EXPECT_EQ(r.regular(&r1), 2);
    EXPECT_EQ(r.regular(&r2), 6.5);
}

TEST(typeTest, newReleaseTest) {
    int price = 0, day = 0;
    mockMovie movie("test", price);
    mockRental rental(movie, day);

    EXPECT_CALL(rental, getDaysRented())
            .Times(Exactly(2))
            .WillOnce(Return(2))
            .WillOnce(Return(5));


    Rental r1(movie, 2);
    Rental r2(movie, 5);
    NewRelease n;

    EXPECT_EQ(n.newRelease(&r1), 6);
    EXPECT_EQ(n.newRelease(&r2), 15);
}

#endif //GEN_LABO05_TYPETEST_H
