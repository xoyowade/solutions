/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals, int p) {
        int s = p+1;
        while (s < intervals.size()) {
            if (intervals[p].end >= intervals[s].start) {
                intervals[p].end = max(intervals[p].end, intervals[s].end); 
            } else {
                break;
            }
            s++;
        }
        vector<Interval> merged;
        for (int i = 0; i <= p; i++) {
            merged.push_back(intervals[i]);
        }
        for (int i = s; i < intervals.size(); i++) {
            merged.push_back(intervals[i]);
        }
        return merged;
    }
    vector<Interval> merge(vector<Interval> &intervals, Interval newInterval, int p) {
        if (p > 0 && newInterval.start <= intervals[p-1].end) {
            intervals[p-1].end = newInterval.end;
            return merge(intervals, p-1);
        }
        if (newInterval.end >= intervals[p].start) {
            intervals[p].start = newInterval.start;
            intervals[p].end = max(intervals[p].end, newInterval.end);
            return merge(intervals, p);
        } else {
            intervals.insert(intervals.begin()+p, newInterval);
        }
        return intervals;
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval.start < intervals[i].start) {
                return merge(intervals, newInterval, i);
            }
        }
        intervals.push_back(newInterval);
        return merge(intervals, intervals.size()-2);
    }
};
