#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int availableTime[30];
int remainTask[30];
const int IDLE = -1;
const int NO_TASK = -2;

int pickTask(int curTime) {
    bool isRemain = false;
    int nextIndex = IDLE;
    int curMax = 0;
    for (int i = 0; i < 27; ++i) {
        if (remainTask[i]) isRemain = true;
        if (curMax < remainTask[i] && availableTime[i] <= curTime) {
            nextIndex = i;
            curMax = remainTask[i];
        }
    }

    return isRemain ? nextIndex : NO_TASK;
}


int leastInterval(vector<char> tasks, int n) {
    for (char task : tasks)
        remainTask[task - 'A']++;

    int curTime = 0;
    while (true) {
        int curJob = pickTask(curTime);
        if (curJob == NO_TASK)
            return curTime;
        else if (curJob == IDLE) {}
        else {
            remainTask[curJob]--;
            availableTime[curJob] = curTime + n + 1;
        }

        curTime++;
    }

}

int main() {
    cout << leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 1);
}