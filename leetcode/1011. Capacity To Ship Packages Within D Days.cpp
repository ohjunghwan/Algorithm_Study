#include <iostream>
#include <vector>

using namespace std;

bool isAbleCapacity(vector<int> &weights, int capacity, int dDay) {
    int curDay = 1;
    int remain = capacity;

    for (int weight : weights) {
        if (weight > capacity) return false;
        if (weight <= remain) {
            remain -= weight;
        } else {
            curDay += 1;
            remain = capacity - weight;
        }
        if (curDay > dDay) return false;
    }

    return true;
}

int shipWithinDays(vector<int> weights, int D) {
    int left = 0;
    int right = 500 * 50001;

    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (isAbleCapacity(weights, mid, D))
            right = mid;
        else
            left = mid;
    }
    return right;
}

int main() {
    cout << shipWithinDays({1, 2, 3, 1, 1}, 4);
    return 0;
}
