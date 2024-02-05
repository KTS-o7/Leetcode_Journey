class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]= {};
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
        }
        
        
        for(int i =0;i<s.size();i++)
        {
            if(arr[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};

// Time complexity : O(n)
// Space Complexity : O(1) as the array is of constant size 26.

/*Code explained :
1) First initialize the array of size 26 to hold count of letters.
2) Count the number of occurences of each characters
3) iteratte through the string again to check if any letter has the occurence  = 1 , if yes return the index else return -1*/