// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for (auto& elem: _rentals) {
        //double thisAmount = 0;
        Rental each = elem;

        // determine amounts for each line
        double thisAmount = getAmmount(each);

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
             && each.getDaysRented() > 1 ) frequentRenterPoints++;

        // show figures for this rental
        result << "\t" << each.getMovie().getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

double Customer::getAmmount(const Rental &each) const {
    double result = 0;
    switch ( each.getMovie().getPriceCode() ) {
        case Movie::REGULAR:
            result += 2;
            if ( each.getDaysRented() > 2 )
                result += ( each.getDaysRented() - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            result += each.getDaysRented() * 3;
            break;
        case Movie::CHILDRENS:
            result += 1.5;
            if ( each.getDaysRented() > 3 )
                result += ( each.getDaysRented() - 3 ) * 1.5;
            break;
    }
    return result;
}
