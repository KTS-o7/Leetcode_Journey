class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        std::ios::sync_with_stdio(false);
        int size = deck.size();
        sort(deck.begin(),deck.end());
        queue<int>q;
        for(int i = 0;i<size;i++)
            q.push(i);
            
        vector<int>ans(size);
        int i = 0;
        while(!q.empty())
        {
            ans[q.front()] = deck[i++];
            q.pop();
            if(!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
        
    }
};

// Time complexity: O(nlogn)
// Space complexity: O(n)

// Logic explained :
// 1. Sort the deck array.
// 2. Create a queue of size n and push all the indices of the deck array.
// 3. Create a vector of size n to store the answer.
// 4. Iterate over the queue and pop the front element and assign the deck[i] to the ans[q.front()] and increment i.
// 5. If the queue is not empty, push the front element to the back of the queue and pop the front element.
// 6. Return the answer vector.

/* This method is designed to simulate the process of revealing cards in a deck in a specific order, ensuring that the deck is sorted in increasing order. Let's break down the logic behind this code step by step:

1. **Initialization and Sorting**:
   - The method begins by disabling synchronization between the C++ standard streams and the C standard streams to improve performance (`std::ios::sync_with_stdio(false);`).
   - It then sorts the input vector `deck` in ascending order using `std::sort`. This is the first step in ensuring that the deck is sorted in increasing order.

2. **Queue Initialization**:
   - A queue `q` is initialized to hold integers. The size of this queue is equal to the size of the input deck.
   - The queue is filled with integers from 0 to `size-1` using a for loop. These integers represent the positions in the final sorted deck where each card will be placed.

3. **Processing the Queue**:
   - A new vector `ans` is initialized with the same size as the input deck. This vector will hold the final sorted deck.
   - The method then enters a while loop that continues until the queue `q` is empty.
   - Inside the loop, the card at the front of the queue is assigned the next card from the sorted deck. This is done by setting `ans[q.front()] = deck[i++];`. The queue's front element represents the position in the final sorted deck, and `deck[i++]` gives the next card from the sorted deck.
   - After assigning the card, the front element of the queue is removed using `q.pop();`.
   - If the queue is not empty after popping, the front element of the queue is pushed back onto the queue. This simulates the process of revealing the next card in the deck.

4. **Returning the Sorted Deck**:
   - Once the queue is empty, the method returns the `ans` vector, which now contains the deck sorted in increasing order, with each card revealed in the correct position according to the rules of the puzzle.

### Intuitive Explanation:

Imagine you have a deck of cards that you want to sort in increasing order. You start by sorting the deck. Then, you decide to reveal the cards one by one, but not in the order they are sorted. Instead, you reveal the cards in a specific order that ensures the deck is sorted in increasing order.

You use a queue to keep track of the order in which you will reveal the cards. Initially, the queue contains the positions of the cards in the final sorted deck. As you reveal each card, you remove its position from the queue and place the card in the deck at that position. If there are still cards left to reveal, you push the next position back onto the queue, simulating the process of revealing the next card.

This process ensures that the deck is sorted in increasing order, with each card revealed in the correct position according to the rules of the puzzle.*/