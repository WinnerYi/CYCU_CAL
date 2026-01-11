#include <stdio.h>

int main() {

 int n1, n2 = 0;
 while (1) {
    scanf("%d", &n1);
    if (n1 == -99999) {
            return 0;
    }

    else {
        scanf("%d", &n2);
        int found = -1; // 初始設為 -1，若沒有找到符合條件的數字，輸出 -1
        int i = n1 - 1;//介於兩數之間(不包括此兩數)、最大的、13的倍數
        while (i > n2) {
            if(i % 13 == 0) {
                found = i;
                break;
            }
            i--;
        }
        printf("%d\n", found);
    }
 }

  return 0;
}
