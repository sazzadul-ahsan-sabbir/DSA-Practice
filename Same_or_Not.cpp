#include <bits/stdc++.h>
using namespace std;

bool compareArray(int stack_arr[], int N, int queue_arr[], int M) {
    int i = N - 1; 
    int j = 0;    

    while (i >= 0 && j < M) {
        if (stack_arr[i] != queue_arr[j]) {
            return false; 
        }
        i--;
        j++;
    }

    if (i >= 0 || j < M) return false;

    return true; 
}

int main() {
    int N, M;
    cin >> N >> M;

    int stack_arr[N];
    int queue_arr[M];

    for (int i = 0; i < N; i++) cin >> stack_arr[i];
    for (int i = 0; i < M; i++) cin >> queue_arr[i];

    bool sameOrder = compareArray(stack_arr, N, queue_arr, M);
    if (sameOrder) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
