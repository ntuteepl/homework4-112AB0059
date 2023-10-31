#include <stdio.h>
#include <string.h>

struct Account {
    char username[4];
    char password[4];
    int balance;
};

int main() {
    int N;
    printf("請輸入測試案例數N：\n");
    scanf("%d", &N);

    struct Account accounts[] = {
        {"123", "456", 9000},
        {"456", "789", 5000},
        {"789", "888", 6000},
        {"336", "558", 10000},
        {"775", "666", 12000},
        {"566", "221", 7000}
    };

    for (int i = 0; i < N; i++) {
        char username[4];
        char password[4];

        printf("請輸入帳號和密碼：\n");
        scanf("%s %s", username, password);

        int found = 0;
        int balance = 0;

        for (int j = 0; j < sizeof(accounts) / sizeof(accounts[0]); j++) {
            if (strcmp(username, accounts[j].username) == 0 && strcmp(password, accounts[j].password) == 0) {
                found = 1;
                balance = accounts[j].balance;
                break;
            }
        }

        if (found) {
            printf("該帳戶餘額： %d\n", balance);
        } else {
            printf("error\n");
        }
    }

    return 0;
}
