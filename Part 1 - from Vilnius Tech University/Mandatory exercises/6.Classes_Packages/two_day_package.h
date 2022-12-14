#ifndef TWO_DAY_PACKAGE_H
#define TWO_DAY_PACKAGE_H

#include "package.h"

class Two_Day_Package : public Package
{
public:
    Two_Day_Package(
        string senderName, string senderAddress, string senderCity, string senderState, string senderZip,
        string recipientName, string recipientAddress, string recipientCity, string recipientState, string recipientZip,
        double weightOunces, double pricePerOunce, double flatFee)
        : Package(senderName, senderAddress, senderCity, senderState, senderZip,
                  recipientName, recipientAddress, recipientCity, recipientState, recipientZip,
                  weightOunces, pricePerOunce)
    {
        if (flatFee < 0)
        {
            m_flatFee = 0;
        }
        else
            m_flatFee = flatFee;
    }
    double calculateCost() const override
    {
        return weightOunces() * pricePerOunce() + m_flatFee;
    }

private:
    double m_flatFee;
};

#endif