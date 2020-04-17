#include <iostream>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

deque<int> queue1;
deque<int> queue2;


double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
    for (int num : nums1) {
        queue1.push_back(num);
    }
    for (int num : nums2) {
        queue2.push_back(num);
    }
    while (queue1.size() + queue2.size() > 2) {
        //pop left
        if (queue1.empty())
            queue2.pop_front();
        else if (queue2.empty())
            queue1.pop_front();
        else {
            if (queue1.front() < queue2.front())
                queue1.pop_front();
            else
                queue2.pop_front();
        }

        //pop right
        if (queue1.empty())
            queue2.pop_back();
        else if (queue2.empty())
            queue1.pop_back();
        else {
            if (queue1.back() < queue2.back())
                queue2.pop_back();
            else
                queue1.pop_back();
        }

    }

    int result = 0;
    int size = 0;
    while (!queue1.empty()) {
        result += queue1.front();
        size++;
        queue1.pop_front();
    }
    while (!queue2.empty()) {
        result += queue2.front();
        size++;
        queue2.pop_front();
    }

    return (float) result / size;
}

int main() {
    cout << findMedianSortedArrays({0}, {1, 2, 3, 4});
}