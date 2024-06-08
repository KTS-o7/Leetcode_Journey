// Brute force approach using set and traversal

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>st;
        string answer = "", word = "", temp = "";
        sentence += ' ';

        for(auto& dict:dictionary)
            st.insert(dict);

        for(char& ch:sentence)
        {
            if(ch == ' ')
            {
                if(answer.size()>0)
                    answer+= ' ';
                
                temp = "";
                for(auto j:word)
                {
                    temp += j;
                    if(st.count(temp))
                        break;
                }
                answer+=temp;
                word = "";
            }
            else
            word+=ch;
        }
        return answer;
        
    }
};

// Time complexity: O(n*m) where n is the length of the sentence and m is the length of the dictionary
// Space complexity: O(m) where m is the length of the dictionary

// Logic explained :
// 1. We first insert all the words in the dictionary into a set.
// 2. We then traverse the sentence and keep adding the characters to the word until we reach a space.
// 3. We then check if the word is present in the dictionary. If it is present, we add the word to the answer.
// 4. If the word is not present in the dictionary, we keep adding the characters to the temp string until we find a word in the dictionary.
// 5. We then add the temp string to the answer.
// 6. We then return the answer.
