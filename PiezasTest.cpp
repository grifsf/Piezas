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
  Piece mypiece1= myboard.dropPiece(2);
  Piece mypiece2= myboard.dropPiece(2);
  Piece mypiece3= myboard.dropPiece(2);
  Piece mypiece4= myboard.dropPiece(2);
	ASSERT_EQ(mypiece4,Blank);
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
  Piece mypiece= myboard.dropPiece(8);
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
  Piece mypiece1= myboard.dropPiece(0);//x
  Piece mypiece2= myboard.dropPiece(1);//o
  Piece mypiece3= myboard.dropPiece(2);//x
  Piece mypiece4= myboard.dropPiece(3);//o
  Piece mypiece5= myboard.dropPiece(0);//x
  Piece mypiece6= myboard.dropPiece(1);//o
  Piece mypiece7= myboard.dropPiece(2);//x
  Piece mypiece8= myboard.dropPiece(3);//o
  Piece mypiece9= myboard.dropPiece(0);//x
  Piece mypiece10= myboard.dropPiece(1);//o
  Piece mypiece12= myboard.dropPiece(2);//x
  Piece mypiece13= myboard.dropPiece(3);//o
  ASSERT_EQ(myboard.gameState(),Blank);
}
TEST(PiezasTest, gameStatexWin)
{
  Piezas myboard;
  Piece mypiece1= myboard.dropPiece(0);//x
  Piece mypiece2= myboard.dropPiece(0);//o
  Piece mypiece3= myboard.dropPiece(1);//x
  Piece mypiece4= myboard.dropPiece(1);//o
  Piece mypiece5= myboard.dropPiece(2);//x
  Piece mypiece6= myboard.dropPiece(0);//o
  Piece mypiece7= myboard.dropPiece(3);//x
  Piece mypiece8= myboard.dropPiece(3);//o
  Piece mypiece9= myboard.dropPiece(2);//x
  Piece mypiece10= myboard.dropPiece(1);//o
  Piece mypiece12= myboard.dropPiece(2);//x
  Piece mypiece13= myboard.dropPiece(3);//o
  ASSERT_EQ(myboard.gameState(),X);
}
TEST(PiezasTest, gameStateowin)
{
  Piezas myboard;
  Piece mypiece1= myboard.dropPiece(0);//x
  Piece mypiece2= myboard.dropPiece(0);//o
  Piece mypiece3= myboard.dropPiece(1);//x
  Piece mypiece4= myboard.dropPiece(1);//o
  Piece mypiece5= myboard.dropPiece(2);//x
  Piece mypiece6= myboard.dropPiece(2);//o
  Piece mypiece7= myboard.dropPiece(0);//x
  Piece mypiece8= myboard.dropPiece(3);//o
  Piece mypiece9= myboard.dropPiece(1);//x
  Piece mypiece10= myboard.dropPiece(3);//o
  Piece mypiece12= myboard.dropPiece(2);//x
  Piece mypiece13= myboard.dropPiece(3);//o
  ASSERT_EQ(myboard.gameState(),O);
}
TEST(PiezasTest, gameStatenotOver)
{
  Piezas myboard;
  Piece mypiece1= myboard.dropPiece(0);//x
  ASSERT_EQ(myboard.gameState(),Invalid);
}
