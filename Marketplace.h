/*
 * \file  Marketplace.h
 * \author M4ST3R-Y0DA-44
 * \brief this file contains the Marketplace class declaration
 *
 * \date Created on 10 décembre 2021
 */

#ifndef MARKETPLACE_H
#define MARKETPLACE_H

/**
 * \class Marketplace
 * \brief class that will hold most of the information of our interface
 */
class Marketplace
{
public:



private:

  std::vector<CarPosting*> m_vSellList; /**\brief (vector) containing all the CarPosting for sale.*/
  std::vector<CarPosting*> m_vLeaseList; /**\brief (vector) containing all the CarPosting for lease.*/

};





#endif /* MARKETPLACE_H */

