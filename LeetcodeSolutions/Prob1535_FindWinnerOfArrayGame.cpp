class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
         auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
        
        int size = arr.size();
        if(k==1)
            return arr[1];
        if (k>=size)
           { sort(arr.begin(),arr.end());
            return arr[size-1];
           }
        else 
            {
                int win = arr[0];
                int wincount = 0;
                for(int i=1;i<=size-1;i++)
                    {
                        if(arr[i]<=win)
                            wincount +=1;
                        if(arr[i]>win)
                        {
                            win = arr[i];
                            wincount =1;
                        }
                        if(wincount == k)
                            return win;
                    }
                sort(arr.begin(),arr.end());
            return arr[size-1];
                
            }
        
    }
};

// time complexity: O(nlogn)
// space complexity: O(1)
// fast io code snippet is used to optimise input and output speed
