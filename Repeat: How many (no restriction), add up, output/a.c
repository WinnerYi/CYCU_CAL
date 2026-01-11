#include <stdio.h>
int main() {
    int n1;
    int n2;
    int total = 0;
    while (1) {
        scanf("%d", &n1);
        if (n1 == -99999) {
            break;
        }

        else {
            int count = 0;
            total = 0;
            while (count < n1) {
                scanf("%d", &n2);
                total += n2;
                count++;
            }
        printf("%d\n", total);
        }
    }
  return 0;
}