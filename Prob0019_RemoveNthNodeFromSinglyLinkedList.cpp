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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        if(cnt == n) { // if head needs to be removed
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }
        temp = head;
        cnt = cnt - n;
        while(cnt > 1) {
            temp = temp->next;
            cnt--;
        }
        ListNode* toDelete = temp->next;
        temp->next = (temp->next)->next;
        delete toDelete;
        return head;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Code logic explained :
// 1. Count the number of nodes in the linked list.
// 2. If the number of nodes is equal to n then remove the head and return the next node.
// 3. Traverse through the linked list and stop at the node before the node to be removed.
// 4. Remove the node and return the head.
// 5. If the node to be removed is the head then return the next node.

// Approach 2:
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for(int i = 0; i < n; i++) {
            first = first->next;
        }
        while(first != nullptr) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)
// Code logic explained :
// 1. Create a dummy node and point it to the head.
// 2. Create two pointers first and second and point first to the head and second to the dummy node.
// 3. Traverse through the linked list and move the first pointer n times.
// 4. Traverse through the linked list and move both the pointers until the first pointer reaches the end.
// 5. Now the second pointer is at the node before the node to be removed.
// 6. Remove the node and return the head.