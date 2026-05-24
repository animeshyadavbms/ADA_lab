#include <stdio.h>

// Structure to store item details
struct Item {
    int weight;
    int value;
    float ratio;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Sort items by value/weight ratio in descending order
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Fractional Knapsack function
float fractionalKnapsack(int capacity, struct Item items[], int n) {
    sortItems(items, n);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {

        // If whole item can be taken
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        // Take fraction of item
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

    // Input values and weights
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);

        // Calculate ratio
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    float maxValue = fractionalKnapsack(capacity, items, n);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
