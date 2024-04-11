class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
        int size = dist.size();
        vector<int>time(size);
        for(int i=0;i<=size-1;i++)
            time[i]=(ceil(dist[i]/(float)speed[i]));
        sort(time.begin(),time.end());
        int count = 0;
        int currTime = 0;
        
        for(int i=0;i<=size-1;i++)
        {
            if(currTime>=time[i])
                return count;
            
            count++;
            currTime++;
        }
        return count;
    }
};

// Time complexity: O(nlogn)
// Space complexity: O(n)
// The above code snippet calculates the number of  monsters that can be eliminated before they reach the city.
// The time taken by each monster to reach the city is calculated and stored in a vector.
// The vector is sorted and the number of monsters that can be eliminated is calculated by comparing the time taken by each monster to reach the city with the current time.
// If the current time is lesser than the time taken by the monster to reach the city, then the monster can be eliminated.
// If the current time is greater than the time taken by the monster to reach the city, then the monster cannot be eliminated.
// The current time is incremented by 1 and the count is incremented by 1.