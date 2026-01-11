#include <stdio.h>
#include <string.h>
struct Information{
  char city[15];
  int money;
};

struct Total {  // 定義用於存放匯總結果的結構體
  char city[15];
  int money;
};



typedef struct Information Information;
typedef struct Total Total;

int main() {
  Information b[15];
  Total t[15];

  int i = 0;
  while(1) {
    scanf("%s",b[i].city);
    if (strcmp(b[i].city, "END") == 0) break;
    scanf("%d",&b[i].money);
    i++;
  }
  int input_city = i;  //  冒泡排序：按城市名稱字典序對輸入數據排序
  for (int i = 0; i < input_city-1; i++) {  //
    for (int j = 0; j < input_city - i - 1; j++){
      if (strcmp(b[j].city, b[j+1].city) > 0) {
        Information temp = b[j];
        b[j] = b[j+1];
        b[j+1] = temp;
      }
    }
  }
  int diff = 0;
  strcpy(t[0].city, b[0].city);
  t[0].money = b[0].money;

  for (int i = 1; i < input_city; i++) {
    if (strcmp(b[i].city, t[diff].city) == 0) {
      t[diff].money += b[i].money;
    }

    else {  // 如果是新城市，將其加入匯總陣列
      diff++;
      strcpy(t[diff].city, b[i].city);
      t[diff].money = b[i].money;
    }
  }
  printf("\n");
  for (int i = 0; i <diff+1; i++) {
    printf("%s %d\n", t[i].city, t[i].money);
  }

  return 0;
}