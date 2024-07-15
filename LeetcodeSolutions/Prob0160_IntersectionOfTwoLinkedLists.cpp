/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int s1 = 0, s2 = 0;
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        ListNode* last1 = nullptr;
        ListNode* last2 = nullptr;
        while(l1 != nullptr){
            last1 = l1;
            s1++;
            l1=l1->next;
        }
        while(l2 !=nullptr){
            last2 = l2;
            s2++;
            l2 = l2->next;
        }
        if(last1 != last2)
            return nullptr;
        int size = s1>s2?s1-s2:s2-s1;

        l1 = headA;
        l2 = headB;
        if(s1>s2){
            while(size--){
                l1=l1->next;
            }
        }
        else{
            while(size--){
                l2=l2->next;
            }
        }
        while(l1!=l2)
        {
            l1=l1->next;
            l2=l2->next;
        }
        return l1;
        
    }
};

// Time complexity: O(M+N)
// Space complexity: O(1)

// Explanation:
/*
1. Calculate the lengths of the two linked lists and store the last nodes of each list.
2. If the last nodes are not the same, the lists do not intersect, so return null.
3. Calculate the difference in lengths between the two lists.
4. Move the pointer of the longer list forward by the difference in lengths.
5. Move both pointers forward until they meet at the intersection point.
6. Return the intersection point.
*/