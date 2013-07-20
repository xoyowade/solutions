class Solution {
public:
    void swap(vector<int> &num, int i1, int i2) {
        int tmp = num[i1];
        num[i1] = num[i2];
        num[i2] = tmp;
    }
    void reverse(vector<int> &num, int start) {
        // reverse is enough
        for (int i = 0; i < (num.size()-start)/2; i++) {
            swap(num, start+i, num.size()-1-i);
        }
    }
    
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = num.size()-1; i >= 1; i--) {
            if (num[i - 1] < num[i]) {
                for (int j = num.size()-1; j >= i; j--) {
                    if (num[j] > num[i-1]) {
                        swap(num, j, i-1);
                        reverse(num, i);
                        return;
                    }
                }
            }
        }
        reverse(num, 0);
    }
};
