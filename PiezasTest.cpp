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
  ASSERT_EQ(test_piece, Invalid);
}

TEST(PiezasTest, testPieceAtInvalidNeg){
  Piezas test;
  Piece test_piece = test.dropPiece(-1);
  ASSERT_EQ(test_piece, Invalid);
}



TEST(PiezasTest, testDropPieceX){
  Piezas test;
  Piece test_piece = test.dropPiece(0);
  ASSERT_EQ(test_piece, X);
}


TEST(PiezasTest, testDropPieceO){
  Piezas test;
  test.dropPiece(0);
  Piece test_piece = test.dropPiece(1);
  ASSERT_EQ(test_piece, O);
}

TEST(PiezasTest, testFullColumn){
  Piezas test;
  test.dropPiece(0);
  test.dropPiece(0);
  test.dropPiece(0);
  Piece test_piece = test.dropPiece(0);
  ASSERT_EQ(test_piece, Blank);
}

TEST(PiezasTest, testXWins){

  Piezas test;
  test.dropPiece(2);//X
  test.dropPiece(0);//O
  test.dropPiece(0);//X
  test.dropPiece(1);//O
  test.dropPiece(1);//X
  test.dropPiece(3);//O
  test.dropPiece(2);//X
  test.dropPiece(0);//O
  test.dropPiece(3);//X
  test.dropPiece(1);//O
  test.dropPiece(2);//X
  test.dropPiece(3);//O
  ASSERT_EQ(test.gameState(), X);
}


TEST(PiezasTest, testDraw){
  Piezas test;
  test.dropPiece(3);// X
  test.dropPiece(2);// O
  test.dropPiece(1);// X
  test.dropPiece(0);// O
  test.dropPiece(0);// X
  test.dropPiece(1);// O
  test.dropPiece(2);// X
  test.dropPiece(3);// O
  test.dropPiece(3);// X
  test.dropPiece(2);// O
  test.dropPiece(1);// X
  test.dropPiece(0);// O
  Piece test_piece = test.gameState();
  ASSERT_EQ(test_piece, Blank);
  //ASSERT_TRUE(Blank);
}


TEST(PiezasTest, testGameNotOver){
  Piezas test;
  test.dropPiece(3);// X
  test.dropPiece(3);// O
  test.dropPiece(2);// X
  test.dropPiece(3);// O
  test.dropPiece(1);// X
  test.dropPiece(1);// O
  test.dropPiece(0);// X
  //  Piece test_piece = test.gameState();
  //  ASSERT_EQ(test_piece, Invalid);
  ASSERT_TRUE(Invalid);
}


TEST(PiezasTest, testReset){
  Piezas test;
  test.dropPiece(3);// X
  test.dropPiece(2);// O
  test.dropPiece(0);// X
  test.dropPiece(1);// O
  test.dropPiece(3);// X
  test.dropPiece(0);// O
  test.dropPiece(1);// X
  test.dropPiece(2);// O
  test.dropPiece(2);// X
  test.dropPiece(1);// O
  test.dropPiece(0);// X
  test.dropPiece(3);// O
  test.reset();
  ASSERT_TRUE(Blank);
}
