class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = height.size() - 1;
        int max = 0;
        while (left < right) {
            int min_h = min(height[left], height[right]);
            int area = min_h * (right - left);
            if (area > max) {
                max = area;
            }
            if (height[left] > height[right]) {
                do {
                    right--;
                } while (height[right] < min_h && left < right);
            } else {
                do {
                    left++;
                } while (height[left] < min_h && left < right);
            }
        }
        return max;
    }
};
