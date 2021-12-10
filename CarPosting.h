/*
 * \file  CarPosting.h
 * \author M4ST3R-Y0DA-44
 * \brief this file contains all declarations for the CarPosting class.
 *
 * \date Created on 10 décembre 2021
 */

#ifndef CARPOSTING_H
#define CARPOSTING_H


#include <string>

/**
 * \class CarPosting
 * \brief class that will contain all Relevent information for the sale of an Auto on our platform.
 */
class CarPosting
{
public:
  /**
   * \fn CarPosting (int p_id, int p_price, time_t p_dateListed, std::string p_postalCode, std::string p_contactPhone, std::string p_email)
   * \brief constructor for class CarPosting
   * @param p_id (int) Ad id, it is used to keep track of ad history
   * @param p_price (int) asking price for sale of car
   * @param p_dateListed (time_t) date at wich the listing appeared
   * @param p_postalCode (string) postal code of the area of sale
   * @param p_contactPhone (string) phone to reach the seller
   * @param p_contactEmail (string) email to reach the seller
   */
  CarPosting (int p_id, int p_price, time_t p_dateListed, std::string p_postalCode, std::string p_contactPhone, std::string p_contactEmail);




private:
  int m_id; /**\brief CarPosting registration id*/
  int m_price; /**\brief (int) asking sale price for a car*/
  int m_soldPrice; /**\brief (int) price for wich the ad sold*/
  time_t m_dateListed; /**\brief (time_t) date at wich the listing was created*/
  time_t m_dateSold; /**\brief (time_t) date at wich the listing sold*/
  std::string m_postalCode; /**\brief (string) postal code representing the area in wich the car is located for sell*/
  std::string m_contactPhone; /**\brief (string) representing the phone number to contact the seller*/
  std::string m_contactEmail; /**\brief (string) representing the email to contact the seller*/

};

#endif /* CARPOSTING_H */

