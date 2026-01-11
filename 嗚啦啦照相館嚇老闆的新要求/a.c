#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
int main() {
  char name[151] = "";
  char input[31] = "";
  int to = 0;
  char ch;
  char from_array[31] = "";
  int k = 0;
  int j = 0;
  bool from_end = false;
  while (true) {
    scanf("%s", input);
    if (input[0] == '-' || (input[0] <= '9' && input[0] >= '0')) {
      strcat(from_array, input);
      break;
    }
    strcat(name, input);
  }

  int from = atoi(from_array);
  if (from < 0) {
    printf("Input format error : %d\n", from);
    return 0;
  } 
  scanf("%d", &to);
  if (to < 0) {
    printf("Input format error : %d\n", to);
    return 0;
  }
  if (to < from) {
    printf("Input format error : %d\n", to);
    return 0;
  }

  for (int i = from; i <= to ; i++) {
    printf("%s%d\n", name, i);
  }
  return 0;
}
