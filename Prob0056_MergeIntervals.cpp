class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if(size<=1)
            return intervals;
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);

        for(int i = 1; i<size;i++)
        {
            if(intervals[i][0] <= ans.back()[1])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            
            else
                ans.push_back(intervals[i]);
        }
        return ans;
        
    }
};

// Time complexity: O(nlogn)
// Space complexity: O(n)
// Logic explained:
// 1. Sort the intervals based on the start time.
// 2. Create a vector of vectors to store the answer.
// 3. Push the first interval into the answer.
// 4. Iterate through the intervals.
// 5. If the start of the current interval is less than or equal to the end of the last interval in the answer, update the end of the last interval in the answer.
// This is because the current interval is overlapping with the last interval in the answer.
// 6. Else, push the current interval into the answer.
// 7. Return the answer.