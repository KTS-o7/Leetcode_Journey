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


// Time Complexity: O(N)
// Space Complexity: O(N)

// Explanation:
// 1. Find the middle of the linked list using the slow and fast pointer.
// 2. Push the second half of the linked list into the stack.
// 3. Break the linked list into two halves.
// 4. Merge the two linked lists by popping the elements from the stack and inserting them into the first half of the linked list.
// 5. Return the reordered linked list.
// This will produce a linked list in this order: 1st element, last element, 2nd element, 2nd last element, 3rd element, 3rd last element, and so on.