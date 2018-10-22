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
    static bool start(const Interval& a, const Interval& b){
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        // check the intervals[i].end against all other intervals[j].start
        // if start is less than end, take that interval's end and make it the new end of intervals[i]
        // put the new interval into a new vector

        vector<bool> checked(intervals.size());
        vector<Interval> results;
        sort(intervals.begin(), intervals.end(), start);

        for(int i = 0; i != intervals.size(); ++i){
            int end = intervals[i].end;

            if (!checked[i]){
                for(int j = i + 1; j != intervals.size(); ++j){
                    if (checked[j]){
                        continue;
                    }
                    if (end >= intervals[j].start){
                        end = max(intervals[j].end, end);
                        intervals[i].end = end;
                        checked[j] = true;
                    }
                }
                results.push_back(intervals[i]);
                checked[i] = true;
            }
        }

        return results;      
    }
};