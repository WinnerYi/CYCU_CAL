#include <stdio.h>

int PRIME(int num) { //質數定義為在大於1的自然數中，除了1和它本身以外不再有其他因數。
  for (int count = 2; count < num; count++) {
    if (num % count == 0) {
      return 0;   // 如果能被 count 整除，則 num 不是質數
    }
  }
  return 1;  //如果沒有能整除的數，則 num 是質數
}

int PRIME_FACTOR(int num) {
  int count = 0 ;
  for (int factor = 1; factor <= num; factor++) {
    if (num % factor == 0 && PRIME(factor)) {
      count++;
    }
  }
  return count;
}

int main() {
  int num = 0;
  int count = 0;
  scanf("%d", &num);
  if (num == 1) {
    printf("1不是質數");
    return 0;
  }
  count = PRIME_FACTOR(num);
  printf("%d", count);

  return 0;
}
