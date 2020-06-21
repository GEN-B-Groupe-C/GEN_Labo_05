//
// Created by janis on 19.06.2020.
//

#include "gtest/gtest.h"
#include "../Customer.h"
#include "../Bill.h"

TEST(CustomerTest, integration) {
    Customer customer("Olivier");
    Bill bill(customer);
    bill.addRental(Rental( Movie("Karate Kid"), 7));
    bill.addRental(Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    bill.addRental(Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

    ASSERT_EQ(bill.statement(), "Rental Record for Olivier\n\tKarate Kid\t9.5\n\tAvengers: Endgame\t15\n\tSnow White\t1.5\nAmount owed is 26\nYou earned 4 frequent renter points");
}