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
TEST(PiezasTest, dropOne)
{
  Piezas myboard;
  Piece mypiece= myboard.dropPiece(2);
	ASSERT_EQ(mypiece,X);
}

TEST(PiezasTest, fullColumn)
{
  Piezas myboard;
  myboard.dropPiece(2);
  myboard.dropPiece(2);
  myboard.dropPiece(2);
  Piece mypiece= myboard.dropPiece(2);
	ASSERT_EQ(mypiece,Blank);
}
TEST(PiezasTest, dropX)
{
  Piezas myboard;
  Piece mypiece1= myboard.dropPiece(2);
	ASSERT_EQ(mypiece1,X);
}
TEST(PiezasTest, dropO)
{
  Piezas myboard;
  myboard.dropPiece(2);
  Piece mypiece= myboard.dropPiece(2);
	ASSERT_EQ(mypiece,O);
}
TEST(PiezasTest, dropXrightPlace)
{
  Piezas myboard;
  myboard.dropPiece(0);
  Piece mypiece = board.pieceAt(0,0);
	ASSERT_EQ(mypiece,X);
}
TEST(PiezasTest, dropORightPlace)
{
  Piezas myboard;
  myboard.dropPiece(0);
  myboard.dropPiece(0);
  Piece mypiece = board.pieceAt(1,0);
	ASSERT_EQ(mypiece,O);
}
TEST(PiezasTest, dropOOB)
{
  Piezas myboard;
  Piece mypiece= myboard.dropPiece(8);
	ASSERT_EQ(mypiece,Invalid);
}
TEST(PiezasTest, dropnegative)
{
  Piezas myboard;
  Piece mypiece= myboard.dropPiece(-8);
	ASSERT_EQ(mypiece,Invalid);
}
TEST(PiezasTest, reset)
{
  Piezas myboard;
  Piece mypiece= myboard.dropPiece(8);
  myboard.reset();
  for(int row=0;row<BOARD_ROWS;row++)
  {
    for(int col=0;col<BOARD_COLS;col++)
    {
      ASSERT_EQ(myboard.pieceAt(row,col),Blank);
    }
  }
}
TEST(PiezasTest, gameStatetie)
{
  Piezas myboard;
  myboard.dropPiece(0);//x
  myboard.dropPiece(1);//o
  myboard.dropPiece(2);//x
  myboard.dropPiece(3);//o
  myboard.dropPiece(0);//x
  myboard.dropPiece(1);//o
  myboard.dropPiece(2);//x
  myboard.dropPiece(3);//o
  myboard.dropPiece(0);//x
  myboard.dropPiece(1);//o
  myboard.dropPiece(2);//x
  myboard.dropPiece(3);//o
  ASSERT_EQ(myboard.gameState(),Blank);
}
TEST(PiezasTest, gameStatexWin)
{
  Piezas myboard;
   myboard.dropPiece(0);//x
   myboard.dropPiece(0);//o
   myboard.dropPiece(1);//x
   myboard.dropPiece(1);//o
   myboard.dropPiece(2);//x
   myboard.dropPiece(0);//o
   myboard.dropPiece(3);//x
   myboard.dropPiece(3);//o
   myboard.dropPiece(2);//x
   myboard.dropPiece(1);//o
   myboard.dropPiece(2);//x
   myboard.dropPiece(3);//o
  ASSERT_EQ(myboard.gameState(),X);
}
TEST(PiezasTest, gameStateowin)
{
  Piezas myboard;
  myboard.dropPiece(0);//x
  myboard.dropPiece(0);//o
  myboard.dropPiece(1);//x
  myboard.dropPiece(1);//o
  myboard.dropPiece(2);//x
  myboard.dropPiece(2);//o
  myboard.dropPiece(0);//x
  myboard.dropPiece(3);//o
  myboard.dropPiece(1);//x
  myboard.dropPiece(3);//o
  myboard.dropPiece(2);//x
  myboard.dropPiece(3);//o
  ASSERT_EQ(myboard.gameState(),O);
}
TEST(PiezasTest, gameStatenotOver)
{
  Piezas myboard;
  myboard.dropPiece(0);//x
  ASSERT_EQ(myboard.gameState(),Invalid);
}
TEST(PiezasTest, illegalPiecePositive)
{
  Piezas myboard;
  Piece mypiece= myboard.pieceAt(18,78);
	ASSERT_EQ(mypiece,Invalid);
}
TEST(PiezasTest, illegalPieceNegative)
{
  Piezas myboard;
  Piece mypiece= myboard.pieceAt(-18,-78);
	ASSERT_EQ(mypiece,Invalid);
}
TEST(PiezasTest, XwinsVertical)
{
  Piezas myboard;
  myboard.dropPiece(0);//x
  myboard.dropPiece(1);//o
  myboard.dropPiece(0);//x
  myboard.dropPiece(2);//o
  myboard.dropPiece(0);//x
  myboard.dropPiece(1);//o
  myboard.dropPiece(3);//x
  myboard.dropPiece(3);//o
  myboard.dropPiece(2);//x
  myboard.dropPiece(3);//o
  myboard.dropPiece(1);//x
  myboard.dropPiece(2);//o
  ASSERT_EQ(myboard.gameState(),X);
}
TEST(PiezasTest, OwinsVertical)
{
  Piezas myboard;
  myboard.dropPiece(0);//x
  myboard.dropPiece(2);//o
  myboard.dropPiece(0);//x
  myboard.dropPiece(2);//o
  myboard.dropPiece(1);//x
  myboard.dropPiece(2);//o
  myboard.dropPiece(3);//x
  myboard.dropPiece(0);//o
  myboard.dropPiece(3);//x
  myboard.dropPiece(1);//o
  myboard.dropPiece(1);//x
  myboard.dropPiece(3);//o
  ASSERT_EQ(myboard.gameState(),O);
}
