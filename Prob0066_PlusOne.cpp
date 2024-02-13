class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i=n-1; i>=0; --i) {
            if(digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Code explained :
// 1. We start from the last element of the array and check if it is 9 or not.
// 2. If it is 9, we change it to 0 and move to the next element.
// 3. If it is not 9, we increment it by 1 and return the array.
// 4. If all the elements are 9, we insert 1 at the beginning of the array and return the array.
// 5. This is because if all the elements are 9, then the array will become 1000...0, so we need to insert 1 at the beginning of the array.