class Solution {
public:
    int maxScore(string s) {
        auto fastio=[](){
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        };
        int size = s.size(),result;
        int totOne=0,currOne=0,currZero=0;
        for(int i=0;i<size;i++)
        {
            if(s[i]=='1')
                totOne++;
        }
        int maxVal = INT_MIN;
        for(int i=0;i<size-1;i++)
        {
            if(s[i]=='1')
                currOne++;
            else
                currZero++;
                
            result = currZero+totOne-currOne;
            maxVal= max(maxVal,result);
        }
        return maxVal;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)
// loop runs till size-1 so that it doesnt count empty string as valid string