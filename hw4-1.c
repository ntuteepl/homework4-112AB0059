#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    if (num <= 3) {
        return 1;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return 0;
    }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n;
    printf("請輸入n：\n");
    scanf("%d", &n);

    printf("請依序輸入 %d 個正整數：\n", n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (isPrime(num)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
