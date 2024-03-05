class Solution {
public:
    int minimumLength(string s) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(s.length()==1)
            return 1;
            //cout<<s.size()<<endl;
        int l =0,r = s.size()-1;
        char c;
        while(l<r)
        {
            if(s[l]!=s[r])
                return r-l+1;
            else
            {
                c = s[l];
                while(s[l]==c && l<=r)
                {
                    l++;
                }
                while(s[r]==c && l<=r)
                {
                    r--;
                }


            }
        }
        return r-l+1;
    }
};

// time complexity: O(n)
// space complexity: O(1)
// code explained:
// 1. If the length of the string is 1, then return 1.
// 2. Initialize the left and right pointer.
// 3. If the left and right pointer are not equal, then return the length of the string.
// 4. If the left and right pointer are equal, then store the character at the left pointer and move the left pointer to the right until the character is not equal to the stored character.
// 5. Similarly, store the character at the right pointer and move the right pointer to the left until the character is not equal to the stored character.
// 6. Return the length of the string.