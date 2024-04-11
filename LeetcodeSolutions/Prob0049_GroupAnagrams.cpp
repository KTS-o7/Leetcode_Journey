// Brute logic
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int size = strs.size();
        vector<int> seen(size,0);
        vector<vector<int>>arr(size,vector<int>(26,0));
        for(int i = 0;i<size;i++)
        {
            for(int j =0;j<strs[i].size();j++)
            {
                arr[i][strs[i][j]-'a']++;
            }
        }
        vector<vector<string>>ans;
        for(int i = 0;i<size;i++)
        {
            vector<string>temp;
            
            
            for(int j=i+1;j<size;j++)
            {
                if(arr[i]==arr[j]  && seen[i]==0)
                {   
                    //cout<<" "<<seen[i]<<" "<<seen[j]<<endl;
                    seen[j] = 1;
                    //cout<<seen[j]<<endl;
                    temp.push_back(strs[j]);

                }
            }
                if(!seen[i])
                    temp.push_back(strs[i]);
                if(!temp.empty())    
                ans.push_back(temp);
        }
        return ans;
        
    }
};


// Time complexity: O(n^2)
// Space complexity: O(n)
// Code explained :
// 1. We are using a brute force approach to solve this problem. We are using a 2D vector to store the count of each character in the string.
// 2. We are using a vector of size n to keep track of the strings that we have already seen.
// 3. We are using a vector of size n to keep track of the count of each character in the string.
// 4. We are using a vector of vector to store the final answer.
// 5. We are iterating through the strings and storing the count of each character in the string.
// 6. We are then iterating through the strings and checking if the count of each character in the string is same as the count of each character in the other strings.
// 7. If the count of each character in the string is same as the count of each character in the other strings, then we are adding the string to the vector of vector.
// 8. We are then returning the vector of vector as the final answer.


// Optimized logic

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
       std::ios::sync_with_stdio(false);
       cin.tie(nullptr);
        unordered_map<string, vector<string>> anagramGroups;

        for (int i = 0; i < size; i++) {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());

            anagramGroups[sortedStr].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for (auto& group : anagramGroups) {
            ans.push_back(group.second);
        }

        return ans;
    }
};

// time complexity: O(n)
// space complexity: O(n)

// Code explained:
// 1. We are using an optimized approach to solve this problem. We are using a hash map to store the sorted string as the key and the original string as the value.
// 2. We are iterating through the strings and sorting the string and storing the sorted string as the key and the original string as the value in the hash map.
// 3. We are then iterating through the hash map and storing the value of the hash map in the vector of vector.
// 4. We are then returning the vector of vector as the final answer.
