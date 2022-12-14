#ifndef OVERNIGHT_PACKAGE_H
#define OVERNIGHT_PACKAGE_H

#include "package.h"

class Overnight_Package : public Package
{
public:
    Overnight_Package(
        string senderName, string senderAddress, string senderCity, string senderState, string senderZip,
        string recipientName, string recipientAddress, string recipientCity, string recipientState, string recipientZip,
        double weightOunces, double pricePerOunce, double addFeePerOunce)
        : Package(senderName, senderAddress, senderCity, senderState, senderZip,
                  recipientName, recipientAddress, recipientCity, recipientState, recipientZip,
                  weightOunces, pricePerOunce)
    {
        if (addFeePerOunce < 0)
        {
            m_addFeePerOunce = 0;
        }
        else
            m_addFeePerOunce = addFeePerOunce;
    }
    double calculateCost() const override
    {
        return weightOunces() * (pricePerOunce() + m_addFeePerOunce);
    }

private:
    double m_addFeePerOunce;
};

#endif