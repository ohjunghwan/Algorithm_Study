int getWater(int left, int right, vector<int> &height) {
    return (right - left) * min(height[left], height[right]);
}

int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int max_water = getWater(left, right, height);
    while (left < right) {
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
        max_water = max(max_water, getWater(left, right, height));
    }

    return max_water;

}