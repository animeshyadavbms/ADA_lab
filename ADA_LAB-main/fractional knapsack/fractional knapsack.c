#include <stdio.h>

struct Item {
    int weight;
    int value;
    float ratio;
};

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

float fractionalKnapsack(int capacity, struct Item items[], int n) {
    sortItems(items, n);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else {
            totalValue += items[i].value * ((float)capacity / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);

        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    float maxValue = fractionalKnapsack(capacity, items, n);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
