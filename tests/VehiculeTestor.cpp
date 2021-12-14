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


/*Test for constructor with all valid parameters*/
TEST (Vehicule, ValidConstructorParam)

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


/*Invalid Constructor with empty make parameter*/
TEST (Vehicule, invalidConstructorMakeEmpty)
{
  ASSERT_THROW (VehiculeTesting ("", "focus", 2004, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalid Construcxtor with a number in the make parameter field*/
TEST (Vehicule, invalidConstructorMakeNumber)
{
  ASSERT_THROW (VehiculeTesting ("for44d", "focus", 2004, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalid constructor with empty model field*/
TEST (Vehicule, invalidConstructorModelEmpty)
{
  ASSERT_THROW (VehiculeTesting ("ford", "", 2004, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalid constructor with year too low to fit on scale*/
TEST (Vehicule, invalidConstructorYearTooLow)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 1800, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalid constructor with year too high to fit on scale*/
TEST (Vehicule, invalidConstructorYearTooHigh)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2030, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalid constructor with Year null*/
TEST (Vehicule, invalidConstructorYearNull)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", NULL, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalid constructor with mileage null*/
TEST (Vehicule, invalidConstructorMileageNull)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, NULL, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalid constructor with mileage too low*/
TEST (Vehicule, invalidConstructorMileageTooLow)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, -25, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalid constructor with mileage at zero*/
TEST (Vehicule, invalidConstructorMileageZero)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 0, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalid constructor with mileage too high*/
TEST (Vehicule, invalidConstructorMileageTooHigh)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 1000001, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalid constructor with empty color parameter*/
TEST (Vehicule, invalidConstructorColorEmpty)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 124500, "", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalid constructor with a color parameter containing a number*/
TEST (Vehicule, invalidConstructorColorContainsNumber)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 124500, "bl4ck", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalide constructor with empty transmission parameter*/
TEST (Vehicule, invalidConstructorTransmissionEmpty)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 124500, "black", "", "auto", "XYZSED1234567"), PreconditionException);
};


/*Invalid constructor with empty subtype parameter*/
TEST (Vehicule, invalidConstructorSubtypeEmpty)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 124500, "black", "automatic", "", "XYZSED1234567"), PreconditionException);
};


/*Invalid constructor with empty vin parameter*/
TEST (Vehicule,  invalidConstructorVinEmpty)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 124500, "black", "automatic", "auto", ""), PreconditionException);
};


/*Inavlid constructor with invalid vin parameter*/
TEST (Vehicule, invalidConstructorVinNotValid)
{
  ASSERT_THROW (VehiculeTesting ("ford", "focus", 2004, 124500, "black", "automatic", "auto", "XYZSED1234567"), PreconditionException);
};

/**
 * \class VehiculeTesto
 * \brief class used to test methods of the vehicule class.
 */
class VehiculeTestor : public ::testing::Test
{

public:


  /**\fn VehiculeTestor()
   * \brief constructor used to generate VehiculeTesting objects.
   */
  VehiculeTestor () : f_VehiculeTestor ("ford", "focus", 2004, 124500, "black", "automatic", "auto", "XYZSED1234567") { };

  VehiculeTesting f_VehiculeTestor;
} ;


/*Test for method reqMake()*/
TEST_F (VehiculeTestor, reqMake)
{
  ASSERT_EQ ("ford", f_VehiculeTestor.reqMake ());
};


/*Test for method reqModel()*/
TEST_F (VehiculeTestor, reqModel)
{
  ASSERT_EQ ("focus", f_VehiculeTestor.reqModel ());
};


/*Test for method reqYear()*/

TEST_F (VehiculeTestor, reqYear)
{
  ASSERT_EQ (2004, f_VehiculeTestor.reqYear ());
};


/*Test for method reqMileage()*/
TEST_F (VehiculeTestor, reqMileage)
{
  ASSERT_EQ (124500, f_VehiculeTestor.reqMileage ());
};


/*Test for method reqColor()*/
TEST_F (VehiculeTestor, reqcolor)
{
  ASSERT_EQ ("black", f_VehiculeTestor.reqColor ());
};


/*Test for method reqTransmission()*/
TEST_F (VehiculeTestor, reqTransmission)
{
  ASSERT_EQ ("automatic", f_VehiculeTestor.reqTransmission ());
};


/*Test for method reqSubtype()*/
TEST_F (VehiculeTestor, reqSubtype)
{
  ASSERT_EQ ("auto", f_VehiculeTestor.reqSubtype ());
};


/*Test for method reqVin()*/
TEST_F (VehiculeTestor, reqVin)
{
  ASSERT_EQ ("XYZSED1234567", f_VehiculeTestor.reqVin ());
};


/*Test for method reqInfoTitle()*/
TEST_F (VehiculeTestor, reqInfoTitle)
{
  ASSERT_EQ ("2004 ford focus", f_VehiculeTestor.reqInfoTitle ());
};