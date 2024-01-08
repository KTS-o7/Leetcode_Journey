// Merge function of merge sort;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto fastio =[]()
        {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        };
        vector<int>ans(m+n);
        int i=0,j=0,k=0;;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                ans[k++]=nums1[i++];
                
            }
            else
            {
               ans[k++]=nums2[j++];
            }
        }
        while(i<m)
        {
            ans[k++]=nums1[i++];
        }
        while(j<n)
        {
           ans[k++]=nums2[j++];
        }
        for(int i = 0;i<ans.size();i++)
            nums1[i]=ans[i];
    }
};