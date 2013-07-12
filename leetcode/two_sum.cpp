class Solution {
public:
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
	        //printf("check base %d(%d) to find %d\n", base, numbers[base], left);
	        for (int check = base - 1; check >= 0; check--) { 
	            int next = numbers[check];
	            if (left == next) {
	                //printf("%d->%d(%d) %d->%d(%d)\n",
	                //    check, index[check] + 1, next,
	                //    base, index[base] + 1, numbers[base]);
	                int index1 = index[check] + 1;
	                int index2 = index[base] + 1;
	                if (index1 < index2) {
	                    result.push_back(index1);
	                    result.push_back(index2);
	                } else {
	                    result.push_back(index2);
	                    result.push_back(index1);
	                }
	                return result;
	            } else if (left > next) {
	                break;
	            }
	        }
	    }
	    return result;
	}
};
