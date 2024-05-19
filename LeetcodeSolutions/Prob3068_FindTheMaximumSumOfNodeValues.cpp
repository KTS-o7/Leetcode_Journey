static auto fastio = [](){
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        };


class Solution {
        
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = 0;
        int changes = 0;
        int minDiff = INT_MAX;
        
        for (int num : nums) {
            int xorNum = num ^ k;

            if (num < xorNum) {
                changes++;
                res += xorNum;
            } else {
                res += num;
            }

            minDiff = min(minDiff, abs(num - xorNum));
        }

        if (changes % 2 == 1)
            return res - minDiff;
        else
            return res;
    }
        
};

// Time complexity: O(n)
// Space complexity: O(1)

// Logic explained :
// 1. We need to find the maximum value of the sum of the array after performing XOR operation on the elements of the array.
// 2. Perform XOR operation on an element and check if the result is greater than the element itself.
// 3. If the result is greater than the element, then add the result to the sum.
// 4. If the result is less than the element, then add the element to the sum.
// 5. If the result is greater than the element, then increment the changes variable.
// 6. Find the minimum difference between the element and the result.
// 7. This is to offset odd number of changes.
// 8. If the number of changes is odd, then subtract the minimum difference from the sum.
// 9. Return the sum.
