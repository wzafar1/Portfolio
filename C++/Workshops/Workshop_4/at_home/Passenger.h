/*
OOP244 Workshop 4: Passenger database
File: Passenger.h
Version 1.0
Date: 08/06/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#ifndef ICT_PASSENGER_H
#define ICT_PASSENGER_H

namespace sict {

  const int Max_NameLength = 32;

  class Passenger {

  private:
    
    char m_PassangerName[Max_NameLength];
    char m_Destination[Max_NameLength];

    int m_YearOfDeparture;
    int m_MonthOfDeparture;
    int m_DayOfDeparture;


  public:

    //Constructors declaration

    Passenger();
    Passenger(const char* name, const char* address);
    Passenger(const char* name, const char* dest, int year, int month, int day);

    //Quries declaration

    bool isEmpty() const;
    void display() const;
    void setEmpty();

    const char* name() const;
    bool canTravelWith(const Passenger& passenger) const;

  };

}

#endif 
