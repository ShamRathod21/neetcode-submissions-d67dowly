/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(), [](auto &a, auto &b) {
            return a.start < b.start;
        });
        Interval start = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if(start.end > intervals[i].start) {
                return false;
            }
            start = intervals[i];
        }
        return true;
    }
};
