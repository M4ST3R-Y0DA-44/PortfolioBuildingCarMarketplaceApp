/**
 * \file CarPosting.cpp
 * \author M4ST3R-Y0DA-44
 * \brief This file contains the CarPosting class and all its methods and attributes declaration
 *
 * \date Created on 10-12-2021 */


#include "CarPosting.h"


CarPosting::CarPosting (int p_id, int p_price, time_t p_dateListed, std::string p_postalCode, std::string p_contactPhone, std::string p_contactEmail) : m_id (p_id), m_price (p_price), m_dateListed (p_dateListed), m_postalCode (p_postalCode), m_contactPhone (p_contactPhone), m_contactEmail (p_contactEmail) { }