class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        std::ios::sync_with_stdio(false); // Speeds up I/O operations by unsynchronizing C and C++ standard streams
        cin.tie(nullptr); // Unties cin from cout for faster I/O operations

        int rep,act,expsum,actsum,n=nums.size(); // Declare variables: rep (repeated number), act (actual number), expsum (expected sum), actsum (actual sum), n (size of nums)
        
        vector<int>ans(2,0); // Declare a vector of size 2 to store the answer
        
        unordered_set<int>s; // Declare an unordered set to store unique numbers
        
        actsum = (n*(n+1))/2; // Calculate the sum of first n natural numbers
        
        for(int i=0;i<n;i++) // Loop through nums
            expsum+=nums[i]; // Calculate the sum of numbers in nums
        
        for(int i=0;i<n;i++){ // Loop through nums
            
            if(s.find(nums[i]) == s.end()) // If the number is not in the set
                s.insert(nums[i]); // Insert the number into the set
            else{
                rep = nums[i]; // If the number is already in the set, it is the repeated number
                break;
            }
        }
        act= actsum-expsum+rep; // Calculate the actual number by subtracting the expected sum from the actual sum and adding the repeated number
        
        ans[0] = rep; // Store the repeated number in the answer vector
        ans[1] = act; // Store the actual number in the answer vector
        return ans; // Return the answer vector
    }
};

// Time Complexity: O(n)

// Space Complexity: O(n)

/*Code explained :
Problem Statement: The problem is to find two numbers in the given array: one that appears twice (the duplicate), and one that is missing.

Algorithm Overview: The algorithm uses a combination of mathematical formulas, a hash set for tracking duplicates, and a vector for storing the results.

Detailed Steps:

std::ios::sync_with_stdio(false); and cin.tie(nullptr);: These two lines are used to speed up input/output operations in C++.

int rep,act,expsum,actsum,n=nums.size();: Here, five integer variables are declared and initialized. rep will store the repeated number, act will store the actual missing number, expsum will store the sum of the numbers in the array, actsum will store the sum of first n natural numbers, and n is the size of the input array.

vector<int>ans(2,0);: A vector ans of size 2 is declared to store the final answer.

unordered_set<int>s;: An unordered set s is declared to keep track of the numbers in the array.

actsum = (n*(n+1))/2;: The sum of first n natural numbers is calculated using the formula n*(n+1)/2 and stored in actsum.

for(int i=0;i<n;i++) expsum+=nums[i];: A loop is run to calculate the sum of the numbers in the array and the result is stored in expsum.

for(int i=0;i<n;i++){...}: Another loop is run to find the repeated number. For each number in the array, it is checked if the number is already present in the set s. If it is not present, it is inserted into the set. If it is present, it means the number is repeated and it is stored in rep.

act= actsum-expsum+rep;: The actual missing number is calculated by subtracting expsum from actsum and adding rep.

ans[0] = rep; and ans[1] = act;: The repeated number and the actual missing number are stored in the answer vector ans.

return ans;: Finally, the answer vector ans is returned.

This algorithm works in O(n) time complexity as it makes a single pass over the array, and it uses O(n) extra space for the unordered set. The unordered set helps in finding the duplicate number in constant time. The missing number is found by subtracting the sum of the array elements from the sum of first n natural numbers and adding the duplicate number. This approach works because the sum of first n natural numbers is the sum of all numbers from 1 to n, and thus includes the missing number exactly once. When we subtract the sum of the array elements from this, we get the negative of the duplicate number plus the missing number. Adding the duplicate number gives us the missing number. */