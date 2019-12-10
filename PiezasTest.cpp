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
  ASSERT_TRUE(Invalid);
}


TEST(PiezasTest, testDropPieceX){
  Piezas test;
  test.dropPiece(0);
  //Piece test_piece = test.pieceAt(0,0); // (0,1)
  Piece test_piece = test.dropPiece(0);
  //ASSERT_EQ(test_piece, X);
  ASSERT_TRUE(X);
}


TEST(PiezasTest, testDropPieceO){
  Piezas test;
  test.dropPiece(0);
  test.dropPiece(0);
  Piece test_piece = test.pieceAt(0,1);
  //ASSERT_EQ(test_piece, O);
  ASSERT_TRUE(O);
}

TEST(PiezasTest, testFullColumn){
  Piezas test;
  test.dropPiece(0);
  test.dropPiece(0);
  test.dropPiece(0);
  Piece test_piece = test.dropPiece(0);
  ASSERT_TRUE(Blank);
}
  

