/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    string serialize(TreeNode* root) {
        string ans = "";
        TreeNode* temp = root;
        queue<TreeNode*>q;
        q.push(temp);
        while(!q.empty())
        {
            for(int i = 0; i<q.size(); i++)
            {
                if(q.front() != nullptr)
                {
                    ans+=to_string(q.front()->val);
                    ans+='#';
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                else
                {
                    ans+="null#";
                }
                q.pop();
            }
        }
        return ans;
        
    }

TreeNode* deserialize(string data) {
    vector<string> nodes;
    int l = 0, r = 0;
    while (l < data.size()) {
        while (r < data.size() && data[r] != '#') {
            r++;
        }
        nodes.push_back(data.substr(l, r - l));
        l = r + 1; 
        r = l; 
    }

    if(nodes[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*>q;
    q.push(root);
    int ind = 1;

    while(!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        if(nodes[ind]!="null")
        {
            TreeNode* temp = new TreeNode(stoi(nodes[ind]));
            curr->left = temp;
            q.push(temp);
        }
        else
        {
            curr->left = nullptr;
        }
        ind++;

        if(nodes[ind]!="null")
        {
            TreeNode* temp = new TreeNode(stoi(nodes[ind]));
            curr->right = temp;
            q.push(temp);
        }
        else
        {
            curr->right = nullptr;
        }
        ind++;
    }
    return root;   
}

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


// Time Complexity of serialize: O(N)
// Space Complexity of serialize: O(N)

// Time Complexity of deserialize: O(N)
// Space Complexity of deserialize: O(N)

// Explanation:
// The Serialize function:
/*
1. Initialize a string ans to store the serialized string.
2. we need to perform a level order traversal of the binary tree.
3. Push the root node into the queue.
4. While the queue is not empty, iterate through the queue.
5. If the front element of the queue is not null, add the value of the node to the string ans.
6. Add a '#' to separate the values.
7. Push the left and right children of the node into the queue.
8. If the front element of the queue is null, add "null#" to the string ans.
9. Pop the front element of the queue.
10. Once the queue is empty, return the string ans.
*/

// The Deserialize function:
/*
1. Create a vector of strings to store the nodes of the serialized string.
2. Initialize two pointers l and r to 0.
3. Iterate through the serialized string.
4. While the right pointer is less than the size of the string and the character at the right pointer is not '#', increment the right pointer.
5. Once the right pointer reaches the '#' character, push the substring from the left pointer to the right pointer into the vector.
6. Increment the left pointer to the right pointer + 1.
7. Set the right pointer to the left pointer.
8. This will convert the serialized string into a vector of strings.
9. If the first element of the vector is "null", return nullptr. It means the tree is empty.
10. Create a root node with the value of the first element of the vector.
11. Push the root node into the queue.
12. Initialize an index variable to 1.
13. While the queue is not empty, iterate through the queue.
14. Get the front element of the queue.
15. If the value at the index of the vector is not "null", create a new node with the value and assign it as the left child of the current node.
16. Push the left child into the queue.
17. Increment the index.
18. If the value at the index of the vector is not "null", create a new node with the value and assign it as the right child of the current node.
19. Push the right child into the queue.
20. Increment the index.
21. Once the queue is empty, return the root node.
*/