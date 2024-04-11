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
    ListNode* rotateRight(ListNode* head, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(head == NULL || head->next==NULL)
            return head;
        int size = 1;
        ListNode* cnt = head;
        while(cnt->next != NULL)
            {
                size++;
                cnt=cnt->next;
            }
        
        //cout<<size<<endl;
        if(size==k || k ==0)
            return head;
        cnt->next = head;
        cnt = head;
        if(k>size)
            k = k%size;
        ListNode* prev = nullptr;
        for(int i = 0;i<size-k;i++)
        {
            prev = cnt;
            cnt=cnt->next;
        }
        prev->next = nullptr;
        return cnt;
        //return nullptr;
        
    }
};

// Time complexity : O(n)
// Space complexity : O(1)
// Logic explained :
// 1. Find the size of the linked list.
// 2. If the size of the linked list is equal to k or k is 0, return the head.
// 3. If k is greater than the size of the linked list, then k = k%size.
// 4. Make the linked list circular.
// 5. Traverse the linked list to the size-kth node.
// 6. Make the next of the size-kth node as NULL.
// 7. Return the kth node.