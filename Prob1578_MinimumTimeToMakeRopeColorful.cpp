class Solution {

public:

    int minCost(string colors, vector<int>& neededTime) {
        auto fastio=[](){
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        };
         int l=0, r, n=colors.size();
        int ans=0, locMax=0;
        for (r=0; r<n; ) {
            while (r<n && colors[r]==colors[l]) {
                ans+=neededTime[r];
                locMax=max(locMax, neededTime[r]);
                r++;
            }
            ans-= locMax;
            locMax=0;
            l=r; 
        }
        return  ans;
        
    }
};

// time complexity: O(N)
// space complexity: O(1)
/*
Lambda Function fastio:

This lambda function is used to optimize input and output operations for faster execution by syncing with standard input/output streams.
Variables Initialization:

int l = 0, r, n = colors.size();: Initialize variables l and r for left and right indices, and n for the size of the input string colors.
int ans = 0, locMax = 0;: Initialize variables ans to store the total cost and locMax to store the maximum time for the current color.
Main Loop:

Loop through the characters of the string using the variable r.
While consecutive characters have the same color, add the time needed for painting and update locMax if the current time is greater.
When a different color is encountered, subtract the maximum time for the current color (locMax) from the total cost.
Reset locMax to 0.
Move to the next different color by updating l to r.
Result:

The function returns the final ans, which represents the minimum cost of painting the string according to the specified conditions.
*/