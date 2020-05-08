#include "Piezas.h"
#include <vector>
using std::vector;
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
  board = vector<vector<Piece> >(BOARD_ROWS,vector<Piece>(BOARD_COLS,Blank));
  turn=X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
  board = vector<vector<Piece> >(BOARD_ROWS,vector<Piece>(BOARD_COLS,Blank));
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    if(column>BOARD_ROWS||column<0)
    {
      return Invalid;
    }
    if(board[BOARD_ROWS-1][column]!=Blank)
    {
      return Blank;
    }
    for(int i=0;i<BOARD_ROWS;i++)
    {
      if(board[i][column]==Blank)
      {
        board[i][column]=turn;    
        break;
      }
    }
    Piece curpiece;
    if(turn==X)
    {
      curpiece=turn;
      turn=O;
    }
    else
    {
      curpiece=turn;
      turn=X;
    }
    return curpiece;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(row>BOARD_ROWS-1||column>BOARD_COLS-1||row<0||column<0)
    {
     return Invalid; 
    }
    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    int XMAX=0;
    int YMAX=0;
    for(int i=0;i<BOARD_COLS;i++)
    {
      if(board[BOARD_ROWS-1][i]==Blank)
      {
        return Invalid;
      }
    }
    //RIGHT and UP
    for(int row=0;row<BOARD_ROWS;row++)
    {
      Piece curpiece=board[row][0];
      int curlongest=0;
      for(int col=0; col<BOARD_COLS;col++)
      {
        if(board[row][col]==curpiece)
        {
          curlongest++;
          if(col==BOARD_COLS-1)
          {
            
            if(curpiece==X)
            {
              if(curlongest>XMAX)
              {
                XMAX=curlongest;
              }
            }
            else
            {
              if(curlongest>YMAX)
              {
                YMAX=curlongest;
              }
            }
          curpiece=board[row][col];
          curlongest=0;
          }
        }
        else
        {
          if(curpiece==X)
          {
            if(curlongest>=XMAX)
            {
              XMAX=curlongest;
            }
          }
          else
          {
            if(curlongest>=YMAX)
            {
              YMAX=curlongest;
            }
          }
          curpiece=board[row][col];
          curlongest=0;
        }
      }
    }
    //UP and RIGHT
    for(int col=0;col<BOARD_COLS;col++)
    {
      Piece curpiece=board[0][col];
      int curlongest=0;
      for(int row=0; row<BOARD_ROWS;row++)
      {
        if(board[row][col]==curpiece)
        {
          curlongest++;
          if(row==BOARD_ROWS-1)
          {
            
            if(curpiece==X)
            {
              if(curlongest>=XMAX)
              {
                XMAX=curlongest;
              }
            }
            else
            {
              if(curlongest>=YMAX)
              {
                YMAX=curlongest;
              }
            }
          curpiece=board[row][col];
          curlongest=0;
          }
        }
        else
        {
          if(curpiece==X)
          {
            if(curlongest>XMAX)
            {
              XMAX=curlongest;
            }
          }
          else
          {
            if(curlongest>YMAX)
            {
              YMAX=curlongest;
            }
          }
          curpiece=board[row][col];
          curlongest=0;
        }
      }
    }
    /*
    for(int i=0;i<XSTREAKS.size();i++)
    {
      if(XMAX<XSTREAKS[i])
      {
        XMAX=XSTREAKS[i];
      }
    }
    for(int i=0;i<OSTREAKS.size();i++)
    {
      if(YMAX<OSTREAKS[i])
      {
        YMAX=OSTREAKS[i];
      }
    }*/
    if(XMAX>YMAX)
    {
      return X;
    }
    if(YMAX>XMAX)
    {
      return O;
    }
    return Blank;
    /*
    for(int col=0;col<BOARD_COLS;col++)
    {
      Piece curstreak;
      int curlongest=0;
      for(int row=0;row<BOARD_ROWS;row++)
      {
        if(board[col][row]==curstreak) {
          curlongest++; 
          if(curstreak==X)
          {
            if(curlongest>XMAX)
            {
              XMAX=curlongest;
            }
          }
          else
          {
            if(curlongest>YMAX)
            {
              XMAX=curlongest;
            }
          }
        }
        else
        {
          curstreak=board[col][row];
          curlongest=0;
        }
      }
    }
    for(int row=0;row<BOARD_ROWS;row++)
    {
      Piece curstreak;
      int curlongest=0;
      for(int col=0;col<BOARD_COLS;col++)
      {
        if(board[col][row]==curstreak) {
          curlongest++; 
          if(curstreak==X)
          {
            if(curlongest>XMAX)
            {
              XMAX=curlongest;
            }
          }
          else
          {
            if(curlongest>YMAX)
            {
              XMAX=curlongest;
            }
          }
        }
        else
        {
          curstreak=board[col][row];
          curlongest=0;
        }
      }
    }
    */
}
