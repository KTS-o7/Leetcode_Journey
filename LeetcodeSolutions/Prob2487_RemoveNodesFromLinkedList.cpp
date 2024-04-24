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
    ListNode* removeNodes(ListNode* head) {
        std::ios::sync_with_stdio(false);
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp != nullptr) {
            if(st.empty()) {
                st.push(temp);
                temp = temp->next;
            }
            else {
                while(!st.empty() && temp->val > st.top()->val)
                    st.pop();
                st.push(temp);
                temp=temp->next;
            }
        }
        
        ListNode* newHead = nullptr;
        while(!st.empty()) {
            temp  = st.top();
            st.pop();
            temp->next = newHead;
            newHead = temp;
        }
        
        return newHead;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)

// Logic Explained
// 1. We will be using the concept of monotonic stack to solve this problem.
// 2. The question asks us to remove all the nodes which have a node greater than them on thier right.
// 3. This will keep the final linked list in a decending order.
// 4. The relative ordering of linkedlist will be maintained.
// 5. We will use a stack to store the nodes but the stack is monotonically increasing. This is because the end of newList will be stored in top of stack.
// 6. We will iterate through the linked list and if the stack is empty we will push the node.
// 7. If the stack is not empty we will pop all the nodes which are smaller than the current node.
// 8. We will push the current node.
// 9. Once we have completely traversed the linked list we will pop the nodes from the stack and create a new linked list.
// 10. Now we create a newHead pointing to nullptr.
// 11. We will pop the nodes from the stack then we will point thier next to newHead and then we will update the newHead to the current node.
// 12. We are rebuilding the answer list right to left.
// 13. Finally we will return the newHead.