class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(),tokens.end());
        int score = 0,l = 0,r=tokens.size()-1;
        while(l<=r){
            if(power>=tokens[l])
            {
                power-=tokens[l++];
                ++score;
                
            }
            else if(score>0 && l<r)
            {
                power+=tokens[r--];
                --score;
            }
            else
                return score;
            
        }
        return score;

        
    }
};

// Timecomplexity: O(nlogn)
// Spacecomplexity: O(1)
// code explained :
// 1. Sort the tokens array.
// 2. Initialize the score and left and right pointer.
// 3. If power is greater than or equal to the left pointer token, then we can increase the score and decrease the power.
// 4. If power is less than the left pointer token and score is greater than 0, then we can increase the power and decrease the score.
// 5. If power is less than the left pointer token or score is less than 0, then we can return the score.
// Greedy approach is used here.
// We try to grab as many lower tokens as possible and then trade them for one higher token.
// We can do this as long as we have enough power to buy the lower token and we have at least one score to trade for power.