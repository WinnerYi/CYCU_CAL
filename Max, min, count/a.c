#include <stdio.h>

int main(){
    int maximum;
    int minimum;
    int n1;
    int count = 0;
    int n2;
    scanf("%d", &n1);
    if(n1 == 9999) {
        printf("NA\nNA\n0");
    }
    maximum = minimum = n1;
    count++;
    while (1) {
        scanf("%d", &n2);
        if(n2 == 9999) {
          break;
        }
        else if(n2 > maximum){
            maximum = n2;
        }
        else if(n2 < minimum) {
            minimum = n2;
        }
        count++;
    }
    printf("%d %d %d", maximum, minimum,  count);

  return 0;
}