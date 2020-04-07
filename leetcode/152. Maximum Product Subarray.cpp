#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> plusList;
vector<bool> isPlus;
vector<int> minusList;
vector<bool> isMinus;


int maxProduct(vector<int> nums) {
    plusList.resize(nums.size());
    isPlus.resize(nums.size(), false);
    minusList.resize(nums.size());
    isMinus.resize(nums.size(), false);

    bool hasZero = false;
    int result = -2100000000;

    if (nums[0] > 0) {
        isPlus[0] = true;
        plusList[0] = nums[0];
    } else if (nums[0] < 0) {
        isMinus[0] = true;
        minusList[0] = nums[0];
    } else {
        hasZero = true;
    }

    result = max(result, nums[0]);


    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > 0) {
            isPlus[i] = true;
            plusList[i] = nums[i];

            if (isPlus[i - 1]) {
                plusList[i] = plusList[i - 1] * nums[i];
            }

            result = max(result, plusList[i]);

            if (isMinus[i - 1]) {
                isMinus[i] = true;
                minusList[i] = minusList[i - 1] * nums[i];
                result = max(result, minusList[i]);
            }

        } else if (nums[i] < 0) {
            isMinus[i] = true;
            minusList[i] = nums[i];

            if (isPlus[i - 1]) {
                minusList[i] = nums[i] * plusList[i - 1];
            }

            result = max(result, minusList[i]);


            if (isMinus[i - 1]) {
                isPlus[i] = true;
                plusList[i] = nums[i] * minusList[i - 1];
            }

            result = max(result, plusList[i]);


        } else {
            hasZero = true;
        }
    }


    return hasZero ? max(0, result) : result;

}

int main() {
    cout << maxProduct({-2});
}
