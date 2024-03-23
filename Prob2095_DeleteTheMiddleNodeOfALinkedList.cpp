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
    ListNode* deleteMiddle(ListNode* head) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(head==NULL || head->next==NULL)
            return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = slow;

        while(fast != NULL && fast->next != NULL)
            {

                fast = fast->next->next;
                //cout<<slow->val<<endl;
                temp = slow;
                slow=slow->next;
            }
        //cout<<slow->val<<endl;
        
        
            temp->next = slow->next;
            delete slow;
            return head;
    }
};

// Time complexity : O(n)
// Space complexity : O(1)
// Logic explained :
// We use the two pointer approach to find the middle element of the linked list.
// We use two pointers fast and slow. Fast pointer moves two steps at a time and slow pointer moves one step at a time.
// When the fast pointer reaches the end of the linked list, the slow pointer will be at the middle of the linked list.
// We delete the middle element by changing the next pointer of the previous element of the middle element to the next element of the middle element.
// We delete the middle element by using the delete operator.
// We return the head of the linked list after deleting the middle element.