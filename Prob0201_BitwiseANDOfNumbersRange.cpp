class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(!left)
            return 0;
        if(left == right)
            return left;
        int check = 1<<31;
        //cout<<check<<endl;
        int ans = 0;
        int place = 31;
        
        while((check&left) == (check&right))
            {
                ans= ans|(check&left);
                //cout<<ans<<endl;
                place--;
                check = 1<<place;
            }
        return ans;
        
    }
};

// Time complexity  : O(32) = O(1)
// Space complexity : O(1)
// Code explained :
// 1. We will first check if the left is 0, then the answer will be 0.
// 2. If the left is equal to right, then the answer will be left.
// 3. We will then check the leftmost bit of the left and right numbers.
// 4. We will keep checking the leftmost bit of the left and right numbers until they are equal.
// 5. We will keep adding the leftmost bit of the left number to the answer.
// 6. We will keep shifting the leftmost bit to the right until we find the leftmost bit of the left and right numbers are not equal.
// 7. At the end, we will return the answer.

// Approach 2:
class solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while(left != right) {
            left >>= 1;
            right >>= 1;
            count++;
        }
        return left << count;
    }
};

// Time complexity  : O(32) = O(1)
// Space complexity : O(1)
// Code explained :
// 1. We will keep right shifting the left and right numbers until they are equal.
// 2. We will keep a count of the number of times we have right shifted the numbers.
// 3. At the end, we will left shift the left number by the count and return the answer.
// 4. This will give us the required answer.

// Approach 3:
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left < right) {
            right = right & (right - 1);
        }
        return right;
    }
};

// Time complexity  : O(32) = O(1)
// Space complexity : O(1)
// Code explained :
// 1. We will keep doing the bitwise AND of the right number and the right number - 1 until the left and right numbers are equal.
// 2. At the end, we will return the right number.
// 3. This will give us the required answer.

