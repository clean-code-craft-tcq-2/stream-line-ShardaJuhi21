#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentManagement.h"
#define MAX_NUMBER_OF_READINGS 150

TEST_CASE("detect the ranges and output the number of readings in each range") {
  bool expectedVal = TRUE;
  bool retVal ;
  int anArray[] ={5,3,4,10,11,12};
     int n = sizeof(anArray) / sizeof(anArray[0]);
     
  GIVEN( "An Array is not sorted" ) {

       // Validate one use case for the GIVEN object
       WHEN( " DetectRange() is called" ) {
            retVal = DetectRange(anArray, n);

            THEN( "whether the function returns true or not" ) {
                REQUIRE( retVal == expectedVal );
            }
        }
    }
  
  int Readings[] ={3,3,4,5,10,11,12};
       int sizeofReadingArray = sizeof(Readings) / sizeof(Readings[0]);
     
   GIVEN( "An Array is sorted but it has repeated numbers" ) {

       // Validate one use case for the GIVEN object
       WHEN( " DetectRange() is called" ) {
            retVal = DetectRange(Readings, sizeofReadingArray);

            THEN( "whether the function returns true or not" ) {
                REQUIRE( retVal == expectedVal );
            }
        }
    }
  
  
 }

TEST_CASE("Convert in A2D") {
  bool expectedVal = TRUE;
  bool retVal ;
 int Array[] ={5,3,4,10,11,12,7,8,9,1,2,3};
int sizeofReadingArray = sizeof(Array) / sizeof(Array[0]);
     
  GIVEN( "An Array is 12 bit Array" ) {

       // Validate one use case for the GIVEN object
       WHEN( "Sensors() is called" ) {
            retVal = Sensors(Array, sizeofReadingArray);

            THEN( "whether the function returns true or not" ) {
                REQUIRE( retVal == expectedVal );
            }
        }
    }
  
  int Reading[] ={5,3,4,10,11,12,7,8,9,1};
       int ReadingArray = sizeof(Reading) / sizeof(Reading[0]);
     
   GIVEN( "An Array is sorted but it has repeated numbers" ) {

       // Validate one use case for the GIVEN object
       WHEN( " Sensors() is called" ) {
            retVal = Sensors(Reading,ReadingArray);

            THEN( "whether the function returns true or not" ) {
                REQUIRE( retVal == expectedVal );
            }
        }
    }
  
  
 }

