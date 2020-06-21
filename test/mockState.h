//
// Created by janis on 21.06.2020.
//

#ifndef GEN_LABO05_MOCKSTATE_H
#define GEN_LABO05_MOCKSTATE_H

#include "gmock/gmock.h"  // Brings in Google Mock.
#include "../Rental.h"
#include "mockRental.h"
#include "../Children.h"
#include "../NewRelease.h"
#include "../Regular.h"

class mockState : State {
    MOCK_METHOD0(regular, mockRental&());
    MOCK_METHOD0(newRelease, mockRental&());
    MOCK_METHOD0(children, mockRental&());
};

class mockChildren : Children {
    MOCK_METHOD0(children, mockRental&());
};

class mockNewRelease : NewRelease {
    MOCK_METHOD0(newRelease, mockRental&());
};

class mockRegular : Regular {
    MOCK_METHOD0(regular, mockRental&());
};

#endif //GEN_LABO05_MOCKSTATE_H
