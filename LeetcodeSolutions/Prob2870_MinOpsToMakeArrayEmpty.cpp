class Solution {
public:
    int minOperations(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        unordered_map<int,int>m;
        int ans=0,quo;
        for(auto i:nums)
            m[i]++;
        for( auto it:m)
            {
            if(it.second== 1)
                return -1;
            quo = (it.second+2)/3;
            ans += quo;
        }
        return ans;
    }
};

// Time compplexity: O(n)
// Space complexity: O(n)

/*Code Explained
Input/Output Optimization:

std::ios::sync_with_stdio(false);: Disables synchronization between C++ standard input and output streams and C standard input and output streams for faster input/output.
cin.tie(nullptr);: Unties cin from cout for faster input.
Frequency Counting:

unordered_map<int, int> m;: Initializes an unordered map to store the frequency of each element in the input vector.

Loop through the input vector nums and count the frequency of each element using the unordered map.

Calculating Operations:

for (auto it : m) { ... }: Iterate through the frequency map.

If any element appears only once (it.second == 1), return -1 because it's not possible to make all elements equal.

Calculate the minimum number of operations needed for each element:

quo = (it.second + 2) / 3;
Accumulate the total number of operations:

ans += quo;
Returning the Result:

return ans;: Return the total number of operations needed to make all elements equal.
Logic:
The goal is to make all elements in the input vector nums equal.
The algorithm counts the frequency of each element using an unordered map.
For each element, it calculates the minimum number of operations needed to make it equal to the others.
The total number of operations needed is the sum of these minimum operations for each element.
If any element appears only once, it's not possible to make all elements equal, so the function returns -1.
Otherwise, it returns the total number of operations needed.
This approach ensures that the elements are grouped in threes (if possible) to minimize the number of operations needed to make them equal.

*/