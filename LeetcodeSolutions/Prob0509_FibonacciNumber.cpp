class Solution {
public:
    int fib(int n) {
        
        int v[31];
        
        v[0] = 0;
        v[1] = 1;
        for(int i = 2;i<=n;i++)
            v[i] = v[i-1] + v[i-2];
        return v[n];

        
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
// Code explained :
// We are using a bottom up approach to solve this problem. We are using an array v to store the fibonacci numbers. We are storing the first two fibonacci numbers in the array and then we are using a for loop to calculate the fibonacci numbers from 2 to n. We are using the formula v[i] = v[i-1] + v[i-2] to calculate the fibonacci numbers. Finally we are returning the value of v[n] which is the nth fibonacci number.
