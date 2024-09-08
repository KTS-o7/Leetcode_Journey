#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000;
long long S[MAX_N + 1];
long long F[MAX_N + 1];
long long prefixSum[MAX_N + 1];

void precompute() {
    for (int i = 1; i <= MAX_N; ++i) {
        for (int j = i; j <= MAX_N; j += i) {
            S[j] += i;
        }
    }
    
    for (int x = 1; x <= MAX_N; ++x) {
        for (int j = x; j <= MAX_N; j += x) {
            F[j] += S[x];
        }
    }
    
    for (int i = 1; i <= MAX_N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + F[i];
    }
}

long long solve(int L, int R) {
    return prefixSum[R] - prefixSum[L - 1];
}

int main() {
    precompute();

    int Q;
    cin >> Q;
    
    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << solve(L, R) << endl;
    }

    return 0;
}
