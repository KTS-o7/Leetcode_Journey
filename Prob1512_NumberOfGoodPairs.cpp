// O(N) solution

static const int fast_io = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> map;
        for(auto i: nums){
            map[i]++;
        }
        int no = 0;
        for(auto i: map){
            if(i.second >= 2){
                no += i.second * (i.second - 1) /2;
            }
        }
        return no;
    }
};
 

// O(N^2) solution
tatic const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int totsize=nums.size();
        int count =0;
        for(int i=0;i<totsize-1;i++)
            for(int j=i+1;j<totsize;j++)
                if( i<j && nums[i]==nums[j])
                    count++;
        return count;
        
    }
};
