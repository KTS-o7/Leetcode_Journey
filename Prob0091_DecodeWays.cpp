class Solution {;
    bool isValid(int code,int len){
        if (len ==1)
            return code>=1 && code<=26;
        return code>=10 && code<=26;
    }

public:

    int numDecodings(string s) {
      
    int n=s.length();
    if(n==0)
        return 0;

    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=(isValid(s[0]-'0',1))?1:0;
    
    for(int i=2;i<=n;i++)
        {
            if(isValid(s[i-1]-'0',1))
                dp[i]+=dp[i-1];
            if(isValid((s[i-2]-'0')*10+s[i-1]-'0',2))
                dp[i]+=dp[i-2];
        }    
    
    return dp[n];
    }
    
};

// Time Complexity: O(N), where N is the length of the input string s. The code iterates through each character of the string once.

// Space Complexity: O(N), as the code uses a vector of size N+1 to store the intermediate results.

/*Code Explanation:
Function isValid:

This function checks if a given code is valid for decoding.
The code is considered valid if it is in the range [1, 26].
The length parameter len is used to distinguish between one-digit and two-digit codes.
Function numDecodings:

This is the main function that calculates the number of decodings for the input string.
It uses dynamic programming to store intermediate results in the vector dp.
The vector dp is of size n + 1 to account for the empty string case.
Initialization:

int n = s.length();: Get the length of the input string.
If the string is empty, return 0.
Dynamic Programming Array Initialization:

vector<int> dp(n + 1, 0);: Create a vector dp initialized with zeros to store the number of decodings up to each position.
Base Cases:

dp[0] = 1;: There is one way to decode an empty string.
dp[1] = (isValid(s[0] - '0', 1)) ? 1 : 0;: Initialize dp[1] based on the validity of the first character.
Dynamic Programming Loop:

Iterate through the string starting from position 2 (i = 2) up to the end of the string (i <= n).
For each position i, check if the current character alone (s[i-1]) is a valid code for decoding individually.
Also, check if the combination of the current and previous characters (s[i-2] and s[i-1]) forms a valid two-digit code for decoding.
Result:

The final result is stored in dp[n], which represents the number of decodings for the entire string.
Time Complexity Analysis:
The time complexity is O(n), where n is the length of the input string. This is because the dynamic programming loop iterates through each character of the string once.
Space Complexity Analysis:
The space complexity is O(n) due to the dynamic programming array dp. The additional space is used to store intermediate results.*/