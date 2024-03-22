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
    bool isPalindrome(ListNode* head) {
        ListNode* first = head;
        vector<int>pali;
        while(first!=NULL)
            {
                pali.push_back(first->val);
                first=first->next;
            }
        
        int l =0 , r = pali.size()-1;
        while(l<r)
        {
            if(pali[l]!=pali[r])
                return false;
            l++;
            r--;
        }
        return true;
            


    }
};