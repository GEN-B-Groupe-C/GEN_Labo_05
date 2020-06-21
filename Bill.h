//
// Created by Pierre-Olivier on 21.06.2020.
//

#ifndef GEN_LABO05_BILL_H
#define GEN_LABO05_BILL_H

#include "Customer.h"
#include "Rental.h"
#include <vector>

class Bill {
public:

    Bill(const Customer& customer) : _customer(customer){}
    Bill(const Customer& customer,  std::vector< Rental > rentals) : _customer(customer), _rentals(rentals){}

    void addRental( const Rental& arg );
    std::string statement();
private:
    const Customer& _customer;
    std::vector< Rental > _rentals;
};
#endif //GEN_LABO05_BILL_H
