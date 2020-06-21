#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Customer.h"
#include "Bill.h"
#include "test/RentalTest.h"
#include "test/typeTest.h"

int main() {
    testing::InitGoogleTest();
    testing::InitGoogleMock();

    Customer customer("Olivier");
    Bill bill(customer);
    bill.addRental(Rental( Movie("Karate Kid"), 7));
    bill.addRental(Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    bill.addRental(Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

    std::cout << bill.statement() << std::endl;

    return RUN_ALL_TESTS();
}