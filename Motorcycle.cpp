/*
 * \file   Motorcycle.cpp
 * \author M4ST3R-Y0DA-44
 * \brief file contains the Motorcycle class methods definitions
 *
 * \date Created on 14 décembre 2021, 01:16
 */


#include "Motorcycle.h"
#include "ExceptionContract.h"
#include "sstream"

using namespace std;
using namespace VehiculeManager;


/*Constructor of the lcass Motorcycle*/
Motorcycle::Motorcycle (const string& p_make, const string& p_model, const int p_year, const int p_mileage, const string& p_color, const string& p_transmission, const string& p_subtype, const string& p_vin, const int p_enginecc, const string p_bikeCategory) : Vehicule (p_make, p_model, p_year, p_mileage, p_color, p_transmission, p_subtype, p_vin), m_enginecc (p_enginecc), m_bikeCategory (p_bikeCategory)
{
  PRECONDITION (p_enginecc > 0);
  PRECONDITION (p_enginecc < 2500);
  PRECONDITION (p_bikeCategory.size () > 0);

  POSTCONDITION (reqEnginecc () == p_enginecc);
  POSTCONDITION (reqBikeCategory () == p_bikeCategory);

  INVARIANTS ();
};


/*method to read engine cc*/
const int
Motorcycle::reqEnginecc () const
{
  return m_enginecc;
}


/*method to read bike category at the saaq*/
const string
Motorcycle::reqBikeCategory () const
{
  return m_bikeCategory;
}


/*Method to read all information regarding the motorcycle, will be implemented in all subclass*/
const string
Motorcycle::reqAllInfo () const
{
  ostringstream ostream;
  ostream << Vehicule::reqAllInfo ()
          << "engine cc : " << reqEnginecc () << endl
          << "motorcycles plate category at the SAAQ : " << reqAllInfo () << endl;
  return ostream.str ();
}


/*Method to clone the Vehicule using a pointer*/
Vehicule*
Motorcycle::clone () const
{
  return new Motorcycle (*this);
}


/*Method to verify all class Invariants*/
void
Motorcycle::verifyInvariant () const
{
  INVARIANT (m_enginecc > 0);
  INVARIANT (m_enginecc < 2500);
  INVARIANT (m_bikeCategory.size () > 0);
}