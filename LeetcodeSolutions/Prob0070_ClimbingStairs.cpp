class Solution {
public:
    // Function to calculate the number of distinct ways to climb stairs
    int climbStairs(int n) {
        // Create a vector 'v' to store the number of ways to reach each step
        std::vector<int> v(n, 0);

        // Base cases: if there is only 1 step, return 1 way, and if there are 2 steps, return 2 ways
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;

        // Initialize the first two steps in the vector
        v[0] = 1;
        v[1] = 2;

        // Fill in the vector using dynamic programming to calculate the number of ways for each step
        for (int i = 2; i < n; i++) {
            v[i] = v[i - 1] + v[i - 2];
        }

        // Return the number of ways to climb to the top (stored in the last element of the vector)
        return v[n - 1];
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

/* Code explained :

# Intuition
The problem of climbing stairs can be approached with a dynamic programming strategy. The intuition here is to recognize that the number of ways to reach a specific step is the sum of the ways to reach the two preceding steps. By iteratively calculating and storing these values, we can determine the total number of distinct ways to climb to the top.

# Algorithm Explanation
1. **Vector Initialization:**
   - A vector `v` is initialized with size `n` to store the number of ways to reach each step.
   ```cpp
   vector<int> v(n, 0);
   ```
   
2. **Base Cases:**
   - Special cases for `n = 1` and `n = 2` are handled separately. If there is only one step, there is one way to climb (`1`). If there are two steps, there are two ways to climb (`1 + 1` or `2`).
   ```cpp
   if (n == 1)
       return 1;
   else if (n == 2)
       return 2;
   ```

3. **Vector Initialization for First Two Steps:**
   - The first two steps are initialized in the vector. `v[0]` represents the number of ways to reach the first step (1 way), and `v[1]` represents the number of ways to reach the second step (2 ways).
   ```cpp
   v[0] = 1;
   v[1] = 2;
   ```

4. **Dynamic Programming Loop:**
   - A loop is used to fill in the vector `v` using dynamic programming. For each step from the third step (`i = 2`) to the top (`n`), the number of ways to reach the current step `v[i]` is calculated as the sum of the ways to reach the two preceding steps (`v[i - 1]` and `v[i - 2]`).
   ```cpp
   for (int i = 2; i < n; i++) {
       v[i] = v[i - 1] + v[i - 2];
   }
   ```

5. **Result Return:**
   - The final result is the number of ways to reach the top, which is stored in the last element of the vector (`v[n - 1]`).
   ```cpp
   return v[n - 1];
   ```

# Summary
This algorithm leverages dynamic programming to build a solution iteratively, avoiding redundant calculations by storing intermediate results in the vector. The vector `v` effectively becomes a memoization table, enabling an efficient calculation of the total number of distinct ways to climb to the top of the stairs.*/