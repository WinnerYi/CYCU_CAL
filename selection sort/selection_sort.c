#include <stdio.h>
struct Person {
  char id;
  int salary;
  };

int Locatemax (int start, struct Person p[], int n) { //找出最大的 在哪個位置
  int locate = start;
  int max = p[start].salary;
  for (int i = start + 1; i < n; i++) {
    if (p[i].salary > max) {
        locate = i;        
        max = p[i].salary;
    }
  }
  return locate;
}

int main() {
  int n = 0;
  printf("請問要輸入幾筆人的數據?  ");
  scanf("%d", &n);
  struct Person p[n];
  for (int i = 0; i < n; i++) { //輸入人員資料
    scanf(" %c", &p[i].id); 
    scanf("%d", &p[i].salary);
  }

  for (int i = 0; i < n-1; i++) {   //選擇排序法
    int locatemax = Locatemax(i, p, n);
    struct Person temp = p[i];  //交換兩個數字
    p[i] = p[locatemax];
    p[locatemax] = temp;
  }

  printf("selecting sort 由薪水高到低\n");
  for (int i =0; i < n; i++) {
    printf("%c %d\n", p[i].id, p[i].salary);
  }

  return 0;
}
