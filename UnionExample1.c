#include <stdio.h>
#include <string.h>
 union Data
 {
     int i;
     float f;
     char str[20];
};
int main()
{ 
  union Data d;        
   d.i = 10; 
   d.f = 220.5;
   strcpy( d.str, "C Programming");
  printf( "d.i : %d\n", d.i);
   printf( "d.f : %f\n", d.f);
   printf( "d.str : %s\n", d.str);
}
