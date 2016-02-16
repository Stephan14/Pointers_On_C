char buffer[SIZE]
char *front, *rear;
...
front = &buffer[0];
rear = &buffer[SIZE] - 1;
while ( front < rear ) {
  if( *front++ != *rear++ )
    break;
}
if ( front >= rear ) {
  printf("It is a palindrome\n" );
}
