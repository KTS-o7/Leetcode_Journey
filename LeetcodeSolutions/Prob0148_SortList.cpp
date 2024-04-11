/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val; // Value of the node
 *     ListNode *next; // Pointer to the next node in the list
 *     ListNode() : val(0), next(nullptr) {} // Default constructor
 *     ListNode(int x) : val(x), next(nullptr) {} // Constructor with value
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with value and next node
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        std::ios::sync_with_stdio(false); // Speeds up I/O operations by unsynchronizing C and C++ standard streams
        cin.tie(nullptr); // Unties cin from cout for faster I/O operations

        if(head == nullptr) // If the list is empty, return null
            return head;

        vector<int>v; // Declare a vector to store the values of the list
        int i; // Declare a variable for loop control
        ListNode* temp = head; // Declare a temporary pointer to traverse the list

        while(temp!=nullptr){ // While we haven't reached the end of the list
            v.push_back(temp->val); // Add the value of the current node to the vector
            temp=temp->next; // Move to the next node
        }

        sort(v.begin(),v.end()); // Sort the vector

        temp = head; // Reset the temporary pointer to the head of the list

        for(i=0;i<v.size();i++){ // For each element in the vector
            temp->val = v[i]; // Assign the sorted values back to the list
            temp=temp->next; // Move to the next node
        }

        return head; // Return the head of the sorted list
    }
};

// time complexity: O(nlogn)
// space complexity: O(n)

// Code explained:
// Problem Statement: The problem is to sort a linked list in ascending order using O(nlogn) time complexity

// Algorithm Overview: The algorithm uses a vector to store the values of the list, sorts the vector, and then assigns the sorted values back to the list.

// Detailed Steps:
// std::ios::sync_with_stdio(false); and cin.tie(nullptr);: These two lines are used to speed up input/output operations in C++.
// if(head == nullptr) return head;: If the list is empty, return null.
// vector<int>v;: Declare a vector to store the values of the list.
// int i;: Declare a variable for loop control.
// ListNode* temp = head;: Declare a temporary pointer to traverse the list.
// while(temp!=nullptr){...}: While we haven't reached the end of the list, add the value of the current node to the vector and move to the next node.
// sort(v.begin(),v.end());: Sort the vector.
// temp = head;: Reset the temporary pointer to the head of the list.
// for(i=0;i<v.size();i++){...}: For each element in the vector, assign the sorted values back to the list and move to the next node.
// return head;: Return the head of the sorted list.


