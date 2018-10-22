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
    vector<Interval> merge(vector<Interval>& intervals) {
        // check the intervals[i].end against all other intervals[j].start
        // if start is less than end, take that interval's end and make it the new end of intervals[i]
        // put the new interval into a new vector
        vector<bool> checked(intervals.size());
        vector<Interval> results;
        
        return results;
        
    }
};