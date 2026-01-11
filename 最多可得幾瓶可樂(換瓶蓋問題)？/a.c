#include <stdio.h>

int main(){
    int money;
    int bottle;
    int total = 0;
    int cap;
    int new_bottle;
    scanf("%d", &money);
    bottle = money / 10;
    cap = bottle;
    total = bottle;// 最開始的總瓶數等於購買的瓶數
    while (cap >= 3) {
        new_bottle= cap / 3;
        total+=new_bottle;
        cap = cap % 3 + new_bottle;// 計算剩餘瓶蓋數：剩餘瓶蓋 + 新瓶的瓶蓋
    }
    printf("%d", total);

  return 0;
}