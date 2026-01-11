#include <stdio.h>
#include <stdbool.h>
#include <string.h>
enum oper {
  INTERSECTION = 1,
  UNION = 2,
  Symmetric_difference = 3,
  Complement = 4,
};

int main () {
  int n;
  int a[20] = {0};
  int b[20] = {0};
  int result[20] = {0};
  while (true){
    scanf ("%d", &n);
    if (n == -1) break;
    a[n-1] = 1;
  }

  while (true){
    scanf ("%d", &n);
    if (n == -1) break;
    b[n-1] = 1;
  }

  int o;
  scanf("%d", &o);

  for (int i = 0; i < 20; i++) {
    if (o == INTERSECTION) result[i] = a[i] && b[i];
    else if (o == UNION) result[i] = a[i] || b[i];
    else if (o == Symmetric_difference) result[i] = (a[i] || b[i]) && !(a[i]&&b[i]);
    else if (o == Complement) result[i] = a[i] && !(a[i]&&b[i]);
  }

  for (int i = 0; i < 20; i++) {
    if (result[i] == 1) printf("%d ", i+1);
  }

  return 0;
}