#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'checkDivisibility' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts STRING_ARRAY arr as parameter.
#

divides = set() 
def populate():
    for i in range(0,1000,8):
        count = [0]*10
        count[i%10]+=1
        count[(i//10)%10]+=1
        count[(i//100)%10]+=1
        n = 0
        for j in count:
            n = (n<<3) + ((1<<j)-1)
        divides.add(n)

populate()
    
    
def checkDivisibility(arr):
    # Write your code here
    ans = list()
    for item in arr:
        
        test = False
        if len(item) == 1:
            test = int(item) % 8 ==0
        if len(item) == 2:
            test = (int(item)%8 == 0) or (int(item[::-1])%8 == 0)
        
        else:
            count = [0]*10
            
            for it in list(item):
                var = int(it)
                if count[var]<3 : count[var] +=1
                
            a = 0
            for i in count:
                a = (a<<3) + ((1<<i)-1)
            
            for num in divides:
                if(a&num) == num:
                    test = True
                    break
        ans.append("YES" if test else "NO")
    return ans        
                

    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input().strip())

    arr = []

    for _ in range(arr_count):
        arr_item = input()
        arr.append(arr_item)

    result = checkDivisibility(arr)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()

'''
Question link :
https://www.hackerrank.com/challenges/manasa-loves-maths/problem

Problem Statement:
You are given an integer N. Is there a permutation of digits of integer that's divisible by 8? A permutation of digits of integer N is defined as an integer formed by rearranging the digits of N. For example, if the number N = 123, then {123, 132, 213, 231, 312, 321} are the possible permutations.

Input Format
The first line contains an integer T i.e. number of test cases.
T lines follow, each containing the integer N.

Output Format
For each test case print YES if there exists one such re-arrangement of N such that it is divisible by 8 or NO if there isn't.

Constraints
1 <= T <= 45
0 <= N <= 10^110

Note
Re-arrangements of 10 are {10, 01} which boils down to {10, 1}.

Sample Input

2
61
75
Sample Output

YES
NO
Explanation
Test case #00: 16 is permutation of 61 which is divisible by 8.
Test case #01: None of permutation of 75, {57, 75}, are divisible by 8.
'''

'''
Answer Intution :
The provided code is a solution to a problem related to divisibility by 8. Let's break down the code and understand its logic.

The code begins with the declaration of a set called `divides`. This set will store the numbers that are divisible by 8.

The `populate()` function is then defined. This function is responsible for populating the `divides` set with numbers that are divisible by 8. It does this by iterating over a range of numbers from 0 to 1000 with a step of 8. For each number, it calculates the count of each digit in the number using the `count` list. The count is stored in the `count` list at the index corresponding to the digit. For example, if the number is 123, then `count[1]` will be 1, `count[2]` will be 1, and `count[3]` will be 1.

Next, the function calculates a new number `n` using the counts of each digit. It does this by left-shifting `n` by 3 bits and adding the binary representation of the count of each digit minus 1. This creates a unique number based on the counts of each digit.

Finally, the calculated number `n` is added to the `divides` set.

After populating the `divides` set, the `checkDivisibility()` function is defined. This function takes an array `arr` as input and returns a list of strings indicating whether each element in the array is divisible by 8.

The function iterates over each item in the array `arr`. For each item, it checks if the length of the item is 1, 2, or greater than 2.

- If the length is 1, it checks if the item is divisible by 8 using the modulo operator `%`.
- If the length is 2, it checks if either the item or its reverse is divisible by 8.
- If the length is greater than 2, it calculates the count of each digit in the item and creates a number `a` using the same logic as in the `populate()` function. Then, it iterates over the numbers in the `divides` set and checks if the bitwise AND operation between `a` and each number in `divides` is equal to the number itself. If it is, then the item is divisible by 8.

The result of the divisibility test for each item is appended to the `ans` list as either "YES" or "NO".

Finally, the `ans` list is returned as the result of the function.

In summary, the code uses a set to store numbers that are divisible by 8. It then checks the divisibility of each item in an array by either performing direct calculations or using bitwise operations. The result is a list indicating whether each item is divisible by 8.

'''