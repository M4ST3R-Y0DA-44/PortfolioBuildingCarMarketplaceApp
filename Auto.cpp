/**
 * \file Auto.cpp
 * \brief This file contains the car class and all its methods and attributes declaration
 *
 * \date Created on 10-12-2021 */



#include "Auto.h"
#include <sstream>


/*constructor of class Auto*/
Auto::Auto (std::string& p_make, std::string& p_model, int p_year, int p_mileage, std::string& p_color, int p_numOfDoors, std::string& p_transmission, std::string& p_subtype, std::string& p_vin) : m_make (p_make), m_model (p_model), m_year (p_year), m_mileage (p_mileage), m_color (p_color), m_numOfDoors (p_numOfDoors), m_transmission (p_transmission), m_subtype (p_subtype), m_vin (p_vin) { }


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
