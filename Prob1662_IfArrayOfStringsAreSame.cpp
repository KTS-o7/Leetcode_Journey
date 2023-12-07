class Solution {
public:

    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
          auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
        string fullWord1 = "";
        string fullWord2 = "";
        for(int i = 0; i < word1.size();i++)
            fullWord1 = fullWord1 + word1[i];
        for(int i = 0; i < word2.size();i++)
            fullWord2 = fullWord2 + word2[i];
        return (fullWord1 == fullWord2);
        
        
    }
};

// time complexity: O(n)
// space complexity: O(1)
// This code takes two vectors of strings and then concatenates them into two strings and then compares them.

