class Solution {
public:
    string customSortString(string order, string s) {
        int sfreq[26]={0};
        std::ios::sync_with_stdio(false);
        for(char c:s)
            {
                sfreq[c-'a']++;
                //cout<<sfreq[c-'a']<<" "<<c<<endl;
            }
            
        string ans = "";
        for(int i = 0;i<order.size();i++)
        {
                {
                    while(sfreq[order[i]-'a'])
                        {
                            //cout<<order[i]-'a'<<endl;
                            ans+=order[i];
                            sfreq[order[i]-'a']--;
                            //cout<<ans<<endl;
                        }
                }
        }
        for(int i=0;i<26;i++)
        {
            
            while(sfreq[i]!=0)
            {   //cout<<sfreq[i]<<endl;
                ans+=char(i+'a');
                //cout<<ans<<endl;
                sfreq[i]--;
            }
        }
        return ans;

    }
};

// Time complexity: O(n)
// Space complexity: O(1)
// Code explained :
// 1. We will create a frequency array of size 26 and store the frequency of each character in the string s.
// 2. Then we will iterate through the order string and keep adding the characters to the ans string as per the frequency of the characters in the string s.
// 3. Then we will iterate through the frequency array and add the remaining characters to the ans string.
// 4. Return the ans string.