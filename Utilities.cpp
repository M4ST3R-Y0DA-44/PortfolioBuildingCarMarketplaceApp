/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <string>
#include <cstring>
#include "Utilities.h"

using namespace std;

namespace usefull
{


  bool
  ValidateStringForNumbersAndEmpty (const string& p_stringToVerify)
  {
    bool stringValid = true;
    if (p_stringToVerify.size () == 0)
      {
        stringValid = false;
      }
    else
      {
        int i = 0;
        char strTest[p_stringToVerify.size () + 1];
        strcpy (strTest, p_stringToVerify.c_str ());
        while (i < p_stringToVerify.size ())
          {
            if (isalpha (strTest[i]))
              {
                i++;
              }
            else
              {
                if (isdigit (strTest[i]))
                  {
                    stringValid = false;
                  }
                else
                  {
                    if (p_stringToVerify.size () - i > 1)
                      {
                        int peekNextLetter = i + 1;
                        if (isalpha (strTest[peekNextLetter]) == false)
                          {
                            stringValid = false;
                          }
                      }
                  }
                i++;
              }
          }
      }
    return stringValid;
  }
}