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
    ListNode* removeElements(ListNode* head, int val) {
        
        
        while(head!=NULL and head->val==val){
            head=head->next;
            }
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            if(curr->val==val){
                prev->next=curr->next;
            }
            else{
                prev=curr;
            }
        curr=curr->next;
        }
        return head;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Code logic explained :
// 1. We will first check if the head is NULL or not and if the head value is equal to the val, then we will move the head to the next node.
// 2. Then we will take two pointers prev and curr and initialize prev to NULL and curr to head.
// 3. We will then traverse the linked list and check if the curr value is equal to the val, then we will make the prev->next point to curr->next.
// 4. If the curr value is not equal to the val, then we will make the prev point to curr.
// 5. In the end, we will return the head of the linked list.