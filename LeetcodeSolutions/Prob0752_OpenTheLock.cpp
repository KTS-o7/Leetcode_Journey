class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
       
        unordered_set<string> dead(deadends.begin(),deadends.end());

        if(dead.find("0000") != dead.end())
            return -1;
        if(target == "0000")
            return 0;

        int steps = 0;
        queue<string> q;
        q.push("0000");
        char actual;
        while(!q.empty())
        {
            steps++;
            for(int size = q.size();size>0;size--)
            {
                string passwd = q.front();
                q.pop();
                for(int i= 0;i<4;i++)
                {
                    actual = passwd[i];
                    passwd[i] = (passwd[i]=='9')?'0':passwd[i]+1;

                    if(passwd == target)
                        return steps;
                    if(dead.find(passwd) == dead.end())
                    {
                        q.push(passwd);
                        dead.insert(passwd);
                    }
                    passwd[i] = actual;

                    passwd[i] = (passwd[i]=='0')?'9':passwd[i]-1;

                    if(passwd == target)
                        return steps;
                    if(dead.find(passwd) == dead.end())
                    {
                        q.push(passwd);
                        dead.insert(passwd);
                    }
                    passwd[i] = actual;
                }

            }
        }
        return -1;
    }
};

// Time Complexity: O(10000) = O(1)
// Space Complexity: O(10000) = O(1)

// Logic Explained:
// 1. We will start from the initial password "0000" and keep changing the digits one by one.
// 2. We will keep track of the deadends and if we reach any deadend, we will not proceed further.
// 3. We will keep track of the steps and return the steps when we reach the target password.
// 4. First we will have a set of deadends named `dead`.
// 5. We will check if the target password is in the deadends, if yes, we will return -1.
// 6. If the target password is "0000", we will return 0.
// 7. We will have a queue to keep track of the passwords.
// 8. We will keep changing the digits one by one and check if the password is in the deadends.
// 9. If not, we will add the password to the queue and increment the steps.
// 10. We will keep doing this until we reach the target password.
// 11. If we reach the target password, we will return the steps.
// 12. If we do not reach the target password, we will return -1.