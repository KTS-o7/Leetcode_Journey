#include <set>
#include <cmath>
#include <bits/stdc++.h>

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    if(intervals.empty()) return 0;

    // Sort the intervals by start time
   sort(intervals.begin(), intervals.end());

    // Use a priority queue to track the end time of meetings
    priority_queue<int, vector<int>, greater<int>> pq;

    int rooms = 0;
    for(auto& interval : intervals) {
        pq.push(interval[1]);
        if(interval[0] < pq.top()) rooms++;
        else pq.pop();
    }

    return rooms;
}

/* Question link :
https://leetcode.com/problems/meeting-rooms-ii/description/

Solution link :
https://github.com/Seanforfun/Algorithm-and-Leetcode/blob/master/leetcode/253.%20Meeting%20Rooms%20II.md
The solution is in Java, but the logic is the same.


*/

// Logic Explained :
// 1. We need to find the minimum number of meeting rooms required to hold all the meetings.
// 2. We can solve this problem by using a priority queue.
// 3. We will sort the meetings based on their start time.
// 4. We will create a priority queue to store the end time of the meetings.
// 5. This means that every time the front of Queue will be the meeting that will end first.
// 6. We will check if the start time of the current meeting is greater than the end time of the meeting at the front of the queue.
// 7. If it is, then we will pop the meeting from the front of the queue.
// 8. If it is not, then we will increment the number of rooms required.

// Time Complexity : O(nlogn)
// Space Complexity : O(n)

// The intuition behind this method :
/*
if cur start time < pq.peek() => means current start time is before first ending time, which means we must have a new room.
if cur start time >= pq.peek() => means we can use this room for the meeting, we poll out the the original period and add current period to the pq(Means we update the room with the new meeting).
*/

