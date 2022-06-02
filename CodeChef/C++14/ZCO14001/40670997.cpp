#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int commands;
    cin >> commands;
    int j = 0;
    bool ct = 0;
    while(commands != 0){
        if(commands == 1)
            j = max(0, j - 1);
        if(commands == 2)
            j = min(n - 1, j + 1);
        if(commands == 3 and ct == 0){
            if(a[j] > 0){
                ct = 1;
                a[j]--;
            }
        }
        if(commands == 4 and ct == 1){
            if(a[j] < k){
                ct = 0;
                a[j]++;
            }
        }
        if(commands == 0)
            break;
        cin >> commands;
    }
    for(int i = 0; i < n; ++i)
        cout << a[i] << ' ';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
