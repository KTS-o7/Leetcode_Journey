// Approach 1 : With a vector counter
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int>counter(nums.size()+2,0);
        

        for(auto it : nums)
        {
                counter[it]++;
                //cout<<counter[it]<<endl;
    
            
            if(counter[it]==2)
                return it;
                
        }
        
        return -1;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
// Logic explained:
// We use a vector counter to store the count of each element in the input vector.
// We iterate through the input vector and increment the count of each element in the counter vector.
// If the count of an element in the counter vector is equal to 2, we return that element as the duplicate element.
// If no duplicate element is found, we return -1.

// Approach 2 : With Floyd's Tortoise and Hare (Cycle Detection)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int slow = nums[0];
        int fast = nums[0];
        
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        fast = nums[0];
        
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
// Logic explained:
// We use Floyd's Tortoise and Hare algorithm to detect the cycle in the input vector.
// We initialize two pointers slow and fast to the first element of the input vector.
// We move the slow pointer one step at a time and the fast pointer two steps at a time until they meet at a common point.
// We reset the fast pointer to the first element of the input vector and move both pointers one step at a time until they meet at the duplicate element.
// We return the duplicate element.
// Why this method always returns the duplicate element?
// First loop will tell you that there is a cycle in the array.
// Second loop will tell you the starting point of the cycle.
// visually it looks as follows
// 1->3->4->2->2
// At first  fast and slow pointers will be at 1 and 1
// Then fast will be at 3 and slow will be at 3
// Then fast will be at 2 and slow will be at 4
// Then fast will be at 2 and slow will be at 2

