class Solution {
public:
    // Function to find winners and losers in a set of matches
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // Disable synchronization with C standard streams for faster I/O
        std::ios::sync_with_stdio(false);
        // Untie cin for faster input
        cin.tie(nullptr);

        // Initialize an unordered map to count the number of matches each player wins
        unordered_map<int, int> count;

        // Iterate through each match
        for (int i = 0; i < matches.size(); i++) {
            // If the first player doesn't exist in the count map, initialize their count to 0
            if (count.find(matches[i][0]) == count.end())
                count[matches[i][0]] = 0;

            // Update the count for the second player (opponent) in the map
            if (count.find(matches[i][1]) != count.end())
                count[matches[i][1]]++;
            else
                count[matches[i][1]]++;
            
            // Debugging: Print match details and player counts
            // cout << matches[i][0] << " " << matches[i][1] << " " << count[matches[i][0]] << " " << count[matches[i][1]] << endl;
        }

        // Separate players into winners and losers based on their match counts
        vector<int> win, lose;
        for (auto it : count) {
            if (it.second == 0)
                win.push_back(it.first);
            if (it.second == 1)
                lose.push_back(it.first);
        }

        // Sort the winner and loser vectors
        sort(win.begin(), win.end());
        sort(lose.begin(), lose.end());

        // Store the results in a 2D vector and return
        vector<vector<int>> ans;
        ans.push_back(win);
        ans.push_back(lose);
        return ans;
    }
};

// Time complexity : O(nlogn)
// Space complexity : O(n)

/*Code explained :
 # Intuition

The problem involves counting the number of matches each player wins and then categorizing players into winners (players who won all matches) and losers (players who lost at least one match). The intuition is to use an unordered map to keep track of match counts for each player.

  

# Approach

1. Initialize an unordered map to store the count of matches won by each player.

2. Iterate through each match and update the match counts in the map.

3. Separate players into winners and losers based on their match counts.

4. Sort the winner and loser vectors.

5. Return a 2D vector containing the sorted winner and loser vectors.

  

# Complexity

- Time complexity: O(n * log(n)) for sorting, where n is the number of matches.

- Space complexity: O(n) for the unordered map.

  

# Algorithm

1. Initialize an unordered map `count` to store the count of matches won by each player.

2. Iterate through each match:

- If the first player doesn't exist in the count map, initialize their count to 0.

- Update the count for the second player (opponent) in the map.

3. Separate players into winners and losers based on their match counts:

- Winners have a count of 0.

- Losers have a count greater than 0.

4. Sort the winner and loser vectors.

5. Store the results in a 2D vector and return.

  

# Pseudocode

```plaintext

function findWinners(matches):

initialize unordered map count for match counting

  

for each match in matches:

if first player doesn't exist in count:

initialize their count to 0

update count for the second player (opponent) in the map

  

initialize vectors win and lose for winners and losers

  

for each player in count:

if player's count is 0:

add player to win vector

if player's count is greater than 0:

add player to lose vector

  

sort win and lose vectors

  

initialize a 2D vector ans containing win and lose vectors

  

return ans

```

  

# Test Cases and Dry Runs

## Test Case 1:

```plaintext

matches = [[1, 2], [2, 3], [3, 1]]

Result: [[], [1, 2, 3]]

```

### Dry Run:

- Player 1 won 1 match, Player 2 won 1 match, and Player 3 won 1 match.

- No player won all matches, so the winners vector is empty, and the losers vector contains all players.

  

## Test Case 2:

```plaintext

matches = [[1, 2], [2, 3], [3, 1], [4, 5]]

Result: [[], [1, 2, 3, 4, 5]]

```

### Dry Run:

- Player 1 won 1 match, Player 2 won 1 match, Player 3 won 1 match, and Players 4 and 5 have not won any matches.

- No player won all matches, so the winners vector is empty, and the losers vector contains all players.

  

## Test Case 3:

```plaintext

matches = [[1, 2], [2, 3], [3, 1], [2, 1], [3, 2], [1, 3]]

Result: [[1, 2, 3], []]

```

### Dry Run:

- Player 1 won 2 matches, Player 2 won 2 matches, and Player 3 won 2 matches.

- All players won all their matches, so the winners vector contains all players, and the losers vector is empty.
*/