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

        for(int i = 0; i < intervals.size(); i++)
        {
            if(!minHeap.empty() && minHeap.top() <= intervals[i].start)
                minHeap.pop();
            minHeap.push(intervals[i].end);
        }
        return minHeap.size();
    }
};
