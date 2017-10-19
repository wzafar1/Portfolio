/*
OOP244 Workshop 4: Passenger database
File: Passenger.cpp
Version 1.0
Date: 08/06/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#include<iostream>
#include <cstring>
#include"Passenger.h"

#define _CRT_SECURE_NO_WARNINGS

namespace sict {

  using namespace std;
  //Default Constructor Implementaion

  Passenger::Passenger() {

    setEmpty();

  };

  //Constructor with 2 parameters Implementaion

  Passenger::Passenger(const char* name, const char* address) {

    if (name == nullptr || name[0] == '\0' || address == nullptr || address[0] == '\0') {

      setEmpty();

    }
    else {

      strncpy(m_PassangerName, name, Max_NameLength);
      m_PassangerName[Max_NameLength] = '\0';
      strncpy(m_Destination, address, Max_NameLength);
      m_Destination[Max_NameLength] = '\0';

      m_DayOfDeparture = 1;
      m_MonthOfDeparture = 7;
      m_YearOfDeparture = 2017;

    }

  };

  //Functions isEmpty query Implementations

  bool Passenger::isEmpty() const {

    bool check;

    if (m_PassangerName[0] == '\0' || m_Destination[0] == '\0') {

      check = true;

    }
    else {

      check = false;

    }

    return check;

  };

 //Functions display query Implementations

  void Passenger::display() const {

    cout << m_PassangerName << " - " << m_Destination
      << " on " << m_YearOfDeparture << "/"; 
    cout.fill('0');
    cout.width(2);
    cout << m_MonthOfDeparture << "/" << m_DayOfDeparture << endl;


  }

  void Passenger::setEmpty() {

    m_PassangerName[0] = '\0';
    m_Destination[0] = '\0';
    m_DayOfDeparture = 0;
    m_MonthOfDeparture = 0;
    m_YearOfDeparture = 0;

  }

  Passenger::Passenger(const char* p_name, const char* p_dest, int t_year, int t_month, int t_day) {


    bool check = (p_name == nullptr || p_name[0] == '\0' || p_dest == nullptr || p_dest[0] == '\0' || t_year < 2017 || t_year>2020
      || t_month < 1 || t_month>12 || t_day < 1 || t_day>31);

    if (!check) {

      strncpy(m_PassangerName, p_name, Max_NameLength);
      m_PassangerName[Max_NameLength] = '\0';
      strncpy(m_Destination, p_dest, Max_NameLength);
      m_Destination[Max_NameLength] = '\0';
      m_DayOfDeparture = t_day;
      m_YearOfDeparture = t_year;
      m_MonthOfDeparture = t_month;
 
    }
    else {

      setEmpty();

    }

  }

  bool Passenger::canTravelWith(const Passenger& passenger) const {

    int yes = 0;

    bool check = (strcmp(m_Destination, passenger.m_Destination) == 0 && m_YearOfDeparture == passenger.m_YearOfDeparture
      && m_MonthOfDeparture == passenger.m_MonthOfDeparture && m_DayOfDeparture == passenger.m_DayOfDeparture);

    if (check) {

      yes = 1;

    }

    return yes;

  }

  const char* Passenger::name() const {

    return m_PassangerName;

  }

}