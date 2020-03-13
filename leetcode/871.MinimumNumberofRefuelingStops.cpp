#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int stationPointer;
priority_queue<int> canRefuel;

int getFuel(int curPlace, vector<vector<int>> stations) {
    if (stations.empty()) return -1;

    for (; stationPointer < stations.size() && stations[stationPointer][0] <= curPlace; stationPointer++) {
        canRefuel.push(stations[stationPointer][1]);
    }

    if (canRefuel.empty())
        return -1;
    else {
        int result = canRefuel.top();
        canRefuel.pop();
        return result;
    }
}

int solution(int target, int startFuel, vector<vector<int>> stations) {
    int result = 0;
    int curPlace = startFuel;
    while (curPlace < target) {
        int fuel = getFuel(curPlace, stations);
        if (fuel == -1)return -1;
        curPlace += fuel;
        result++;
    }

    return result;
}

int main() {
    cout << solution(100, 50, {{50, 50}});
}