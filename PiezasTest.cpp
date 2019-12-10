/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

//TEST(PiezasTest, testPieceAtBlank){
//  PiezasTest test;
//  ASSERT_EQ(test.pieceAt(0,0), Blank );
//}
//
//TEST(PiezasTest, testDropPieceO){
//  PiezasTest test;
//  test.dropPiece(column);
//  ASSERT_EQ(test.dropPiece(), X);
//}
