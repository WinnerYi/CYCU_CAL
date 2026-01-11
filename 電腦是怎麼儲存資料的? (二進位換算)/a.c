#include <stdio.h>

int main() {
    int n;
    int math = 1;
    int temp;

    printf("請輸入一個正整數：");
    scanf("%d", &n);

    // 找出不超過 n 的最大 2 的次方
    while (math <= n) {
        math *= 2;
    }
    math /= 2;

    // 進行二進位轉換
    while (math > 0) {
        temp = n / math;   // 0 或 1
        n = n % math;
        printf("%d", temp);
        math /= 2;
    }

    printf("\n");
    return 0;
}

