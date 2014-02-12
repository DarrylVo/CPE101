char letter(int r, int c)
{
   if( (r>=2&&r<=5)&& (c>=4&&c<=9) )
   {
      if( (r>=4&&r<=5)&& (c>=7 && c<=9) )
      {
         return 'X';
      }
      else
      {
         return 'Z';
      }
   }
   else if( (r>=4&&r<=6)&& (c>=7 && c<=12))
   {
      if( (r>=4&&r<=5) && (c>=7 && c<=9))
      {
         return 'X';
      }
      else
      {
         return 'B';
      }
   }
   else
   {
      return 'T';
   }
}
