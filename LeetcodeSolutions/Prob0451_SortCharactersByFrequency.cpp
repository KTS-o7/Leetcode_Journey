class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(auto it:s)
            m[it]++;
        vector<pair<int,char>>v;
        pair<int,char>p;
        for(auto it:m)
        {
            p = {it.second,it.first};
            v.push_back(p);
        }
        int n;
        sort(v.begin(),v.end());
        string ans = "";
        
        for(int i = v.size()-1;i>=0;i--)
        {
            n = v[i].first;
            while(n>0)
            {
                ans+=v[i].second;
                n--;
            }
        }
        return ans;
    }
};

// Time comeplexity : O(NlogN)
// Space complexity : O(N)
// N = length of string s
// Code explained 
// 1. Create a map to store the frequency of each character in the string.
// 2. Create a vector of pairs to store the frequency and the character. pair will hold the frequency and the character. so that we can keep track of character with maximum frequency.
// 3. Sort the vector in ascending order.
// 4. Create a string to store the answer.
// 5. Traverse the vector from the end and add the character to the answer string n times where n is the frequency of the character.
// 6. Return the answer string.
