//Q2: 把一段輸入的文字做首字轉成大寫。如果該首字已經是大寫就不處理。輸入的最後有一個
#include <stdio.h>
int main() {
char c;
int captal_word = 1;// 定義標誌變量，用於檢查是否需要將首字母大寫

while (1) {

    scanf("%c", &c);
     if ((c == '.')||(c == '!')) {
        printf("%c", c);
        break;
    }

    if (c == ' ') {  // 如果遇到空格，則直接打印並將首字母標誌設為1
        printf(" ");
        captal_word = 1;
    }

         // 如果標誌為1且字符是小寫字母，則將其轉換為大寫
    if (captal_word  && c >= 'a' && c <= 'z') {   
        c = c - 'a' + 'A';
        captal_word = 0;  // 首字母已經大寫，將標誌設為0
    }
    printf("%c", c);
}

return 0;

}