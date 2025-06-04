#include <iostream>
#include <vector>
#include <algorithm>

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};
 
class Solution 
{
public:
    bool canAttendMeetings(std::vector<Interval>& intervals) 
    {
        std::sort(intervals.begin(), intervals.end(),
            [](const Interval& interval1, const Interval& interval2)
            {
                return interval1.start < interval2.start;
            });

        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[i - 1].end)
            {
                return false;
            }
        }

        return true;
    }
};


int main()
{
    std::vector<Interval> intervals = { {0, 30}, {5, 10}, {15, 20} };

    Solution sol;
    sol.canAttendMeetings(intervals);
    std::cout << "Hello World!\n";
}
