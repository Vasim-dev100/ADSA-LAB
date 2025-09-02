
#include <stdio.h>

int findDefective(int coins[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (coins[i] < coins[minIndex]) {
            minIndex = i;
        }
    }

    int allEqual = 1;
    for (int i = 1; i < n; i++) {
        if (coins[i] != coins[0]) {
            allEqual = 0;
            break;
        }
    }
    if (allEqual) return -1;
    return minIndex;
}

int main() {
    int n;
    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter weights of coins:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    int index = findDefective(coins, n);

    if (index == -1)
        printf("All coins have equal weight. No defective coin.\n");
    else
        printf("Defective (lighter) coin found at position %d (0-based), weight = %d\n",
               index, coins[index]);

    return 0;
}
