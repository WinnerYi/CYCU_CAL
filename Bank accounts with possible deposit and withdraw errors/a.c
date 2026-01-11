#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 定義一個新型別，Str50 為一個可以存放 50 字元的字元陣列
typedef char Str50[50];

// 定義一個結構體 Customer，用於表示客戶資訊
struct Customer {
  Str50 name;    // 客戶姓名
  int id;        // 客戶編號
  int balance;   // 客戶存款餘額
};

// 定義一個客戶陣列型別，可存放最多 200 個客戶
typedef struct Customer CustomerArray[200];

// 檢查並處理帳戶的存取款操作
void CheckAccount(int num_of_customer, CustomerArray cus_arr) {
  char action[10];           // 存放用戶操作 (如 "deposit" 或 "withdraw")
  bool is_real_account;      // 用於確認帳戶是否存在
  int id;                    // 操作的帳戶 ID
  int money;                 // 操作的金額

  // 持續讀取用戶操作，直到輸入 "-1" 結束
  while (1) {
    scanf("%s", action);    // 讀取操作類型
    if (strcmp(action, "-1") == 0) break;  // 若輸入 "-1"，結束操作
    scanf("%d %d", &id, &money);  // 讀取帳戶 ID 和金額
    is_real_account = false;

    // 檢查帳戶是否存在
    for (int i = 0; i < num_of_customer; i++) {
      if (id == cus_arr[i].id) {
        is_real_account = true;  // 帳戶存在
        if (strcmp(action, "deposit") == 0) {
          cus_arr[i].balance += money;  // 存款操作
        } else if (strcmp(action, "withdraw") == 0) {
          if (money > cus_arr[i].balance) {
            // 提款金額超過餘額，提示不足
            printf("Insufficient balance: %d\n", cus_arr[i].id);
          } else {
            cus_arr[i].balance -= money;  // 提款操作
          }
        }
      }
    }

    // 若帳戶不存在，提示錯誤
    if (!is_real_account) {
      printf("No such account: %d\n", id);
    }
  }
}

// 顯示錯誤日誌或計算指定客戶的總存款
void ErrorLog(int err_num, char name[50], CustomerArray cus_arr, int num_of_customer) {
  int total = 0;          // 存放總存款金額
  bool is_a_person = true;  // 用於確認是否為有效的客戶

  if (err_num == 1) {
    // 若錯誤碼為 1，表示客戶不存在
    printf("No such person!\n");
    is_a_person = false;
  } else if (err_num == 0) {
    // 若錯誤碼為 0，表示客戶存在計算，該客戶的總存款
    for (int i = 0; i < num_of_customer; i++) {
      if (strcmp(name, cus_arr[i].name) == 0) {
        total += cus_arr[i].balance;
      }
    }
  }

  // 若客戶存在，顯示客戶名稱及總存款
  if (is_a_person) {
    printf("%s : %d\n", name, total);
  }
}

// 讀取所有客戶的基本資訊
int Read(CustomerArray cus_arr) {
  int i = 0;  // 用於計數，表示目前輸入的客戶數量

  // 持續讀取客戶資訊，直到輸入 "-1" 表示結束
  while (1) {
    scanf("%s", cus_arr[i].name);  // 讀取客戶名稱
    if (strcmp(cus_arr[i].name, "-1") == 0) break;  // 若名稱為 "-1"，結束輸入
    scanf("%d %d", &cus_arr[i].id, &cus_arr[i].balance);  // 讀取客戶編號和餘額
    i++;  // 增加客戶數量計數
  }
  return i;  // 返回客戶總數
}

// 處理客戶名稱查詢，檢查是否存在該名稱的客戶
int Process(char name[50], CustomerArray cus_arr, int num_of_customer) {
  int err_num = 1;  // 初始錯誤碼為 1 (表示客戶不存在)

  // 遍歷客戶陣列，檢查是否有名稱匹配的客戶
  for (int i = 0; i < num_of_customer; i++) {
    if (strcmp(name, cus_arr[i].name) == 0) {
      err_num = 0;  // 若找到匹配的客戶，設置錯誤碼為 0
    }
  }
  return err_num;  // 返回錯誤碼
}

int main() {
  CustomerArray cus_arr;  // 定義客戶陣列
  int num_of_customer = Read(cus_arr);  // 讀取所有客戶資訊
  CheckAccount(num_of_customer, cus_arr);  // 處理帳戶存取款操作

  char name[50];  // 用於存放查詢的客戶名稱
  scanf("%49s", name);  // 讀取客戶名稱
  int err_num = Process(name, cus_arr, num_of_customer);  // 查詢客戶是否存在
  ErrorLog(err_num, name, cus_arr, num_of_customer);  // 顯示結果或錯誤資訊
  return 0;  // 結束程式
}