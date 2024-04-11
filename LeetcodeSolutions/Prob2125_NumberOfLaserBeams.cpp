class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        vector<int>laser(bank.size(),0);
        for(int i=0;i<bank.size();i++){
            int cnt =0;
            for(int j=0;j<bank[0].size();j++)
                cnt+= (bank[i][j]=='1')?1:0;
            laser[i]=cnt;
        }
        int ans =0,l=0,r=1;
        while(r<bank.size())
            {
            if(laser[r]==0)
                r++;
            else
                {
                ans+=laser[l]*laser[r];
                l=r;
                r++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(n*m)
// Space Complexity : O(n)

/* Code Explained
Input/Output Optimization:

std::ios::sync_with_stdio(false);: Disable synchronization with C I/O for faster input/output.
cin.tie(nullptr);: Untie cin from cout for faster input.
Counting '1's in Each Row:

vector<int> laser(bank.size(), 0);: Initialize a vector laser to store the count of '1's in each row. The size of the vector is the number of rows in the bank.
Use nested loops to iterate through each cell in the bank and count the number of '1's in each row. Store the counts in the laser vector.
Counting Valid Laser Beams:

int ans = 0, l = 0, r = 1;: Initialize variables for the answer (ans) and two pointers (l and r) to iterate through the rows of the bank.

while (r < bank.size()) { ... }: Iterate through the 'laser' vector to count the valid laser beams.

If the count of '1's in the current row (laser[r]) is zero, move to the next row (r++).

If there are '1's in the current row, calculate and add the count of '1's in the current row (laser[l]) multiplied by the count of '1's in the next row (laser[r]) to the answer (ans).

Update the pointers to move to the next row.



Returning the Result:

Return the final count of valid laser beams.*/


/*Logic Of code
Counting '1's in Each Row:
vector<int> laser(bank.size(), 0);: Initializes a vector laser with the same size as the number of rows in the bank vector. This vector will be used to store the count of '1's in each row.

Nested Loops: Iterates through each cell in the bank vector using nested loops. The outer loop (for(int i=0;i<bank.size();i++)) iterates over rows, and the inner loop (for(int j=0;j<bank[0].size();j++)) iterates over columns.

Counting '1's: Increments a counter (cnt) whenever a cell contains the value '1'. The count for each row is then stored in the laser vector.

Counting Valid Laser Beams:
int ans = 0, l = 0, r = 1;: Initializes variables ans (answer) to zero and two pointers (l and r) to iterate through the rows of the bank vector. l represents the starting row, and r represents the next row.

While Loop (while (r < bank.size())): Iterates through the rows of the bank vector.

Checking for '1's in the Current Row (laser[r] == 0): If the count of '1's in the current row (laser[r]) is zero, it means there are no '1's in that row. In such a case, move to the next row (r++).

Calculating Valid Laser Beams: If there are '1's in the current row, calculate and add the product of the count of '1's in the current row (laser[l]) and the count of '1's in the next row (laser[r]) to the answer (ans).

Updating Pointers: Update the pointers to move to the next row (l = r) and the row after that (r++).

Returning the Result:
Return Statement (return ans;): Returns the final count of valid laser beams (ans).*/