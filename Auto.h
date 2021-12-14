/**
 * \file   Auto.h
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 10 décembre 2021
 */

#ifndef AUTO_H
#define AUTO_H

#include <string>

/**
 * \class Auto
 * \brief class representing a car with all its attributes and methods. */
class Auto
{
public:

  /**
   * \fn   Auto (std::string& p_make, std::string& p_model, int p_year, int p_mileage, std::string& p_color, int p_numOfDoors, std::string& p_subType, std::string& p_vin)
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
  Auto (const std::string& p_make, const std::string& p_model, const int p_year, const int p_mileage, const std::string& p_color, const int p_numOfDoors, const std::string& p_transmission, const std::string& p_subtype, const std::string& p_vin);

  /**
   * \fn const std::string reqMake () const
   * \brief method to read m_make attribute of the car
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
   * \fn const int reqNumOfDoors () const
   * \brief method to read the m_numOfDoors attribute
   * \return (int) containing the m_numOfDoors attribute
   */
  const int reqNumOfDoors () const;
  /**
   * \fn const std::string reqTransmission () const
   * \brief method to read the transmission type
   * \return (string) containing gearbox type (Auto/Manual/etc)
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
   * \fn const std::string reqInfoTitleAuto() const
   * \brief method to read the information of the car in a title formated string
   * \return (string) information on the car in a title formated string*
   */
  const std::string reqInfoTitleAuto () const;

private:
  std::string m_make; /**\brief (string) contains the make of the car*/
  std::string m_model; /**\brief (string) contains the model of the car*/
  int m_year; /**\brief (int) contains the year of the car*/
  int m_mileage; /**\brief (int) contains the mileage of the car*/
  std::string m_color; /**\brief (string) contains the color of the car*/
  int m_numOfDoors; /**\brief (int) number of doors for the car*/
  std::string m_transmission; /**\brief (string) gearbox type (Auto/Manual/etc)*/
  std::string m_subtype; /**\brief (string) car categorie (sub compact, compact, SUV, etc)*/
  std::string m_vin; /**\brief (string) the vehicules identification number*/

  /**
   * \fn void verifyInvariant () const
   * \brief method to verify invariant errors
   */
  void verifyInvariant () const;
};

#endif /* AUTO_H */

