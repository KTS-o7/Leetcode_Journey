class Solution {
public:
    int mySqrt(int x) {
        int low= 0,high=x,mid;
        if(x==0) return 0;
        if(x==1) return 1;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(x/mid == mid)
                return mid;
            else if(x/mid > mid)
            {
                if(x/(mid+1) <(mid+1)) return mid;
                else low = mid+1;
            }
            else
                high = mid-1;
        }
        return mid;
        
    }
};