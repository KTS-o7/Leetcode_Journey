class Solution {
public:
    bool isPowerOfTwo(int n) {
        
            return (n<1)?false:!(n&(n-1)) ;
        
    }
};

// Time complexity: O(1)
// Space complexity: O(1)
// Code explained :
// Above code is based on following facts
// 1. If a number is power of 2 then it will have only one bit set in its binary representation.
// 2. If a number is power of 2 then n & (n-1) will be 0.
// 3. If a number is power of 2 then n-1 will have all bits set except the bit which is set in n.

