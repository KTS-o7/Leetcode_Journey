class Solution {
public:
    int findSpecialInteger(vector<int>& arr) { auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
         if(arr.size()==1)
        return arr[0];
        unordered_map<int,int>umap;
        int size = arr.size();
        int magic = size*0.25;
        for (int i = 0;i<size;i++)
        {
            umap[arr[i]]++;
            if(umap[arr[i]]>magic)
                return arr[i];
        }
        return 0;
    }
};
 // Time Complexity: O(n)
 // Space Complexity: O(n)
 
