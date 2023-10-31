#include <stdio.h>

int main() {
    int n;
    printf("請輸入情侶數目：\n");
    scanf("%d", &n);

    int feelings[n][n];
    int boys[n], girls[n];

    printf("請輸入好感度矩陣：\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &feelings[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        boys[i] = -1;
        girls[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int maxFeeling = -1;
        int boy, girl;

        for (int j = 0; j < n; j++) {
            if (boys[j] == -1) {
                for (int k = 0; k < n; k++) {
                    if (girls[k] == -1) {
                        if (feelings[j][k] > maxFeeling) {
                            maxFeeling = feelings[j][k];
                            boy = j;
                            girl = k;
                        }
                    }
                }
            }
        }

        boys[boy] = girl;
        girls[girl] = boy;

        printf("boy %d pair with girl %d.\n", boy + 1, girl + 1);
    }

    return 0;
}
