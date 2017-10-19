#ifndef _ICT_CONTACT_H
#define _ICT_CONTACT_H

namespace sict {

  class Contact {

  private:

    char m_name[20];
    long long* m_Pnumber;
    int m_noOfNumbers;

    bool decomposeNumber(const long long phone_number);

    long long getAreaCode(const long long phone_number);
    long long getCountryCode(const long long phone_number);
    long long getNumber(const long long phone_number);

  public:

    //Members
    Contact(); //Default constructot
    Contact(const char* name, const long long* phoneNumber, int noOfDigits);
    ~Contact(); //deconstructor

                // Functions
    bool isEmpty() const;
    void display() const;

    void setEmpty();

  };

}

#endif // !_ICT_CONTACT_H
