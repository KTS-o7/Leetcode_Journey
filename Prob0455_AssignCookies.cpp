class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int cookie=0,child=0;

        while(cookie<s.size() && child<g.size())
        {
            if(s[cookie]>=g[child])
            {
                cookie++;
                child++;
            }
            else
                cookie++;

        }
        return child;


        
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
/*
code Explanation: The algorithm works by greedily assigning cookies to children, starting with the smallest greed factor and the smallest cookie size. Sorting both vectors allows for an efficient and straightforward comparison. The time complexity of this algorithm is O(n log n), where n is the maximum of the sizes of vectors g and s.

Sorting:

sort(g.begin(), g.end());: Sort the vector g representing the greed factors of children in ascending order.
sort(s.begin(), s.end());: Sort the vector s representing the sizes of cookies in ascending order. Sorting helps in efficiently matching cookies with children.
Iterating Through Cookies and Children:

Initialize two pointers, cookie and child, to keep track of the current positions in the sorted vectors.
while (cookie < s.size() && child < g.size()) { ... }: Continue the loop until either there are no more cookies (cookie >= s.size()) or no more children (child >= g.size()).
Checking Cookie Size:

if (s[cookie] >= g[child]) { ... }: If the current cookie size is greater than or equal to the greed factor of the current child, it means the child can be content with that cookie. Increment both cookie and child.
else { ... }: If the cookie is too small for the current child, move to the next cookie (cookie++).
Returning Result:

return child;: After the loop, the value of child represents the maximum number of children that can be content with the available cookies.
*/