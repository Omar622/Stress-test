     /* Do it! */
    /*  OMAR  */
#include <bits/stdc++.h>
using namespace std;
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define siz(x) ((int)((x).size()))
typedef long long ll;

void sss(){
    int n, q;
    cin >> n;
    ll arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        if(i) arr[i] += arr[i-1];
    }

    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << (l ? arr[r] - arr[l-1] : arr[r]) << "\n";
    }
}

int main(){
    FIO;

    int t = 1;
    cin >> t;
    while(t--){
        sss();
    }
    
    return 0;
}

/*

*/
