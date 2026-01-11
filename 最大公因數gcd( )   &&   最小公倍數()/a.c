#include <stdio.h>

int main() {
  int n1;
  int n2;

  scanf("%d %d", &n1, &n2);
 
 // 使用輾轉相除法來計算最大公因數
  while (n2 != 0) {
    int temp = n2; // 暫存 n2 的值，因為下一步會修改 n2
    n2 =n1 % n2; // 計算 n1 除以 n2 的餘數，並將結果存入 n2
    n1=temp;    // 將 n1 設為剛才暫存的 n2 值
  }
  printf("%d", n1);// 當 n2 變成 0 時，n1 就是最大公因數

  return 0;
}
