class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map<char,char>mp1,mp2;
        for(int i = 0;i<s.size();i++)
        {
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }

        for(int i=0;i<s.size();i++)
        {
            if(mp1[s[i]] != t[i] || mp2[t[i]] != s[i])
                return false;
        }       

        return true;
        
    }
};


// Time complexity : O(n)
// Space complexity : O(n)
// Logic explained :
// We will use two maps mp1 and mp2 to store the mapping of characters of s to t and t to s respectively.
// We will iterate through the string and store the mapping of characters of s to t and t to s in the maps.
// Then we will iterate through the string and check if the mapping of characters of s to t and t to s is correct or not.
// If the mappings are not identical then we cant produce the string t from s and string s from t and hence return false.
// If the mappings are identical then we can produce the string t from s and string s from t and hence return true.