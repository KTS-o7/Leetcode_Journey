class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>v;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        while(!m.empty())
        {
            vector<int>temp;
            for(auto it= m.begin();it!=m.end();)
            {
                if(it->second!=0)
                {
                    temp.push_back(it->first);
                    it->second--;
                }
                if(it->second==0)
                    it =  m.erase(it);
                    
                else
                    ++it;
            }
            v.push_back(temp);
        }
        return v;
    }
};

// Time complexity : O(n)
// Space complexity : O(n)

/*Code Explained
Initialization:

vector<vector<int>> v;: Initialize an empty vector v to store the resulting matrix.
unordered_map<int, int> m;: Initialize an unordered map m to store the frequency of each unique element in the input vector.
Counting Frequency:

Use a loop to iterate through the elements of the input vector (nums) and count the frequency of each unique element in the unordered map m.
Constructing the Matrix:

Use a while loop to process until the frequency map (m) is not empty.
Inside the loop, use another loop (for loop) to iterate over the entries of the frequency map.
If the frequency of the current element is not zero, add the element to the current row (temp) and decrease its frequency.
If the frequency becomes zero, remove the entry from the map using m.erase(it).
Continue the loop until the frequency map is empty.
Returning the Result:

Return the resulting matrix.*/