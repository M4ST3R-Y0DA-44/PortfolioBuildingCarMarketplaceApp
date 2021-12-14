/**
 * \file  VehiculeTestor.cpp
 * \author M4ST3R-Y0DA-44
 * \brief this file contains all test for the Auto class
 *
 * \date Created on 13 décembre 2021
 */

#include "Vehicule.h"
#include "ExceptionContract.h"
#include <gtest/gtest.h>
#include "ExceptionContract.h"

/**
 * \class VehiculeTesting
 * \brief made specifically to be able to test the Auto class. The Auto class will becomde a virtual pure class so we will need the AutoTesting class to be able to create objects of the class to test the class.
 */
class VehiculeTesting : public Vehicule
{

public:


  /**
   * \fn VehiculeTesting (std::string& p_make, std::string& p_model, int p_year, int p_mileage, std::string& p_color, int p_numOfDoors, std::string& p_transmission, std::string& p_subtype, std::string& p_vin) : Auto ("ford", "f-150", 2003, 20300, "black", 2, "automatic", "truck" "XDEDE34674347683")
   * \brief constructs an object to be able to test the Auto class.
   * @param p_make
   * @param p_model
   * @param p_year
   * @param p_mileage
   * @param p_color
   * @param p_numOfDoors
   * @param p_transmission
   * @param p_subtype
   * @param p_vin
   */
  VehiculeTesting (const std::string& p_make, const std::string& p_model, const int p_year, const int p_mileage, const std::string& p_color, const std::string& p_transmission, const std::string& p_subtype, const std::string& p_vin) : Vehicule (p_make, p_model, p_year, p_mileage, p_color, p_transmission, p_subtype, p_vin) { };


} ;


/**
 * Test of the Vehicule Constructor
 * valid cases:     all param valid.
 * invalid case:    invalid make (empty)
 *                  invalid make (names contain numbers)
 *                  invalid model (empty)
 *                  invalid year (year too low)
 *                  invalid year (year too high)
 *                  invalid year (null)
 *                  invalid mileage (null)
 *                  invalid mileage (Null)
 *                  invalid mileage (mileage too high)
 *                  invalid color (empty)
 *                  invalid color (color contains numbers)
 *                  invalid transmission (empty)
 *                  invalid subtype (empty)
 *                  invalid vin (empty)
 *                  invalid vin (invalid vin)
 */


TEST (VehiculeTesting, ValidConstructorParam)

{
  VehiculeTesting f_testor = VehiculeTesting ("ford", "focus", 2004, 124500, "black", "automatic", "auto", "XYZSED1234567");

  EXPECT_EQ (f_testor.reqMake (), "ford");
  EXPECT_EQ (f_testor.reqModel (), "focus");
  EXPECT_EQ (f_testor.reqYear (), 2004);
  EXPECT_EQ (f_testor.reqMileage (), 124500);
  EXPECT_EQ (f_testor.reqColor (), "black");
  EXPECT_EQ (f_testor.reqTransmission (), "automatic");
  EXPECT_EQ (f_testor.reqSubtype (), "auto");
  EXPECT_EQ (f_testor.reqVin (), "XYZSED1234567");
};


TEST (VehiculeTesting, invalidConstructorMakeEmpty)
{
  ASSERT_THROW (VehiculeTesting ("", "focus", 2004, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorMakeNumber)
{
  ASSERT_THROW (VehiculeTesting ("for44d", "focus", 2004, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorModelEmpty)
{
  ASSERT_THROW (VehiculeTesting ("ford", "", 2004, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorYearTooLow)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 1800, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorYearTooHigh)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2030, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorYearNull)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", NULL, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorMileageNull)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, NULL, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorMileageTooLow)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, -25, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorMileageZero)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 0, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorMileageTooHigh)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 1000001, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorColorEmpty)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 124500, "", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorColorContainsNumber)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 124500, "bl4ck", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorTransmissionEmpty)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 124500, "black", "", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorSubtypeEmpty)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 124500, "black", "automatic", "", "XYZSED1234567"), PreconditionException);
};


TEST (VehiculeTesting,  invalidConstructorVinEmpty)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 124500, "black", "automatic", "auto", ""), PreconditionException);
};


TEST (VehiculeTesting, invalidConstructorVinNotValid)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};