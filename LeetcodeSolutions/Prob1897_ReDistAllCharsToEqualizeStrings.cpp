class Solution {
public:
    bool makeEqual(vector<string>& words) {
        auto fastio=[](){
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        };
        vector<int> freq(26);
        for(string &word:words)
            for(char &ch:word)
                freq[ch - 'a']++;

        for(int i=0; i<26; i++)
            if(freq[i]%words.size() != 0)
                return false;

        return true;
    }
};