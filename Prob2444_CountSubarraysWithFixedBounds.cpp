class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        long long ans = 0;
        int minI =-1,maxI=-1,start=-1;
        for(int i =0;i<nums.size();i++)
        {
            
            if(nums[i]==minK)
            {
                minI=i;
            }
             if(nums[i]==maxK)
            {
                maxI=i;
            }
            if(nums[i]<minK || nums[i]>maxK)
                {
                    maxI=-1;
                    minI=-1;
                    start = i;
                }
            ans+= max(0,min(minI,maxI)-start);
        }
        return ans;
        
    }
};


// time complexity : O(n)
// space complexity : O(1)
// Logic explained :
/*
This C++ code defines a class `Solution` with a public method `countSubarrays`. The method takes three parameters: a vector of integers `nums`, and two integers `minK` and `maxK`. The purpose of this method is to count the number of subarrays in `nums` where the minimum value is `minK` and the maximum value is `maxK`.

Here's a step-by-step explanation of the method:

1. Initialize `ans` to 0. This variable will hold the final count of subarrays.
2. Initialize `minI`, `maxI`, and `start` to -1. These variables will hold the indices of `minK`, `maxK`, and the start of the subarray, respectively.
3. Loop through the `nums` vector. For each element:
   - If the element is equal to `minK`, update `minI` to the current index.
   - If the element is equal to `maxK`, update `maxI` to the current index.
   - If the element is less than `minK` or greater than `maxK`, reset `minI` and `maxI` to -1 and update `start` to the current index. This is because such an element cannot be part of a valid subarray.
   - Add the difference between the smaller of `minI` and `maxI` and `start` to `ans`. The `max(0, min(minI, maxI) - start)` expression ensures that we only count valid subarrays where both `minK` and `maxK` are present.
4. After the loop, return `ans` as the total count of valid subarrays.

Please note that this code assumes that `minK` and `maxK` are distinct and both are present in `nums`. If that's not the case, the code might not work as expected. Also, the code does not handle the case where `nums` is empty. You might want to add checks for these edge cases if necessary.
*/

/*
The line `ans += max(0, min(minI, maxI) - start);` is used to count the number of valid subarrays that end at the current index `i`.

Here's how it works:

- `min(minI, maxI)`: This gives the index of the last occurrence of either `minK` or `maxK` that we've seen so far in the array. We take the minimum of these indices because we want both `minK` and `maxK` to be present in our subarray.

- `min(minI, maxI) - start`: This calculates the number of elements in the current subarray. `start` is the index of the first element of the current subarray, so subtracting `start` from the last index of `minK` or `maxK` gives the number of elements in the subarray.

- `max(0, min(minI, maxI) - start)`: We take the maximum of 0 and the number of elements in the subarray because we don't want to count subarrays where either `minK` or `maxK` is not present (in which case `min(minI, maxI)` would be `-1` and `min(minI, maxI) - start` would be negative).

- `ans += max(0, min(minI, maxI) - start)`: Finally, we add the number of valid subarrays that end at the current index to our total count `ans`.

So, in each iteration of the loop, this line counts the number of valid subarrays that end at the current index and adds it to the total count. This way, by the end of the loop, `ans` will hold the total number of valid subarrays in `nums`. This is why `ans += max(0, min(minI, maxI) - start);` gives the correct answer.
*/