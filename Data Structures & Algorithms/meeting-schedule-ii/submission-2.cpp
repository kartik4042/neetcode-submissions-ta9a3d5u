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
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [](auto &x, auto &y){return x.start < y.start;});
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto &interval : intervals)
        {
            if(!minHeap.empty() && minHeap.top() <= interval.start)
                minHeap.pop();
            minHeap.push(interval.end);
        }    
        return minHeap.size();
    }
};
