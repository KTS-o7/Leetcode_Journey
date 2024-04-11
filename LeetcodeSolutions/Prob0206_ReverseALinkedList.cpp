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
    ListNode* reverseList(ListNode* head) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(head==NULL)
            return NULL;
        ListNode* temp;
        ListNode* prev=NULL;
       
        ListNode*  curr=head;
        
        while(curr!=NULL)
        {
           temp=curr->next;
           curr->next=prev;
           prev=curr;
           curr=temp;


        }
        return prev;
        
    }
};


// Time complexity: O(n)
// Space complexity: O(1)
// Logic explained :
// 1. We will take three pointers prev, curr and temp.
// 2. We will iterate through the linked list and at each iteration we will change the next pointer of the current node to the previous node.
// 3. We will update the prev pointer to the current node and the current node to the next node.
// 4. Finally we will return the prev pointer which will be the head of the reversed linked list.
