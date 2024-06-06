class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>baselineCount(26,0);
        string temp;
        for(int i =0;i<words[0].size();i++)
            {
                baselineCount[words[0][i]-'a']++;
            }
        for(auto word:words)
        {
            vector<int>newCount(26,0);
            for(const auto& ch:word)
                newCount[ch-'a']++;

            for(int i= 0;i<26;i++)
                baselineCount[i] = min(baselineCount[i],newCount[i]);
        }
        vector<string>answer;
        for(int i =0; i<26;i++)
        {
            while(baselineCount[i]--)
            {
                temp = "";
                temp += 'a'+i;
                answer.push_back(temp);
            }
        }
        return answer;

        
    }
};

// Time complexity : O(N) where N is the total number of characters in all the words
// Space complexity : O(N) There might be N counts of characters in the answer vector


// Logic explained :
// 1. We first create a baselineCount vector of size 26 and initialize it to 0
// 2. We then iterate through the first word and increment the count of each character in the baselineCount vector
// 3. We then iterate through the rest of the words and create a newCount vector for each word and increment the count of each character in the newCount vector
// 4. We then iterate through the baselineCount vector and update the count of each character to the minimum of the count of that character in the baselineCount vector and the newCount vector
// 5. This will give us the count of the common characters in all the words
// 6. We then iterate through the baselineCount vector and add the character to the answer vector the number of times it occurs in the baselineCount vector
// 7. We then return the answer vector