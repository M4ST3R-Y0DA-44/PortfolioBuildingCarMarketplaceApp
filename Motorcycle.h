/**
 * \file   Motorcycle.h
 * \author M4ST3R-Y0DA-44
 * \brief file that contains the Motorcycle class
 *
 * \date Created on 14 décembre 2021, 00:25
 */

#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicule.h"


/**
 * \namespace VehiculeManager
 * \brief namespace to contains all vehicule type that can be accepted by our application
 */
namespace VehiculeManager
{

  /**
   * \class Motorcycle
   * \brief A class representing a Motorcycle, this class inherits the Vehicule base class.
   */
  class Motorcycle : public Vehicule
  {
  public:
    /**
     *\fn Motorcycle (const std::string& p_make, const std::string& p_model, const int p_year, const int p_mileage, const std::string& p_color, const std::string& p_transmission, const std::string& p_subtype, const std::string& p_vin, const int p_enginecc, const std::string p_bikeCategory)
     * \brief constructor of the Motorcycle class
     * @param p_make (string) make of the motorcycle
     * @param p_model (string) model of the motorcycle
     * @param p_year (int) year of fabrication of the motorcycle
     * @param p_mileage (int) current mileage of the motorcycle
     * @param p_color (string) color of the motorcycle
     * @param p_transmission (string) transmission of the motorcycle
     * @param p_subtype (string) represents the type of class in this case Motorcycle
     * @param p_vin (string) vehicule identification number of the motorcycle
     * @param p_enginecc (int) represent the size of the engine in cc
     * @param p_bikeCategory (string) the bike category of plates at the SAAQ in the province of Quebec
     */
    Motorcycle (const std::string& p_make, const std::string& p_model, const int p_year, const int p_mileage, const std::string& p_color, const std::string& p_transmission, const std::string& p_subtype, const std::string& p_vin, const int p_enginecc, const std::string p_bikeCategory);

    /**
     * \fn const int reqEnginecc() const
     * \brief method that returns the engine size in cc attribut (m_enginecc)
     * \return (int) value of engine size in cc
     */
    const int reqEnginecc () const;

    /**
     * \fn const std::string reqBikeCategory() const
     * \brief method that returns the category of bike according to the SAAQ in Quebec
     * \return (string) the bike category at the SAAQ
     */
    const std::string reqBikeCategory () const;

    /**
     * \virtual const std:string reqAllInfo() const
     * \brief method to return all info of the Motorcycle
     * \return (string) a complete formated list of information on the motorcycle
     */
    virtual const std::string reqAllInfo () const;
    /**
     * \fn virtual Vehicule* clone() const
     * \brief method to clone the Vehicule using a pointer
     * \return (pointer) points to the Vehicule we are copying
     */
    virtual Vehicule* clone () const;


  private:
    int m_enginecc; /**< \brief (int) engine size in cc*/
    std::string m_bikeCategory; /**< \brief (string) categorie of plates for the bike at the SAAQ in Quebec*/

    /**
     * \fn void verifyInvariant () const
     * \brief method to verify all Invariants of the class
     */
    void verifyInvariant () const;


  };

};

#endif /* MOTORCYCLEH */

