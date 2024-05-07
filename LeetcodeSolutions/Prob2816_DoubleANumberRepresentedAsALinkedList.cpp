/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        stack<ListNode*>st;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            st.push(temp);
            temp=temp->next;
        }

        int carry = 0, newVal = 0;
        while(!st.empty())
        {
            temp = st.top();
            st.pop();
            newVal = 2*temp->val + carry;
            carry = newVal/10;
            newVal = newVal%10;
            //cout<<carry<<newVal<<endl;
            temp->val = newVal;
        }
        if(carry)
        {
            ListNode* newhead = new ListNode(carry,head);
            return newhead;
        }

        return head;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

// Explanation:
// 1. Traverse the linked list and store the nodes in a stack.
// 2. Traverse the stack and double the value of each node and store the carry.
// 3. If there is a carry after the traversal, add a new node with the carry at the beginning of the linked list.
// 4. Return the head of the linked list.