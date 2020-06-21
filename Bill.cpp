//
// Created by Pierre-Olivier on 21.06.2020.
//

#include "Bill.h"

using namespace std;

void Bill::addRental( const Rental& arg ) { _rentals.push_back( arg ); }

string Bill::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << _customer.getName() << "\n";
    for (auto& each: _rentals) {
        // determine amounts for each line
        totalAmount += each.getAmmount();

        // add frequent renter points
        frequentRenterPoints += each.getFrequentRenterPoint();

        // show figures for this rental
        result << each.getFigures();
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}