class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> umap;
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){

            sum+=nums[i];
            if(sum==k)
                count++;
            if(umap.find(sum-k) !=umap.end()){
                count+= umap[sum-k];
            }
            umap[sum]++;
        }
        return count;

    }
};


// Time complexity: O(n)
// Space complexity: O(n)
// Logic explained :
// 1. We use a hashmap to store the sum of the subarray and the number of times it has occured.
// 2. We iterate through the array and keep adding the sum of the subarray to the hashmap.
// 3. If the sum of the subarray is equal to k, we increment the count.
// 4. If the sum of the subarray minus k is present in the hashmap, we increment the count by the number of times it has occured.
// This is because if the sum of the subarray minus k is present in the hashmap, it means that the subarray from that index to the current index has a sum of k.
// 5. We increment the count and the number of times the sum has occured in the hashmap.
// 6. We return the count.

// Example:
// nums = [1,1,1], k = 2
// umap = {0:1}
// sum = 0
// count = 0
// i=0
// sum = 1
// umap = {0:1, 1:1}
// i=1
// sum = 2
// umap = {0:1, 1:1, 2:1}
// count = 1
// i=2
// sum = 3
// umap = {0:1, 1:1, 2:1, 3:1}
// count = 2
// return 2
