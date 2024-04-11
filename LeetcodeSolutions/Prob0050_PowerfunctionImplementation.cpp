class Solution {
public:
    // Function to calculate x raised to the power n using Fast Exponentiation
    double myPow(double x, int n) {
        // Handle the case when n is negative by inverting x
        if(n < 0) {
            x = 1 / x;
        } 
        
        // Use a long variable to handle the edge case of n being INT_MIN
        long num = labs(n);
        
        // Initialize the result variable
        double pow = 1;
        
        // Main loop for fast exponentiation
        while (num) { // equivalent to while(num != 0)
            // If the current bit of num is 1, multiply pow by x
            if (num & 1) { // equivalent to if((num & 1) != 0)
                pow *= x;
            }
            
            // Square x for the next iteration
            x *= x;
            
            // Right shift num to check the next bit
            num >>= 1;
        }
        
        // Return the final result
        return pow;
    }
};

// Time complexity : O(logn)
// Space complexity : O(1)
// Code explained :
// 1. We handle the case when n is negative by inverting x.
// 2. We use a long variable to handle the edge case of n being INT_MIN.
// 3. We initialize the result variable.
// 4. We use a while loop to iterate through the bits of num. We multiply pow by x if the current bit of num is 1 and square x for the next iteration. We right shift num to check the next bit.
// 5. We return the final result.

// Binary exponentiation is a trick to calculate the power of a number in O(logn) time complexity.
// It is based on the following two facts:
// 1. If n is even, x^n = (x^(n/2))^2
// 2. If n is odd, x^n = x * (x^(n-1))
// We can use these two facts to calculate the power of a number in O(logn) time complexity.
// The idea is to keep dividing n by 2 and updating x to x^2 until n becomes 0. We multiply the result by x whenever the current bit of n is 1.
// The time complexity of this approach is O(logn) because we are dividing n by 2 in each iteration of the while loop. The space complexity is O(1) because we are using a few variables to store the result.