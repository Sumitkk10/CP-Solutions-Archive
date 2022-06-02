#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int a[3][2];
    for(int i = 0; i < 3; ++i)
        cin >> a[i][0] >> a[i][1];
    if(a[0][0] == a[1][0]){
        if(a[2][0] == a[0][0] and a[2][1] > a[0][1] and a[2][1] < a[1][1])
            cout << abs(a[0][0] - a[1][0]) + abs(a[0][1] - a[1][1]) + 2 << '\n';
        else if(a[2][0] == a[0][0] and a[2][1] < a[0][1] and a[2][1] > a[1][1])
            cout << abs(a[0][0] - a[1][0]) + abs(a[0][1] - a[1][1]) + 2 << '\n';
        else
            cout << abs(a[0][0] - a[1][0]) + abs(a[0][1] - a[1][1]) << '\n';
        return;
    }
    if(a[1][1] == a[0][1]){
        if(a[2][1] == a[0][1] and a[2][0] > a[0][0] and a[2][0] < a[1][0])
            cout << abs(a[0][0] - a[1][0]) + abs(a[0][1] - a[1][1]) + 2 << '\n';
        else if(a[2][1] == a[0][1] and a[2][0] < a[0][0] and a[2][0] > a[1][0])
            cout << abs(a[0][0] - a[1][0]) + abs(a[0][1] - a[1][1]) + 2 << '\n';
        else
            cout << abs(a[0][0] - a[1][0]) + abs(a[0][1] - a[1][1]) << '\n';
        return;
    }
    cout << abs(a[0][0] - a[1][0]) + abs(a[0][1] - a[1][1]) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
