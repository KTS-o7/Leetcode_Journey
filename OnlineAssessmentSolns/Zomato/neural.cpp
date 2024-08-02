#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long findGen(vector<int>& layers) {
        int val = layers[0];
        for(auto i: layers){
            val = max(val, i);
        }

        long odd = 0;
        long even = 0;
        for(auto i: layers){
            int diff = val - i;

            int r = diff%2;
            int q = diff/2;

            if(r==1){
                odd++;
            }
            even += q;
        }
        odd = 2*odd -1;
        even = 2*even;
        while(even-odd>=5){
            even -= 2;
            odd += 4;
        }

        int ans1 = max(even, odd);
        val++;
        for(auto i: layers){
            val = max(val, i);
        }

        odd = 0;
        even = 0;
        for(auto i: layers){
            int diff = val - i;

            int r = diff%2;
            int q = diff/2;

            if(r==1){
                odd++;
            }
            even += q;
        }
        odd = 2*odd -1;
        even = 2*even;
        while(even-odd>=5){
            even -= 2;
            odd += 4;
        }

        int ans2 = max(even, odd);
        return min(ans1, ans2);
    }
};

int main() {
	Solution s;
	vector<int> layers = {1,1,2,4};

	cout << s.findGen(layers) << endl;
}
