#include <stdio.h>

int main(){
  int n=0;
  scanf("%d", &n);
  int mid = n/2 ;

  for (int i=0; i<=mid; i++){
     for (int j=0; j<=mid-i; j++){
        printf(" ");
     }
     printf("*");

     if (i>0) {

       for (int k =0; k<2*i-1; k++) {
           printf(" ");
       }
       printf("*");
     }
     printf("\n");
  }

   for (int i=mid-1; i>=0; i-- ) {
       for (int j=0; j<=mid-i; j++) {
         printf(" ");
       }
       printf("*");

       if (i >0) {
         for(int k=0; k<2*i-1;k++){
           printf(" ");
         }
        printf("*");
       }

      printf("\n");
   }
   return 0;
}
