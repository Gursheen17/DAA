#include <stdio.h>

int w[100], x[100], n, m;

void sumOfSubsets(int s, int k, int r) {
    x[k] = 1;

    if (s + w[k] == m) {
        printf("Subset: ");
        for (int i = 0; i <= k; i++) {
            if (x[i] == 1)
                printf("%d ", w[i]);
        }
        printf("\n");
    }
    else if (k + 1 < n && s + w[k] + w[k + 1] <= m) {
        sumOfSubsets(s + w[k], k + 1, r - w[k]);
    }

    if (k + 1 < n && s + r - w[k] >= m) {
        x[k] = 0;
        sumOfSubsets(s, k + 1, r - w[k]);
    }
}

int main() {
    int sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }

    printf("Enter target sum: ");
    scanf("%d", &m);

    printf("Subsets are:\n");

    sumOfSubsets(0, 0, sum);

    return 0;
}