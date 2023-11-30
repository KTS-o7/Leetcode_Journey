class Solution {

public:

    int maxCoins(vector<int>& piles) {
          auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
        
        int size = piles.size();
        int cnt = 0;
        sort(piles.begin(),piles.end());
        for(int i = size/3;i<size;i=i+2)
        {
            cnt+=piles[i];
        }
        
        return cnt;
    }
};

// time complexity: O(nlogn)
// space complexity: O(1)
// This code counts the maximum number of coins you can get by picking 2nd largest element from the array.