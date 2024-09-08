#include <bits/stdc++.h>
using namespace std;

int solution(int N, string P) {
    int s_count = 0;
    int w_to_s = 0;
    
    for (int i = 0; i < N; i++) {
        if (P[i] == 'S') {
            s_count++;
        } else {
            w_to_s = min(w_to_s + 1, s_count);
        }
    }
    
    return w_to_s;
}

int main() {
    int N;
    string P;
    
    cin >> N;
    cin >> P;

    int result = solution(N, P);
    cout << result << endl;

    return 0;
}
