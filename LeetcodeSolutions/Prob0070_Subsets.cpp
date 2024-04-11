class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        result.push_back({});  // Include an empty subset
        
        for (int num : nums) {
            
            int n = result.size();
            // Iterate over existing subsets and create new subsets with the current element
            for (int i = 0; i < n; ++i) {
                std::vector<int> subset = result[i];
                subset.push_back(num);
                result.push_back(subset);
            }
        }

        return result;
    }
};

// Time Complexity: O(n*2^n)
// Space Complexity: O(n*2^n)

/*Code explained:

### Algorithm:

1. **Initialize**: Create an empty vector of vectors called `result` to store subsets. Add an initial empty subset to `result`.

   ```
   result = [[]]
   ```

2. **Iterate Through Elements**:
   - For each element `num` in the input vector `nums`, do the following:
   
     ```
     for num in nums:
     ```

3. **Generate Subsets**:
   - For each existing subset in `result`, do the following:
     - Create a copy of the subset.
     - Append the current element `num` to the copied subset.
     - Add the modified subset to the `result` vector.

     ```
     n = len(result)
     for i in range(n):
         subset = result[i]
         new_subset = subset.copy()
         new_subset.append(num)
         result.append(new_subset)
     ```

4. **Repeat for All Elements**: Continue the outer loop until all elements in `nums` are processed.

5. **Return Result**: The `result` vector contains all possible subsets of the input vector `nums`.

### Complexity Analysis:

- **Time Complexity**: O(2^n), where n is the number of elements in the input vector. Each element doubles the number of subsets.
- **Space Complexity**: O(2^n), as the `result` vector stores all subsets.

 */
