class Solution {
public:
    int maxDepth(string s) {
        int counter=0,maxCount =0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                counter++;
            else if(s[i]==')')
                counter--;
            maxCount = max(counter,maxCount);
        }
        return maxCount;
        
    }
};

// Time complexity: O(n)
// Space complexity: O(1)

// Logic Explained : 
// 1. We will iterate through the string and whenever we encounter '(' we will increment the counter and whenever we encounter ')' we will decrement the counter.
// 2. We will keep track of the maximum value of the counter and return it as the answer.
// 3. At any given time counter will tell the depth of parentheses so far.
// 4. We will return the maximum depth of parentheses.