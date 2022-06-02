#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, x;
    cin >> n >> x;
    int odd = 0, even = 0;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        odd += (a % 2);
        even += (a % 2 == 0);
    }
    if(odd == 0){
        cout << "No\n";
        return;
    }
    int left = x - even;
    if(left <= 0){
        cout << "Yes\n";
        return;
    }
    if(odd >= left){
        if(odd == left){
            cout << (left % 2 ? "Yes\n" : "No\n");
            return;
        }
        if(left == x){
             cout << (left % 2 ? "Yes\n" : "No\n");
               return;
        }
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
