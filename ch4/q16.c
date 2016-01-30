void printCurrentWeather(int preciptating, int temperature )
{
  if( preciptating == 1)
  {
    if( temperature < 32 )
    {
      printf( "snowing\n" );
    }
    else if( temperature >= 32 )
    {
      printf( "raining\n" );
    }
  }
  else
  {
    if( temperature < 60 )
    {
      printf( "cold\n" );
    }
    else if( temperature >= 60 )
    {
      printf( "warm\n" );
    }
  }
}
