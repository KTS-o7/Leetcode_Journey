class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        auto comparePair = [](const pair<int,int>& a,const pair<int,int>& b)
        {
            return a.first<b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comparePair)> maxHeap;

        for(int i = 0;i<score.size();i++)
            maxHeap.push(make_pair(score[i],i));

        vector<string>answer(score.size());
        pair<int,int> holder;
        int place = 0;
        vector<string>places = {"Gold Medal","Silver Medal","Bronze Medal"};
        while(!maxHeap.empty() && place <3)
        {
            holder = maxHeap.top();
            maxHeap.pop();
            answer[holder.second] = places[place];
            place++;
        }
        while(!maxHeap.empty())
        {

            holder = maxHeap.top();
            maxHeap.pop();
            answer[holder.second] = to_string(++place);
        }
        return answer;


    }
};

// Time complexity: O(nlogn)
// Space complexity: O(n)

// Logic explained:
// 1. Create a max heap with the scores and their index.
// 2. Pop the top 3 elements and assign them the medals.
// 3. For the rest of the elements, assign them their place.
// 4. Return the answer.