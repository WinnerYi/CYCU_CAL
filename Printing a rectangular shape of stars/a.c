#include <stdio.h>

int main(){
    int length;
    int width;
    scanf("%d %d", &length, &width);
    if (width < 0 || length < 0) {
      printf("Input error.");
      return 0;
    }

    if (width == 0 || length == 0) {
    return 0;
    }
    int i = 0;

    while(i<length) {
        int j = 0;
        while (j<width) {
           printf("*");
           j++;
        }
        if (i != length-1) { // 當不是最後一行時，輸出換行符號來準備下一行
            printf("\n");
        }
        i++;
    }

  return 0;
}
