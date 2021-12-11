/**
 * \file Auto.cpp
 * \author M4ST3R-Y0DA-44
 * \brief This file contains the car class and all its methods and attributes declaration
 *
 * \date Created on 10-12-2021 */



#include "Auto.h"
#include <sstream>
#include "ExceptionContract.h"


/*constructor of class Auto*/
Auto::Auto (std::string& p_make, std::string& p_model, int p_year, int p_mileage, std::string& p_color, int p_numOfDoors, std::string& p_transmission, std::string& p_subtype, std::string& p_vin) : m_make (p_make), m_model (p_model), m_year (p_year), m_mileage (p_mileage), m_color (p_color), m_numOfDoors (p_numOfDoors), m_transmission (p_transmission), m_subtype (p_subtype), m_vin (p_vin)
{
  PRECONDITION (p_make.size () > 0 ); /*size()>0 will all be changed in the futur with a function to validate names*/
  PRECONDITION (p_model.size () > 0); /*size()>0 will all be changed in the futur with a function to validate names*/
  PRECONDITION (p_year > 1800);
  PRECONDITION (p_year <= 2022);
  PRECONDITION (p_mileage > 0);
  PRECONDITION (p_mileage < 1000000);
  PRECONDITION (p_color.size () > 0); /*size()>0 will all be changed in the futur with a function to validate names*/
  PRECONDITION (p_numOfDoors >= 0);
  PRECONDITION (p_numOfDoors <= 5);
  PRECONDITION (p_transmission.size () > 0 ); /*size()>0 will all be changed in the futur with a function to validate names*/
  PRECONDITION (p_subtype.size () > 0); /*size()>0 will all be changed in the futur with a function to validate names*/
  PRECONDITION (p_vin.size () > 0); /*to be modified with a vin validator function*/

  POSTCONDITION (m_make = p_make);
  POSTCONDITION (m_model = p_model);
  POSTCONDITION (m_year = p_year);
  POSTCONDITION (m_mileage = p_mileage);
  POSTCONDITION (m_color = p_color);
  POSTCONDITION (m_numOfDoors = p_numOfDoors);
  POSTCONDITION (m_transmission = p_transmission);
  POSTCONDITION (m_subtype = p_subtype);
  POSTCONDITION (m_vin = p_vin);

  INVARIANTS ();
}


/*request method for make attribute*/


const std::string
Auto::reqMake () const
{
  return m_make;
}


/*request method for model attribute*/
const std::string
Auto::reqModel () const
{
  return m_model;
}


/*request method for year attribute*/
const int
Auto::reqYear () const
{
  return m_year;
}


/*request method for mileage attribute*/
const int
Auto::reqMileage () const
{
  return m_mileage;
}


/*request method for color attribute*/
const std::string
Auto::reqColor () const
{
  return m_color;
}


/*request method for number of doors attribute*/
const int
Auto::reqNumOfDoors () const
{
  return m_numOfDoors;
}


/*request method for transmission*/
const std::string
Auto::reqTransmission () const
{
  return m_transmission;
}


/*request method for subtype attribute*/
const std::string
Auto::reqSubType () const
{
  return m_subtype;
}


/*request method for vin attribute*/
const std::string
Auto::reqVin () const
{
  return m_vin;
}


/*request for the information regarding the vehicule in a title formated string*/
const std::string
Auto::reqInfoTitleAuto () const
{
  std::ostringstream ostream;
  ostream << reqYear () << " " << reqMake () << " " << reqModel ();
  return ostream.str ();
}


/*Method to verify Invariants*/
void
Auto::verifyInvariant () const
{
  INVARIANT (m_make.size () > 0 ); /*size()>0 will all be changed in the futur with a function to validate names*/
  INVARIANT (m_model.size () > 0);  /*size()>0 will all be changed in the futur with a function to validate names*/
  INVARIANT (m_year > 1800);
  INVARIANT (m_year <= 2022);
  INVARIANT (m_mileage > 0);
  INVARIANT (m_mileage < 1000000);
  INVARIANT (m_numOfDoors >= 0);
  INVARIANT (m_numOfDoors <= 5);
  INVARIANT (m_transmission.size () > 0 ); /*size()>0 will all be changed in the futur with a function to validate names*/
  INVARIANT (m_subtype.size () > 0); /*size()>0 will all be changed in the futur with a function to validate names*/
  INVARIANT (m_vin.size () > 0); /*size()>0 will all be changed in the futur with a function to validate names*/
}
