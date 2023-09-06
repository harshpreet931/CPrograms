#include<stdio.h> 
 enum  day{Mon, Tue, Wed, Thu, Fri, Sat, Sun};
  
int main() 
{ 
  // Declare variables of enum type
    enum day today, tomorrow; 
 // Assign values
    today = Wed;
    tomorrow = Thu;
 // Print values
    printf("Today is day number %d\n", today);
     printf("Tomorrow is day number %d\n", tomorrow);
return 0;
}                                          
