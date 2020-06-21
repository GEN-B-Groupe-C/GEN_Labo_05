// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"
#include "Rental.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
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

