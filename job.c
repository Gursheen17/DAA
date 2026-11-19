#include <stdio.h>

struct Job {
    int id, deadline, profit;
};

int main() {
    int n, maxDeadline = 0, totalProfit = 0;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job job[n];

    printf("Enter job id, deadline and profit:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &job[i].id, &job[i].deadline, &job[i].profit);

        if (job[i].deadline > maxDeadline)
            maxDeadline = job[i].deadline;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (job[i].profit < job[j].profit) {
                struct Job temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }

    int slot[maxDeadline + 1];

    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = job[i].deadline; j >= 1; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += job[i].profit;
                break;
            }
        }
    }

    printf("Scheduled Jobs:\n");

    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1)
            printf("Job %d\n", job[slot[i]].id);
    }

    printf("Maximum Profit = %d\n", totalProfit);

    return 0;
}