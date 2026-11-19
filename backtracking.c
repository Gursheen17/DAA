#include <stdio.h>

int x[100], n;

void backtrack(int k) {
    if (k == n) {
        for (int i = 0; i < n; i++)
            printf("%d ", x[i]);
        printf("\n");
        return;
    }

    for (int i = 0; i <= 1; i++) {
        x[k] = i;
        backtrack(k + 1);
    }
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    backtrack(0);

    return 0;
}