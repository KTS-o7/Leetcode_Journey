#include <bits/stdc++.h>
using namespace std;

long findMinGeneration(vector<int> layer) {
    int n = layer.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int max_layer = *max_element(layer.begin(), layer.end());

    for (int i = 0; i < n; ++i) {
        pq.push(max_layer - layer[i]);
    }

    long generations = 0;
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();

        if (top == 0) {
            continue;
        }

        if (generations % 2 == 0) { 
            top -= 2;
        } else { 
            top -= 1;
        }

        generations++;
        
        if (top > 0) {
            pq.push(top);
        }
    }

    return generations;
}

int main() {
    vector<int> layer = {1, 1, 2, 4};
    cout << findMinGeneration(layer) << endl; 
    return 0;
}
