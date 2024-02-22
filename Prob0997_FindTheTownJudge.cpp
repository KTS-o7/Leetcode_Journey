class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        vector<int>v(n+1,0);
        vector<int>t(n+1,0);

        for(auto it:trust)
        {
            v[it[0]]++;
            t[it[1]]++;

            //cout<<v[it[0]]<<endl;
        }
        for(int i=1;i<n+1;i++)
        {
            if(v[i]==0 && t[i]==n-1)
                return i;
        }
        return -1;
        
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
// Code logic explained :
// 1. Create two vectors v and t of size n+1 and initialize all the elements to 0.
// 2. V is used to store if a person trusts someone and t is used to store if a person is trusted by someone.
// 3. Traverse through the trust vector and increment the value
// 4. Traverse through the vector and check if the value of v[i] is 0 and t[i] is n-1 then return i.
// 5. If no such person is found then return -1.

// Approach 2:
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        vector<int>v(n+1,0);
       // vector<int>t(n+1,0);

        for(const auto& it:trust)
        {
            v[it[0]]--;
            v[it[1]]++;

            //cout<<v[it[0]]<<endl;
        }
        for(int i=1;i<n+1;i++)
        {
            if( v[i]==n-1)
                return i;
        }
        return -1;
        
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
// Code logic explained :
// 1. Create a vector v of size n+1 and initialize all the elements to 0.
// 2. Traverse through the trust vector and decrement the value of v[it[0]] and increment the value of v[it[1]].
// 3. This is done becuase if a person trusts someone then he is not a judge and if a person is trusted by someone then he is might be a judge.
// 4. Traverse through the vector and check if the value of v[i] is n-1 then return i.
// 5. If no such person is found then return -1.
// 6. const auto& is used to avoid the creation of a new vector and to avoid the overhead of copying the vector.
// 7. auto is used to avoid the overhead of specifying the type of the vector.
// 8. & is used to avoid the overhead of copying the vector.