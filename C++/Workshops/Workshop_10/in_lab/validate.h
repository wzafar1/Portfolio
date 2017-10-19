/*
OOP244 Workshop 10: Validate
File: validate.h
Version 1.0
Date: 03/08/2017
Author: wzafar1
Seneca Emial: wzafar1@myseneca.ca
*/

#ifndef ICT_VALIDATE_H_
#define ICT_VALIDATE_H_

namespace ict {

  template <typename T> 
  
  bool validate(const T& minimum, const T& maximum, const T* testVal, int numElem, bool* result) {

    int pass = 0;
    bool state = false;
    
    for (int i = 0; i < numElem; i++) {

      if (testVal[i] >= minimum && testVal[i] <= maximum) {

        result[i] = true;
        pass++;

      }
      else {

        result[i] = false;

      }

    }
    
    if (pass == (numElem)) {

      state = true;

    }

    return state;

  }
}


#endif // !ICT_VALIDATE_H_
