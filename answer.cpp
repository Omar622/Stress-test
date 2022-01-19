#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int arr[n];
        for(auto& x: arr) cin >> x;

        int q;
        cin >> q;
        while(q--){
            int l, r;
            cin >> l >> r;
            long long sum = 0;
            for(int i = l; i <= r; ++i){
                sum += arr[i];
            }
            cout << sum << "\n";
        }
    }
}
