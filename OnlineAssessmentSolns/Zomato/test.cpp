#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long findGen(vector<int>& layers) {
        auto calculate = [](const vector<int>& layers, int maxLayer) -> int {
            long oddCount = 0;
            long evenCount = 0;
            for(auto layer: layers){
                int difference = maxLayer - layer;

                int remainder = difference % 2;
                int quotient = difference / 2;

                if(remainder == 1){
                    oddCount++;
                }
                evenCount += quotient;
            }
            oddCount = 2 * oddCount - 1;
            evenCount = 2 * evenCount;
            while(evenCount - oddCount >= 5){
                evenCount -= 2;
                oddCount += 4;
            }

            return max(evenCount, oddCount);
        };

        int maxLayer = *max_element(layers.begin(), layers.end());
        int ans1 = calculate(layers, maxLayer);

        maxLayer++;
        int ans2 = calculate(layers, maxLayer);

        return min(ans1, ans2);
    }
};

int main() {
    Solution s;
    vector<int> layers = {1, 1, 5};

    cout << s.findGen(layers) << endl;
}