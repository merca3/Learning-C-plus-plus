#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
using namespace std;

class Package
{
public:
    Package(
        string senderName, string senderAddress, string senderCity, string senderState, string senderZip,
        string recipientName, string recipientAddress, string recipientCity, string recipientState, string recipientZip,
        double weightOunces, double pricePerOunce)
    {
        m_senderName = senderName;
        m_senderAddress = senderAddress;
        m_senderCity = senderCity;
        m_senderState = senderState;
        m_senderZip = senderZip;
        m_recipientName = recipientName;
        m_recipientAddress = recipientAddress;
        m_recipientCity = recipientCity;
        m_recipientState = recipientState;
        m_recipientZip = recipientZip;
        if (weightOunces < 0)
        {
            m_weightOunces = 0;
        }
        else
            m_weightOunces = weightOunces;
        if (pricePerOunce < 0)
        {
            m_pricePerOunce = 0;
        }
        else
            m_pricePerOunce = pricePerOunce;
    }
    double weightOunces() const { return m_weightOunces; };
    double pricePerOunce() const { return m_pricePerOunce; };
    virtual double calculateCost() const
    {
        return m_weightOunces * m_pricePerOunce;
    }
    void printAllInfo()
    {
        cout << "Information about package" << endl;
        cout << endl;
        cout << "Sender: " << endl;
        printSenderInfo();
        cout << "Recipient: " << endl;
        printRecipientInfo();
        cout << "Cost of the package: " << calculateCost() << "$" << endl;
        cout << "=========================================" << endl;
    }

private:
    string m_senderName;
    string m_senderAddress;
    string m_senderCity;
    string m_senderState;
    string m_senderZip;
    string m_recipientName;
    string m_recipientAddress;
    string m_recipientCity;
    string m_recipientState;
    string m_recipientZip;
    double m_weightOunces;
    double m_pricePerOunce;
    void printSenderInfo() const
    {
        cout << m_senderName << ", " << m_senderAddress << endl;
        cout << m_senderCity << ", " << m_senderState << ", " << m_senderZip << endl;
        cout << endl;
    }
    void printRecipientInfo() const
    {
        cout << m_recipientName << ", " << m_recipientAddress << endl;
        cout << m_recipientCity << ", " << m_recipientState << ", " << m_recipientZip << endl;
        cout << endl;
    }
};

#endif