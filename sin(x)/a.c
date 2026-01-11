#include <stdio.h>

/* 計算x! */
double Factorial(double x) {
  double result = 1.0;
  for (int i = 1; i <= x; i = i + 1) {
    result = result * i;
  }
  return result;
}

/* 計算x的n次方 */
double Power(double x, int n) {
  double result = 1.0;
  for (int i = 1; i <= n; i = i + 1) {
    result = result * x;
  }
  return result;
}

int main() {
  double x, order;
  scanf("%lf %lf", &x, &order);
  double sin_x = 0.0;
  int sign = 1;
  for (int n = 1; n <= order; n=n+2) { // 使用泰勒展開式計算 sin(x)
    sin_x += sign*(Power(x, n)/Factorial(n));
    sign *= -1 ;// 每一項的正負號交替
  }
  printf("%6f", sin_x); // 輸出計算結果，保留小數點後 6 位
  return 0;
}
