#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int> &numbers, int val) {
        int from = 0, to = numbers.size() - 1;
        while (from < to) {
            int mid = from + (to - from)/2;
            int cur = numbers[mid];
            // printf("check %d @ mid index %d[%d, %d] for %d\n", cur, mid, from ,to, val);
            if (cur == val) {
                return mid;
            } else if (cur < val) {
                from = mid + 1;
            } else {
                to = mid - 1;
            }
        }
        if (numbers[from] == val) {
            return from;
        }
        return -1;
    }
    
    void sort(vector<int> &numbers, vector<int> &index) {
        const int size = numbers.size();
        for (int i = 0; i < size; i++) {
            int small = i;
            for (int j = i+1; j < size; j++) {
                if (numbers[j] < numbers[small]) {
                    small = j;
                }
            }
            swap(numbers[small], numbers[i]);
            swap(index[small], index[i]);
            //printf("map %d->%d\n", i, small);
        }
    }
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        const int size = numbers.size();
        if (size < 2) return result;
        vector<int> index(size);
        for (int i = 0; i < size; i++) {
            index[i] = i;
        }
        sort(numbers, index);
        for (int base = size - 1; base > 0; base--) {
            int left = target - numbers[base];
            int pos = search(numbers, left);
            // printf("check base %d(%d) and find %d @ num %d\n", base, numbers[base], left, pos);
            if (pos >= 0) {
                int index1 = index[pos] + 1;
                int index2 = index[base] + 1;
                if (index1 < index2) {
                    result.push_back(index1);
                    result.push_back(index2);
                } else {
                    result.push_back(index2);
                    result.push_back(index1);
                }
                return result;
            }
        }
        return result;
    }
};

int main() {
    int target = 100;
	static const int SIZE = 3;
	int nums[SIZE] = {5,75,25};
    vector<int> numbers(&nums[0], &nums[0]+SIZE);
	Solution s;
    vector<int> result = s.twoSum(numbers, target);
    if (result.size() < 2) return -1;
    cout << result[0] << " " << result[1] << endl;
    
    return 0;
}
