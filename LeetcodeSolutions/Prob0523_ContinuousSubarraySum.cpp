// Approach 1 : Brute force

class Solution {
    public:
    bool checkSubarraySum(vector<int>& nums,int k)
    {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            int sum = nums[i];
            for(int j = i+1; j<size; j++)
            {
                sum+=nums[j];
                if(k==0)
                {
                    if(sum==0)
                        return true;
                }
                else if(sum%k==0)
                    return true;
            }
        }
        return false;
    }
};

// Time complexity: O(n^2) where n is the length of the array
// Space complexity: O(1)
// Logic explained:
// 1. The outer loop will let us choose the starting index of the subarray.
// 2. The inner loop will let us choose the ending index of the subarray.
// 3. We will keep adding the elements of the subarray and check if the sum is divisible by k.
// 4. If the sum is divisible by k, we return true.
// 5. If we reach the end of the array and we haven't found a subarray whose sum is divisible by k, we return false.



// Approach 2 : Prefix sum + reminder hash map lookup
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       std::ios::sync_with_stdio(false);
       cin.tie(nullptr);
       cout.tie(nullptr);
       
       int size = nums.size(), sum = 0;
       unordered_map<int,int>indexOccured;
       
       indexOccured[0] = -1;

       for(int i= 0; i<size; i++)
       {
            sum+=nums[i];

            if(indexOccured.find(sum%k) == indexOccured.end())
            {
                indexOccured[sum%k] = i;
            }
            else
            {
                int found = indexOccured[sum%k];
                if(i-found>1)
                    return true;
            }
       }
       return false;
        
    }
};

// Time complexity: O(n) where n is the length of the array
// Space complexity: O(n) where n is the length of the array

// Logic explained:
// 1. Create a map to store the index of the sum%k. This will help us to find the subarray whose sum is divisible by k.
// 2. Run a loop to create prefix sum.
// 3. If the index at which the sum%k is found is not present in the map, we add the index to the map.
// 4. If the index at which the sum%k is found is present in the map, we check if the difference between the current index and the index at which the sum%k was found is greater than 1. If it is, we return true.
// 5. This is because the question says the length of subarray must be atleast 2.
// 6. If we reach the end of the array and we haven't found a subarray whose sum is divisible by k, we return false.
// We need to initialize the map with 0,-1 because if the sum%k is 0, we need to return true if the length of the subarray is atleast 2. If we don't initialize the map with 0,-1, we will miss this case.
// Example of edge case:
// [2,4,3], k=6
// at i = 0, sum = 2, sum%k = 2%6 = 2 , indexOccured[2] = 0
// at i = 1, sum = 6, sum%k = 6%6 = 0, indexOccured[0] = -1 (as we initialized the map with 0,-1) 
// found = -1, current index = 1 , 1-(-1) = 2 which is greater than 1, so we return true.
