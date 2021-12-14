/**
 * \file   Vehicule.h
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 10 décembre 2021
 */

#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>

namespace VehiculeManager
{

  /**
   * \class Vehicule
   * \brief class representing a car with all its attributes and methods. */
  class Vehicule
  {
  public:

    /**
     * \fn   Vehicule (std::string& p_make, std::string& p_model, int p_year, int p_mileage, std::string& p_color, int p_numOfDoors, std::string& p_subType, std::string& p_vin)
     * \brief Constructor of the Car class
     * \param p_make  (string) contains the make of the car
     * \param p_model (string) contains the model of the car
     * \param p_year (int) contains the year of the car
     * \param p_mileage (int) contains the mileage of the car
     * \param p_color (string) contains the color of the car
     * \param p_numOfDoors (int) number of doors for the car
     * \param p_transmission (string) contains the gearbox type
     * \param p_subtype (string) car categorie (sub compact, compact, SUV, etc)
     * \param p_vin (string) the vehicules identification number */
    Vehicule (const std::string& p_make, const std::string& p_model, const int p_year, const int p_mileage, const std::string& p_color, const std::string& p_transmission, const std::string& p_subtype, const std::string& p_vin);

    /**
     * \fn const std::string reqMake () const
     * \brief method to read m_make attribute of the vehicule
     * \return  (string) containing the m_make attribute
     */
    const std::string reqMake () const;
    /**
     * \fn const std::string reqModel () const
     * \brief method to read m_model attribute
     * \return (string) containing m_model attribute
     */
    const std::string reqModel () const;
    /**
     * \fn const int reqYear () const
     * \brief method to read the m_year attribute
     * \return  (int) containing the m_year attribute
     */
    const int reqYear () const;
    /**
     * \fn const int reqMileage () const
     * \brief method to read the m_mileage attribute
     * \return (int) containing the m_mileage attribute
     */
    const int reqMileage () const;
    /**
     * \fn const std::string reqColor () const
     * \brief method to read the m_color attribute
     * \return  (string) containing the m_color attribute
     */
    const std::string reqColor () const;
    /**
     * \fn const int reqTransmisison () const
     * \brief method to read the m_Transmission attribute
     * \return (int) containing the m_Transmission attribute
     */

    const std::string reqTransmission () const;
    /**
     * \fn const std::string reqSubtype () const
     * \brief method to read the m_subType attribute
     * \return (string) containing the m_subType attribute
     */
    const std::string reqSubtype () const;
    /**
     * \fn const std::string reqVin () const
     * \brief method to read the m_vin attribute
     * \return (string) containing the m_vin attribute
     */
    const std::string reqVin () const;
    /**
     * \fn const std::string reqInfoTitle() const
     * \brief method to read the information of the vehicule in a title formated string
     * \return (string) information on the vehicule in a title formated string*
     */
    const std::string reqInfoTitle () const;

    /**
     * \fn virtual const std::string reqAllInfo() const = 0
     * \brief method that return all the information on the vehicule
     * \return (string) with all the informations on the vehicule
     */
    virtual const std::string reqAllInfo () const = 0;

    /**
     * \fn virtual Vehicule* clone() const = 0
     * \brief method that creates a clone of the object vehicule to be implemented in all sub classes
     * \return (pointer) a pointer pointing on a clone of the vehicule
     */
    virtual Vehicule* clone () const = 0;

    /**
     * \virtual ~Vehicule ()
     * \brief Destructor of the class to be implemented in all other subclasses
     */
    virtual
    ~Vehicule () { };


  private:
    std::string m_make; /**< \brief (string) contains the make of the car*/
    std::string m_model; /**< \brief (string) contains the model of the car*/
    int m_year; /**< \brief (int) contains the year of the car*/
    int m_mileage; /**< \brief (int) contains the mileage of the car*/
    std::string m_color; /**< \brief (string) contains the color of the car*/
    std::string m_transmission; /**< \brief (string) gearbox type (Auto/Manual/etc)*/
    std::string m_subtype; /**< \brief (string) car categorie (sub compact, compact, SUV, etc)*/
    std::string m_vin; /**< \brief (string) the vehicules identification number*/

    /**
     * \fn void verifyInvariant () const
     * \brief method to verify invariant errors
     */
    void verifyInvariant () const;
  };

};

#endif /* VEHICULE_H */

