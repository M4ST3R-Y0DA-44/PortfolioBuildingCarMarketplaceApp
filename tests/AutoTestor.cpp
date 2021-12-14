/**
 * \file  AutoTestor.cpp
 * \author M4ST3R-Y0DA-44
 * \brief this file contains all test for the Auto class
 *
 * \date Created on 13 décembre 2021
 */

#include "Auto.h"
#include "ExceptionContract.h"
#include <gtest/gtest.h>
#include "ExceptionContract.h"

/**
 * \class AutoTesting
 * \brief made specifically to be able to test the Auto class. The Auto class will becomde a virtual pure class so we will need the AutoTesting class to be able to create objects of the class to test the class.
 */
class AutoTesting : public Auto
{

public:


  /**
   * \fn AutoTesting (std::string& p_make, std::string& p_model, int p_year, int p_mileage, std::string& p_color, int p_numOfDoors, std::string& p_transmission, std::string& p_subtype, std::string& p_vin) : Auto ("ford", "f-150", 2003, 20300, "black", 2, "automatic", "truck" "XDEDE34674347683")
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
  AutoTesting (const std::string& p_make, const std::string& p_model, const int p_year, const int p_mileage, const std::string& p_color, const int p_numOfDoors, const std::string& p_transmission, const std::string& p_subtype, const std::string& p_vin) : Auto (p_make, p_model, p_year, p_mileage, p_color, p_numOfDoors, p_transmission, p_subtype, p_vin) { };


} ;


/**
 * Test of the Auto Constructor
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
 *                  invalid number of doors (0 and under)
 *                  invalid number of doors (Null)
 *                  invalid number of doors (over 5)
 *                  invalid transmission (empty)
 *                  invalid subtype (empty)
 *                  invalid vin (empty)
 *                  invalid vin (invalid vin)
 */


TEST (AutoTesting, ValidConstructorParam)

{
  AutoTesting f_testor = AutoTesting ("ford", "focus", 2004, 124500, "black", 2, "automatic", "auto", "XYZSED1234567");

  EXPECT_EQ (f_testor.reqMake (), "ford");
  EXPECT_EQ (f_testor.reqModel (), "focus");
  EXPECT_EQ (f_testor.reqYear (), 2004);
  EXPECT_EQ (f_testor.reqMileage (), 124500);
  EXPECT_EQ (f_testor.reqColor (), "black");
  EXPECT_EQ (f_testor.reqNumOfDoors (), 2);
  EXPECT_EQ (f_testor.reqTransmission (), "automatic");
  EXPECT_EQ (f_testor.reqSubtype (), "auto");
  EXPECT_EQ (f_testor.reqVin (), "XYZSED1234567");
};


TEST (AutoTesting, invalidConstructorMakeEmpty)
{
  ASSERT_THROW (AutoTesting ("", "focus", 2004, 124500, "black", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorMakeNumber)
{
  ASSERT_THROW (AutoTesting ("for44d", "focus", 2004, 124500, "black", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorModelEmpty)
{
  ASSERT_THROW (AutoTesting ("ford", "", 2004, 124500, "black", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorYearTooLow)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 1800, 124500, "black", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorYearTooHigh)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2030, 124500, "black", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorYearNull)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", NULL, 124500, "black", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorMileageNull)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2004, NULL, "black", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorMileageTooLow)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2004, -25, "black", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorMileageZero)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2004, 0, "black", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorMileageTooHigh)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2004, 1000001, "black", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorColorEmpty)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2004, 124500, "", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorColorContainsNumber)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2004, 124500, "bl4ck", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorNumDoorsUnderZero)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2004, 124500, "black", -1, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorNumDoorsTooHigh)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2004, 124500, "black", 6, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorTransmissionEmpty)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2004, 124500, "black", 2, "", "auto", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting, invalidConstructorSubtypeEmpty)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2004, 124500, "black", 2, "automatic", "", "XYZSED1234567"), PreconditionException);
};


TEST (AutoTesting,  invalidConstructorVinEmpty)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2004, 124500, "black", 2, "automatic", "auto", ""), PreconditionException);
};


TEST (AutoTesting, invalidConstructorVinNotValid)
{
  ASSERT_THROW (AutoTesting ("ford", "focus", 2004, 124500, "black", 2, "automatic", "auto", "XYZSED1234567"), PreconditionException);
};