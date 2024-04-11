class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int l = s.size()-1, size = s.size();
        
        if (size <= 1)
            return s;
        while(s[l]==' ')
            l--;
        //cout<<l<<endl;
        
        string temp = "", ans = "";
        
        for (int r = 0; r <= l; r++) {
            if (s[r] != ' '){

                temp += s[r];
                //cout<<temp<<endl;
            }
            else if (temp != "") {
                v.push_back(temp);
                cout<<temp<<endl;
                temp = "";
            }
        }
        if(v.empty())
            return temp;
        
        if (!v.empty()) {
            v.push_back(temp); // Add the last word to the vector
            for (int i = v.size() - 1; i >0; i--) { // Modified loop to include the first word
                ans += v[i];
                ans+=' ';
            }
            ans+=v[0];
        }
        
        return ans;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
// Algorithm explained :
// 1. Create a vector to store the words in the string.
// 2. Truncate all trailing spaces.
// 3. Create a temp string to store the words.
// 4. Traverse the string and add the words to the vector.
// 5. If the character is a space its appended to form a word until a space is encounterd.
// 6. If a space is encountered and temp holds a word then its pushed onto vector and temp is reset.
// 7. If the vector is empty then return the temp.
// 8. If the vector is not empty then traverse the vector in reverse and append the words to form the answer.
// 9. Return the answer.