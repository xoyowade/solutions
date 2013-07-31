/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comparator(const Interval &i1, const Interval &i2) {
    return i1.start < i2.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> merged;
        if (intervals.size() == 0) {
            return merged;
        }
        sort(intervals.begin(), intervals.end(), comparator);
        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            Interval &interval_m = merged.back();
            Interval &interval_g = intervals[i];
            if (interval_m.end >= interval_g.start) {
                interval_m.end = max(interval_m.end, interval_g.end);
            } else {
                merged.push_back(interval_g);
            }
        }
        return merged;
    }
};
