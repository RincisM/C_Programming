#include <stdio.h> 
 int main() 
 { 
     int i, n, pos, a[100]; 
     printf("\nEnter the size of the array:"); 
     scanf("%d",&n); 
     printf("\nEnter the elements of the array: "); 
   for(i=0;i<n;i++) 
   { 
     scanf("%d", &a[i] ); 
   } 
     printf("\nEnter the position from which the number has to be deleted: "); 
     scanf ("%d", &pos); 
   for(i= pos; i<n;i++) 
   { 
     a[i] = a[i+1];  
   }
   n--;  
   printf("\n The array after deletion is:\n");
     for(i=0;i<n;i++) 
     { 
       printf("%d ",a[i]); 
     }
       return 0; 
 }