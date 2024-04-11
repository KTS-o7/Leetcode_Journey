// Brute force code
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int>v,t;
        t={12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789};
        for(int i=0;i<t.size();i++)
        {
            if(t[i]>=low && t[i]<=high)
                v.push_back(t[i]);
        }
        return v;
    }
};
// Time complexity : O(1)
// Space complexity : O(1)

// Actual logic :
    class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            vector<int> res;
            for (int i = 1; i <= 9; ++i) {
                int num = i;
                for (int j = i + 1; j <= 9; ++j) {
                    num = num * 10 + j;
                    if (num >= low && num <= high) {
                        res.push_back(num);
                    }
                }
            }
            sort(res.begin(), res.end());
            return res;
        }
    };
// Time complexity : O(nlogn)
// Space complexity : O(n)

// Code logic :
// The idea is to generate all possible sequential digits and then check if they are in the range of low and high. We can generate all possible sequential digits by using a nested loop. The outer loop will iterate from 1 to 9 and the inner loop will iterate from the outer loop variable to 9. We will keep on multiplying the outer loop variable by 10 and adding the inner loop variable to it. We will then check if the generated number is in the range of low and high. If it is, we will add it to the result vector. Finally, we will sort the result vector and return it. The time complexity of this approach is O(nlogn) where n is the number of sequential digits in the range of low and high. The space complexity is O(n) where n is the number of sequential digits in the range of low and high.
// The time complexity of the above approach is O(nlogn) where n is the number of sequential digits in the range of low and high. The space complexity is O(n) where n is the number of sequential digits in the range of low and high.