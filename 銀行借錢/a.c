#include <stdio.h>
#include <string.h>
struct Information{
  char bank[15];
  int money;
};

typedef struct Information Information;

int main() {
  Information b[10];
  int n, m;  //n:最多打算跟幾家銀行貸款  m: 此企業要借的金額
  scanf("%d %d", &n, &m);
  
  int i = 0;
  while (scanf("%s %d", b[i].bank, &b[i].money) != EOF) {
    i++;
}

  int total_bank = i;
  for (int i = 0; i < total_bank-1; i++) {  // 金額由大到小排序 🫧
    for (int j = 0; j < total_bank - i - 1; j++){
      if (b[j].money < b[j+1].money) {
        Information temp = b[j];
        b[j] = b[j+1];
        b[j+1] = temp;
      }
    }
  }

  int total = 0;//計算是否可以借到足夠的金額
  for (int i = 0; i < n; i++) {
    total += b[i].money;
  }
  if (total < m) printf("not enough!");

  else {
    int k = 0;
    int totalm = m;
    while(k < n && m > 0) {
      m -= b[k].money;
      if (m < 0) {
        b[k].money = totalm;
      }

      totalm = m;
      k++;
    }
    printf("\n%d\n", k);
    for (int i = 0; i < k; i++) {
      printf("%s %d\n", b[i].bank, b[i].money);
    }
  }
  return 0;
}