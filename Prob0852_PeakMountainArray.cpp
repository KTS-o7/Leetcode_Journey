class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r= arr.size()-1,mid;
        while(l<=r)
        {
            mid = l+ (r-l)/2;
         
            if(mid>0 && arr[mid-1] < arr[mid] && arr[mid]>arr[mid+1])
                return mid;
            else if(mid>0 && arr[mid]<arr[mid-1])
                r = mid-1;
            else 
                l = mid+1;
            
        }
        return -1;
    }
};