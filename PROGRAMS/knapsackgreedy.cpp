#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for an item
struct Item {
    int value, weight;
};

// Comparator function to sort by value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to get maximum value
double fractionalKnapsack(int capacity, vector<Item> &items) {
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (auto &item : items) {
        if (capacity >= item.weight) {
            // Take full item
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            // Take fraction of item
            totalValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50;

    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value = " << maxValue << endl;

    return 0;
}