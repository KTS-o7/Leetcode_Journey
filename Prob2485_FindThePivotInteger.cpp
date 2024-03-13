// approach 1 : Mathematical way

class Solution {
public:
    int pivotInteger(int n) {
        int sum = (n)*(n+1)/2;
        int pivot = sqrt(sum);
        return pivot*pivot == sum ? pivot:-1;
        
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)
// Logic explained : 
// Pivot integer is the integer such that the sum of all integers from 1 to pivot is equal to the sum of all integers from pivot to n.
// So, the sum of all integers from 1 to n is n*(n+1)/2.
// Let's say the pivot integer is x, then the sum of all integers from 1 to x is x*(x+1)/2 and the sum of all integers from x to n is n*(n+1)/2 - x*(x-1)/2.
// So, the sum of all integers from 1 to x is equal to the sum of all integers from x to n.
// So, x*(x+1)/2 = n*(n+1)/2 - x*(x-1)/2
// x*(x+1) + x*(x-1) = n*(n+1)
// 2*x^2 = n*(n+1)
// x^2 = n*(n+1)/2
// x = sqrt(n*(n+1)/2)
// If x is an integer, then it is the pivot integer, otherwise, there is no pivot integer.



// Approach 2: Binary Search
class Solution {
public:
    int pivotInteger(int n) {
        long long int l = 1, r = n;
        while(l <= r) {
            long long int mid = l + (r-l)/2;
            long long int sum1 = mid*(mid+1)/2;
            long long int sum2 = mid*(mid-1)/2;
            if(sum1 == n*(n+1)/2 - sum2) {
                return mid;
            }
            else if(sum1 < n*(n+1)/2 - sum2) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return -1;
    }
};

// Time Complexity: O(logn)
// Space Complexity: O(1)
// Logic explained :
// We can use binary search
// Let's say the pivot integer is x, then the sum of all integers from 1 to x is x*(x+1)/2 and the sum of all integers from x to n is n*(n+1)/2 - x*(x-1)/2.    
// So, the sum of all integers from 1 to x is equal to the sum of all integers from x to n.
// So, x*(x+1)/2 = n*(n+1)/2 - x*(x-1)/2
// Calculate mid and find sums and compare


// Approach 3: Brute Force
class Solution {
public:
    int pivotInteger(int n) {
        for(int i = 1; i <= n; i++) {
            long long int sum1 = i*(i+1)/2;
            long long int sum2 = i*(i-1)/2;
            if(sum1 == n*(n+1)/2 - sum2) {
                return i;
            }
        }
        return -1;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic explained :
// We can use brute force approach
// Let's say the pivot integer is x, then the sum of all integers from 1 to x is x*(x+1)/2 and the sum of all integers from x to n is n*(n+1)/2 - x*(x-1)/2.
// So, the sum of all integers from 1 to x is equal to the sum of all integers from x to n.
// check every integer from 1 to n and find the pivot integer


// Appraoch 4: using prefix sum
class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefix(n+1, 0);
        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + i;
        }
        for(int i = 1; i <= n; i++) {
            if(prefix[i-1] == prefix[n] - prefix[i]) {
                return i;
            }
        }
        return -1;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
