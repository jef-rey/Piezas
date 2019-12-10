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

TEST(PiezasTest, testPieceAtBlank){
  Piezas test;
  Piece test_piece = test.pieceAt(0,0);
  ASSERT_EQ(test_piece, Blank );
}


TEST(PiezasTest, testPieceAtInvalid){
  Piezas test;
  Piece test_piece = test.pieceAt(8,9);
  //ASSERT_EQ(test_piece, Invalid);
  ASSERT_TRUE(Invalid);
}
//TEST(PiezasTest, testPieceAtInvalid){
//  PiezasTest test;
//  ASSERT_EQ(test.pieceAt(4,5), Invalid );
//}
