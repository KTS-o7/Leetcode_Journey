// Approach 1
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
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        if(head==NULL)
            return head;
        ListNode* temp;
        ListNode* ans;
        temp = head;
        while(temp!=nullptr)
        {
            n++;
            temp=temp->next;
        }
        n = n/2;
        ans = head;
        while(n)
        {
            n--;
            ans=ans->next;
        }
        return ans;
        
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
// Code explained :
// 1. First we find the length of the linked list.
// 2. Then we find the middle element by traversing the linked list again.
// 3. We return the middle element.


// Approach 2 - Two pointer method

class Solution{
    public:
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


// Time complexity: O(n)
// Space complexity: O(1)
// Code explained :
// 1. We use two pointers, slow and fast.
// 2. Slow pointer moves one step at a time and fast pointer moves two steps at a time.
// 3. When fast pointer reaches the end, slow pointer will be at the middle of the linked list.
// 4. We return the slow pointer.