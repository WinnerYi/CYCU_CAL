//Q1: 把一段輸入的英文字母做大小寫轉換。
#include <stdio.h>

int main() {
char c;
while (1) {

    scanf("%c", &c);
     if ((c == '.')||(c == '!')) {
        printf("%c", c);
        break;
    }

    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';// 小寫字母轉換為大寫
    }

    else if (c >= 'A' && c <= 'Z') {
        c = c - 'A' + 'a';// 大寫字母轉換為小寫
    }

    printf("%c", c);
}

return 0;

}