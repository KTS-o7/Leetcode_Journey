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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int car=0;
        ListNode* root= new ListNode((l1->val+ l2->val)%10);
        ListNode* curr= root;
        car= (l1->val+ l2->val)/10;
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL && l2!=NULL){
            ListNode* temp= new ListNode((l1->val+ l2->val+car)%10);
            car= (car+l1->val+ l2->val)/10;
            l1= l1->next;
            l2= l2->next;
            curr->next= temp;
            curr= temp;
        }
        while(l1!=NULL){
            ListNode* temp= new ListNode((l1->val+car)%10);
            car= (car+l1->val)/10;
            l1= l1->next;
            curr->next= temp;
            curr= temp;
        }
        while(l2!=NULL){
            ListNode* temp= new ListNode((l2->val+car)%10);
            car= (car+l2->val)/10;
            l2= l2->next;
            curr->next= temp;
            curr= temp;
        }
        if(car==1){
            ListNode* newN= new ListNode(1);
            curr->next= newN;
        }
        return root;    
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
