class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int oneCount = 0;
        for(int i = 0;i<s.size();i++)
            if(s[i]=='1')
                oneCount++;
        int zeroCount = s.size()-oneCount;
        string ans = "";
        while(oneCount-1)
            {
                ans+='1';
                oneCount--;
            }
        while(zeroCount)
        {
            ans+='0';
            zeroCount--;
        }
        ans+='1';
        return ans;
        

        
    }
};

// time complexity: O(n)
// space complexity: O(n)
// code explained : 
// 1. Count the number of 1's and 0's in the given string.
// 2. Append 1's to the ans string equal to the number of 1's in the given string - 1.
// 3. Append 0's to the ans string equal to the number of 0's in the given string.
// 4. Append 1 to the ans string.
// 5. Return the ans string.
// 6. This will give the largest odd number possible from the given binary string.