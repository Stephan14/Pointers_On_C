#include<stdio.h>

static int chessboard[8][8];

//判断能否攻击其他棋子
int attack_other( int row, int column )
{
  int i ;

  for ( i = 0; i < 8 && i != row ; i++ )
  {
    if ( chessboard[i][column] || chessboard[row][i] )
      return 1;
    if ( chessboard[i][column-(row-i)] && chessboard[i][column+(row-i)] )
      return 1;
  }

  return 0;
}

void print_chessboard()
{
  int row, column;
  for( row = 0; row < 8; row++ )
  {
    for( column = 0; column < 8; column++ )
    {
      printf("%d\t", chessboard[row][column]);
    }
    printf( "\n" );
  }
}

int conflicts( int row, int column )
{
  int i;
  for( i = 1; i < 8; i += 1 )
  {
    if( row - i >= 0 && chessboard[ row - i ][ column ] )
      return 1;
    if( column - i >= 0 && chessboard[ row ][ column - i ] )
      return 1;
    if( column + i < 8 && chessboard[ row ][ column + i ] )
      return 1;

    if( row - i >= 0 && column - i >= 0 && chessboard[ row - i ][ column - i ] )
      return 1;
    if( row - i >= 0 && column + i < 8 && chessboard[ row - i ][ column + i ] )
      return 1;
    }
    return 0;
}
void place_chess( int row )
{
  int column;

  for ( column = 0; column < 8; column++ )
  {
    chessboard[row][column] = 1;

    if ( row == 0 || !conflicts( row, column ) )
    {
      if( row < 7 )
      {
        place_chess( row+1 );
      }
      else
      {
        //print_chessboard();
      }
    }

    chessboard[row][column] = 0;
  }


}

int main(int argc, char const *argv[]) {

  printf("%d\n", attack_other( 1, 2) );
  place_chess(0);
  print_chessboard();
  return 0;
}
