class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
            return 0;
        vector<bool>isPrime(n,true);
        isPrime[0]= false;
        isPrime[1]=false;

        for(int i = 2; i<=sqrt(n);++i)
        {
            if(isPrime[i])
            {
                for(int j = i*i;j<n; j+=i)
                    isPrime[j]=false;
            }
        }        
        return count(isPrime.begin(),isPrime.end(),true);
    }
};

// Time Complexity: O(nlog(logn))
// Space Complexity: O(n)
// Code logic explained :
// 1. We are using Seive of Eurosthenes 
// 2. We are creating a vector of boolean of size n and initializing all the elements as true.
// 3. We are marking 0 and 1 as false as they are not prime numbers.
// 4. We are iterating from 2 to sqrt(n) and checking if the number is prime or not.
// 5. If the number is prime, we are marking all the multiples of that number as false.
// 6. Finally we are counting the number of true elements in the vector and returning the count.
// 7. This is the optimized solution for the problem.
