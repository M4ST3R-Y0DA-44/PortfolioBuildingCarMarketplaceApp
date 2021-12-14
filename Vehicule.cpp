/**
 * \file Vehicule.cpp
 * \author M4ST3R-Y0DA-44
 * \brief This file contains the car class and all its methods and attributes declaration
 *
 * \date Created on 10-12-2021 */



#include "Vehicule.h"
#include <sstream>
#include "ExceptionContract.h"


using namespace std;


/*constructor of class Auto*/
Vehicule::Vehicule (const string& p_make, const string& p_model, const int p_year, const int p_mileage, const string& p_color, const string& p_transmission, const string& p_subtype, const string& p_vin) : m_make (p_make), m_model (p_model), m_year (p_year), m_mileage (p_mileage), m_color (p_color), m_transmission (p_transmission), m_subtype (p_subtype), m_vin (p_vin)
{
  PRECONDITION (p_make.size () > 0 ); /*size()>0 will all be changed in the futur with a function to validate names*/
  PRECONDITION (p_model.size () > 0); /*size()>0 will all be changed in the futur with a function to validate names*/
  PRECONDITION (p_year > 1800);
  PRECONDITION (p_year <= 2022);
  PRECONDITION (p_mileage > 0);
  PRECONDITION (p_mileage < 1000000);
  PRECONDITION (p_color.size () > 0); /*size()>0 will all be changed in the futur with a function to validate names*/
  PRECONDITION (p_transmission.size () > 0 ); /*size()>0 will all be changed in the futur with a function to validate names*/
  PRECONDITION (p_subtype.size () > 0); /*size()>0 will all be changed in the futur with a function to validate names*/
  PRECONDITION (p_vin.size () > 0); /*to be modified with a vin validator function*/

  POSTCONDITION (reqMake () == p_make);
  POSTCONDITION (reqModel () == p_model);
  POSTCONDITION (reqYear () == p_year);
  POSTCONDITION (reqMileage () == p_mileage);
  POSTCONDITION (reqColor () == p_color);
  POSTCONDITION (reqTransmission () == p_transmission);
  POSTCONDITION (reqSubtype () == p_subtype);
  POSTCONDITION (reqVin () == p_vin);

  INVARIANTS ();
}


/*request method for make attribute*/


const string
Vehicule::reqMake () const
{
  return m_make;
}


/*request method for model attribute*/
const string
Vehicule::reqModel () const
{
  return m_model;
}


/*request method for year attribute*/
const int
Vehicule::reqYear () const
{
  return m_year;
}


/*request method for mileage attribute*/
const int
Vehicule::reqMileage () const
{
  return m_mileage;
}


/*request method for color attribute*/
const string
Vehicule::reqColor () const
{
  return m_color;
}


/*request method for transmission*/
const string
Vehicule::reqTransmission () const
{
  return m_transmission;
}


/*request method for subtype attribute*/
const string
Vehicule::reqSubtype () const
{
  return m_subtype;
}


/*request method for vin attribute*/
const string
Vehicule::reqVin () const
{
  return m_vin;
}


/*request for the information regarding the vehicule in a title formated string*/
const string
Vehicule::reqInfoTitleAuto () const
{
  ostringstream ostream;
  ostream << reqYear () << " " << reqMake () << " " << reqModel ();
  return ostream.str ();
}


/*Method to verify Invariants*/
void
Vehicule::verifyInvariant () const
{
  INVARIANT (m_make.size () > 0 ); /*size()>0 will all be changed in the futur with a function to validate names*/
  INVARIANT (m_model.size () > 0);  /*size()>0 will all be changed in the futur with a function to validate names*/
  INVARIANT (m_year > 1800);
  INVARIANT (m_year <= 2022);
  INVARIANT (m_mileage > 0);
  INVARIANT (m_mileage < 1000000);
  INVARIANT (m_transmission.size () > 0 ); /*size()>0 will all be changed in the futur with a function to validate names*/
  INVARIANT (m_subtype.size () > 0); /*size()>0 will all be changed in the futur with a function to validate names*/
  INVARIANT (m_vin.size () > 0); /*size()>0 will all be changed in the futur with a function to validate names*/
}
