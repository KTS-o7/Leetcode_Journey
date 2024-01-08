class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n!=0 && !(n&0xAAAAAAAA) && !(n&n-1))
        {
            
            return true;}
        return false;
    }
};

/*The function first checks if n is not equal to zero and if the bitwise AND operation between n and 0xAAAAAAAA (which is a hexadecimal representation of the number 10101010101010101010101010101010 in binary) is zero. This checks if n has only even bits set to 0.

The function then checks if the bitwise AND operation between n and n-1 is zero. This checks if n has only one bit set to 1.

If both conditions are true, the function returns true, indicating that n is a power of 4. Otherwise, the function returns false.

*/

// Time Complexity: O(1)
// Space Complexity: O(1)