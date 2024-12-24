#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int maxWater = 0, left = 0, right = height.size() - 1;
    while (left < right) {
        int width = right - left;
        maxWater = max(maxWater, min(height[left], height[right]) * width);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxWater;
}
