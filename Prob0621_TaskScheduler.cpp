class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freqCount;
        int maxCount = INT_MIN;
        for(int i =0;i<tasks.size();i++)
            freqCount[tasks[i]]++;
        
        for(auto it:freqCount)
        {
            maxCount = max(maxCount,it.second);
        }

        int fmax=0;

        for(auto it:freqCount)
        {
            if(it.second == maxCount)
                fmax++;
        }
        return tasks.size()>((n+1)*(maxCount-1)+fmax)?tasks.size():((n+1)*(maxCount-1)+fmax);
        
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
// n is the number of tasks

// Logic Explained : 
// 1. We first count the frequency of each task and store it in a map.
// 2. We then find the maximum frequency of any task.
// 3. We then find the number of tasks that have the maximum frequency.
// 4. We then calculate the time required to complete all the tasks.
// 5. We return the maximum of the time required to complete all the tasks and the number of tasks.


// Problem logic is as follows
// Link : https://leetcode.com/problems/task-scheduler/description/comments/1566970

// Explaination 2 :
/*
Let's consider situation when there are idles

I marked idles with underscore symbol

Case 1: Only 1 character with maximum occurence.

Example input:
n = 2
A occures 3 times

Minimum sequence will be the following:
A _ _ A _ _ A

As you see the minimum possible length will be 7

Case 2: There are several characters with maximum occurences

Example input:
n = 2
A occures 3 times
B occures 3 times

Minimum sequence will be the following:
A B _ A B _ AB

As you see the minimum possible length will be 8

Case 3: There one or several characters with maximum occurences and there are other symbols

Depending on the number of symbols there could be 2 situations

Example input:
n = 2
A occures 3 times
B occures 3 times
C occures 1 time

Minimum sequence will be the following:
A B C A B _ AB

As you see there are still gaps between symbols the minimum possible length will be still 8
Note that the minimum length cannot be less than 8 and the total number of characters 7 is still less than 8

Example input:
n = 2
A occures 3 times
B occures 3 times
C occures 2 times
D occures 2 times
E occures 1 time

Minimum sequence will be the following:
A B C D A B C D AB E

As you see there are no gaps between characters and the minimum possible length will be still 11
Note than 11 is the total number of all elements

How we calculate the minimum length of sequence?
Observe Case 1 and Case 2:
A _ _ A _ _ A is the same as (A _ _ A _ _) + (A)
A B _ A B _ AB is the same as (A B _ A B _) + (A B)

The formula is the following:
count - occurence of symbol with maximum number of occurences
(n + 1) - number of elements in repeated interval 'A _ _' or 'A B _'.
(count - 1) - maximum occurences of character with maximum maximum occurence except the last occurence of that character
(count - 1) * (n + 1) - minimum number of symbols except the last one
k - number of characters with maximum occurence.
In Case 1 k = 1
In Case 2 k = 2

(count - 1) * (n + 1) + k - minimum number of elements for Case 1 or Case 2

What about Case 3?
It is minimum of 2 situations:
a) if there are gaps then the minimum is the same as for Case 1 and Case 2
b) if there are no gaps then the minimum is total number of characters

So final formula for minimum
Let's call
min3a = minimum for Case 3a = (count - 1) * (n + 1) + k
min3b = minimum for Case 3b = total number of characters

finalMinimum = Math.Min(min3a, min3b)

n - number of characters in input
Time complexity: O(n)
Space complexity: O(n)
*/