/*
 * \file  MotorcycleTestor.cpp
 * \author M4ST3R-Y0DA-44
 * \brief file containing the Motorcycle class tests
 *
 * \date reated on 14 décembre 2021, 02:03
 */

#include "Motorcycle.h"
#include "ExceptionContract.h"
#include <gtest/gtest.h>



using namespace VehiculeManager;


/**
 * Motorcycle class constructor test
 * Valid case:      all param are valid
 * Invalid cases:   invalid engine cc parameter (0)
 *                  invalid engine cc parameter (2501)
 *                  invalid bike categorie (empty)
 */

TEST (Motorcycle, ConstructorAllParamValid)
{
  Motorcycle motorcycleTestor = Motorcycle ("suzuki", "SV650s", 2001, 80018, "blue", "manual", "motorcycle", "ABCD1234567", 650, "touring");
  EXPECT_EQ (motorcycleTestor.reqMake (), "suzuki");
  EXPECT_EQ (motorcycleTestor.reqModel (), "SV650s");
  EXPECT_EQ (motorcycleTestor.reqYear (), 2001);
  EXPECT_EQ (motorcycleTestor.reqMileage (), 80018);
  EXPECT_EQ (motorcycleTestor.reqColor (), "blue");
  EXPECT_EQ (motorcycleTestor.reqTransmission (), "manual");
  EXPECT_EQ (motorcycleTestor.reqVin (), "ABCD1234567");
  EXPECT_EQ (motorcycleTestor.reqEnginecc (), 650);
  EXPECT_EQ (motorcycleTestor.reqBikeCategory (), "touring");
};


/*Invalid constructor parameter enginecc at zero*/
TEST (Motorcycle, InvalidParameterEngineccZero)
{
  ASSERT_THROW (Motorcycle ("suzuki", "SV650s", 2001, 80018, "blue", "manual", "motorcycle", "ABCD1234567", 0, "touring"), PreconditionException);
};


/*Invalid constructor parameter enginecc over 2500*/
TEST (Motorcycle, InvalidParameterEngineccTooHigh)
{
  ASSERT_THROW (Motorcycle ("suzuki", "SV650s", 2001, 80018, "blue", "manual", "motorcycle", "ABCD1234567", 2501, "touring"), PreconditionException);
};


/*Invalid constructor parameter Bike Category is empty*/
TEST (Motorcycle, InvalidParameterBikeCategory)
{
  ASSERT_THROW (Motorcycle ("suzuki", "SV650s", 2001, 80018, "blue", "manual", "motorcycle", "ABCD1234567", 650, ""), PreconditionException);
};

/**
 * \class MotorcycleTest
 * \brief class used to create a Motorcycle Object in order to test opur methods of the class
 */
class MotorcycleTest : public ::testing::Test
{

public:


  /**
   * \fn MotorcycleTest()
   * \constructor used to generate a Motorcycle object to test methods of the class
   */
  MotorcycleTest () : f_motorcycleTestor ("suzuki", "SV650s", 2001, 80018, "blue", "manual", "motorcycle", "ABCD1234567", 650, "touring") { };

  Motorcycle f_motorcycleTestor;

} ;


/*Test on method reqEnginecc()*/
TEST_F (MotorcycleTest, reqEnginecc)
{
  ASSERT_EQ (f_motorcycleTestor.reqEnginecc (), 650);
};


/*Test on method reqBikeCategory()*/
TEST_F (MotorcycleTest, reqBikeCategory)
{
  ASSERT_EQ (f_motorcycleTestor.reqBikeCategory (), "touring");
};


