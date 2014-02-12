char letter(int r, int c)
{
   if((r==c)||(r+c==6))
   {
      return 'X';
   }
   else
   {
      return 'O';
   }
}
