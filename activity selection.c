
#include <stdio.h>

int main() {
    int n;
    int start[100], finish[100];
    int temp;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter start and finish time of activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Sort activities by finish time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {
                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }

    printf("\nSelected activities:\n");

    // Select first activity
    int last = 0;
    printf("Activity 1: (%d, %d)\n",
           start[last], finish[last]);

    // Select remaining activities
    for (int i = 1; i < n; i++) {
        if (start[i] >= finish[last]) {
            printf("Activity %d: (%d, %d)\n",
                   i + 1, start[i], finish[i]);

            last = i;
        }
    }

    return 0;
}
