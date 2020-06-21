// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"
#include "Rental.h"

using std::ostringstream;
using std::vector;

using namespace std;

Customer::Customer() {}

Customer::Customer( const std::string& name )
        : _name( name ) {}

std::string Customer::getName() const { return _name; }

