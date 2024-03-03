class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //if(strs.size()==1)
          //  return strs[0];
        bool flag = true;
        string ans = "";
        int match = 0;
        sort(strs.begin(),strs.end());
        if(strs[0]=="")
            return "";
        
        while(flag && ans.size()<strs[0].size()){
            int ch = strs[0][match];
            for(int i = 1; i<strs.size(); i++){
                if(ch != strs[i][match])
                     {
                         //flag = false;
                         return ans;
                     }
                
            }
            match++;
            ans+=ch;
        }
        return ans;

        
    }
};

// Time complexity : O(n*m) where n is the number of strings and m is the length of the smallest string.
// Space complexity : O(m) where m is the length of the smallest string.
// Code explained :
// 1. We first sort the strings in the vector of strings.
// 2. Then we take the first string and compare each character of the first string with the corresponding character of the rest of the strings.
// 3. If we find a mismatch, we return the ans string.
// 4. If we find a match, we keep adding the character to the ans string.
// 5. We return the ans string at the end.
