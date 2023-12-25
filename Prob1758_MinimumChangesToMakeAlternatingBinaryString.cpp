class Solution {
public:
    int minOperations(string s) {
        int cntOne=0;
        for(int i =0;i<s.size();i++){
            if(i%2==0)
                {
                    if(s[i]=='1')
                        cntOne++;
                }
            else
            {
                if(s[i]=='0')
                    cntOne++;
            }
        }
        
        return  (cntOne>(s.size()-cntOne))?(s.size()-cntOne):cntOne;
        
    }
};

/*
Code Explanation:
Initialization:

int cntOne = 0;: Initialize a counter variable to count the occurrences of '1' in specific positions.
Iterating Through the String:

The for loop iterates through each character of the input string s.
For each character at index i:
If i is even, check if the character is '1'. If true, increment cntOne.
If i is odd, check if the character is '0'. If true, increment cntOne.
Calculate Minimum Operations:

After counting the occurrences of '1' in specific positions, the code calculates the minimum operations required to make the string alternating.
It returns the minimum of two values: s.size() - cntOne and cntOne. This is done using the ternary conditional operator (? :), which selects the smaller value.
Example:
Let's say the input string is "010101". The loop will iterate through each character and count '1's at even indices and '0's at odd indices. In this case, cntOne would be 3, representing the '1's at positions 0, 2, and 4. The function would then return the minimum of s.size() - cntOne and cntOne, which is 3.

Time Complexity Analysis:
The time complexity of the code is O(N), where N is the length of the input string s. The code iterates through each character of the string once.
Space Complexity Analysis:
The space complexity is O(1), as the code uses a constant amount of space regardless of the input size.*/