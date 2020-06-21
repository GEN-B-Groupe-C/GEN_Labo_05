// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
public:
    Customer();
    explicit Customer( const std::string& name );

    virtual std::string getName() const;

private:
    std::string _name;

};
#endif // CUSTOMER_H