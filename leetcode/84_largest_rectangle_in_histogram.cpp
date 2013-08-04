struct Area{
    int area;
    int height;
    int width;
    Area (int h, int w) {
        Set(h, w);
    }
    void Set (int h, int w) {
        height = h;
        width = w;
        area = h*w;
    }
};
bool operator<(const Area &a, const Area &b) {
    return a.area < b.area;
}
class Solution {
public:
    
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int max_area = 0;
        int i = 0;
        while (i < height.size()) {
            if (s.empty() || height[s.top()] <= height[i]) {
                s.push(i++);
            } else {
                int t = s.top();
                s.pop();
                max_area = max(max_area, height[t] * (s.empty() ? i : (i-s.top()-1)));
            }
        }
        while (!s.empty()) {
            int t = s.top();
            s.pop();
            max_area = max(max_area, height[t] * (s.empty() ? i : (i-s.top()-1)));
        }
        
        return max_area;
    }
    int maxarea(vector<int> &height, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == r) {
            return height[l];
        }
        int min = l;
        for (int i = l+1; i <= r; i++) {
            if (height[i] < height[min]) {
                min = i;
            }
        }
        return max(max(maxarea(height, l, min-1), maxarea(height, min+1, r)), height[min]*(r-l+1));
    }
    int largestRectangleArea_divide_and_conquer(vector<int> &height) {
        return maxarea(height, 0, height.size()-1);
    }
    int largestRectangleArea_bruteforce(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.empty()) {
            return 0;
        }
        Area max_area(height[0], 1);
        vector<vector<Area> > areas;
        vector<Area> first;
        first.push_back(max_area);
        areas.push_back(first);
        for (int i = 1; i < height.size(); i++) {
            vector<Area> last_areas = areas.back();
            for (int j = 0; j < last_areas.size(); j++) {
                Area &a = last_areas[j];
                a.Set(min(a.height, height[i]), a.width+1);
                max_area = max(max_area, a);
            }
            Area a(height[i], 1);
            last_areas.push_back(a);
            max_area = max(max_area, a);
            areas.push_back(last_areas);
        }
        
        return max_area.area;
    }
};
