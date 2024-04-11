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
    void reorderList(ListNode* head) {
        std::ios::sync_with_stdio(false);
        
        if (head == NULL || head->next == NULL) return;
        ListNode* fast= head;
        ListNode* slow = head;
       
        while(fast->next!=NULL && fast->next->next != NULL)
        {
            fast= fast->next->next;
            slow=slow->next;
        }
        stack<ListNode*> st;
        ListNode* node = slow->next;
        while(node != NULL) {
            st.push(node);
            node = node->next;
        }
        slow->next = NULL;

        ListNode* curr = head;
        ListNode* nextNode;
        while(!st.empty()) {
            nextNode = curr->next;
            curr->next = st.top();
            st.pop();
            curr->next->next = nextNode;
            curr = nextNode;
        }
    }
};


// Time complexity : O(n)
// Space complexity : O(n)
// Logic explained :
// 1. We will find the middle of the linked list using the slow and fast pointer approach.
// 2. We will then push the second half of the linked list into a stack.
// 3. We break the list into two parts at mid by setting mid->next to NULL
// 4. We will then iterate through the first half of the linked list and pop the elements from the stack and insert them in between the nodes of the first half.
// 5. We will keep track of the next node of the first half and the next node of the popped element.
// 6. We will then set the next of the current node to the popped element and the next of the popped element to the next node of the current node.
// 7. We will then move the current node to the next node of the popped element.
// 8. We will repeat the above steps until the stack is empty.
// 9. We will get the reordered linked list as the output.