class Solution {
public:

    int prevTemp[110];

    int getCurResult(int index, int temp) {
        int findTemp = temp + 1;
        int minIndex = 2100000000;
        while (findTemp <= 101) {
            if (prevTemp[findTemp]) {
                minIndex = min(minIndex, prevTemp[findTemp]);
            }
            findTemp++;
        }
        return minIndex == 2100000000 ? 0 : minIndex - index;
    }

    vector<int> dailyTemperatures(vector<int> T) {
        vector<int> result(T.size());
        for (int i = T.size() - 1; i >= 0; --i) {
            prevTemp[T[i]] = i;
            result[i] = getCurResult(i, T[i]);
        }
        return result;
    }

};