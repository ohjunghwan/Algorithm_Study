#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


int largestRectangleArea(vector<int> heights) {
    stack<pair<int, int>> hStack;
    int max_rec = 0;
    heights.push_back(INT32_MIN);

    for (int i = 0; i < heights.size(); ++i) {
        while (!hStack.empty() && hStack.top().second > heights[i]) {
            auto cur = hStack.top();
            hStack.pop();
            int front = (hStack.empty()) ? cur.first : (cur.first - hStack.top().first - 1);
            int back = i - cur.first;
            max_rec = max((front + back) * cur.second, max_rec);
        }
        hStack.push({i, heights[i]});
    }

    return max_rec;
}


int main() {
    cout << largestRectangleArea({1});
}
