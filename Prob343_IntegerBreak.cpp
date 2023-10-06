static const int fast_io = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    int integerBreak(int n) {
        if(n<=3)
            return n-1;
        int ans = 1;
        while(n>4)
        {
            ans = ans*3;
            n=n-3;
        }
        return ans*n;
        
    }
};