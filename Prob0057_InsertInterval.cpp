class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>>answer;
        int start = newInterval[0], end = newInterval[1];
        int ptr = 0, size = intervals.size();
        
        for(;ptr<size && intervals[ptr][1]<start;ptr++)
        {
            answer.push_back(intervals[ptr]);
        }

        for(;ptr<size && intervals[ptr][0]<=end;ptr++)
        {
            start = min(start,intervals[ptr][0]);
            end = max(end,intervals[ptr][1]);

        }
        
        answer.push_back({start,end});

        answer.reserve(answer.size()+size-ptr);
        answer.insert(answer.end(),intervals.begin()+ptr,intervals.end());
        
        return answer;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
// Code logic explained:
// 1. Create a vector of vectors to store the answer.
// 2. Create a start and end variable to store the new interval.
// 3. Create a pointer to iterate through the intervals.
// 4. If the end of the current interval is less than the start of the new interval, push the current interval into the answer.
// 5. If the start of the current interval is less than or equal to the end of the new interval, update the start and end of the new interval.
// This is because the current interval is overlapping with the new interval.
// 6. Push the new interval into the answer.
// 7. Reserve the space for the answer and insert the remaining intervals into the answer.
// 8. Return the answer.
// 9. Done.