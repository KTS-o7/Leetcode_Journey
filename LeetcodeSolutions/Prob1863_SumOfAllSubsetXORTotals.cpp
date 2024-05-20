class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        return calculate(nums, 0, 0); 
    }

    int calculate(vector<int>& nums, int level, int currentXOR) {

        if (level == nums.size()) 
            return currentXOR;
 
        int include = calculate(nums, level + 1, currentXOR ^ nums[level]);
 
        int exclude = calculate(nums, level + 1, currentXOR);
        
        return include + exclude;
    }
};

// Time complexity: O(2^n)
// Space complexity: O(n)

// Logic Explained :
// 1. We are given an array of integers.
// 2. We need to find the sum of XOR of all possible subsets.
// 3. We can solve this problem using recursion and backtracking.
// 4. We will start from the first element of the array and we have two choices, either we can include the element in the subset or we can exclude the element from the subset.
// 5. If we include the element in the subset, we will calculate the XOR of the current element with the XOR of the previous elements.
// 6. If we exclude the element from the subset, we will calculate the XOR of the previous elements.
// 7. We will continue this process for all the elements of the array.
// 8. We will return the sum of XOR of all possible subsets.
// 9. The time complexity of this approach is O(2^n) where n is the number of elements in the array.