#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long long long int
#define ld long double
using namespace std;
const long long int N = 1e6 + 5;
const long long int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    double a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    if(n == 2){
        cout << "1\n";
        return;
    }
    int ans = 1;
    stack<int> cur;
    cur.push(0);
    cur.push(1);
    for(int i = 2; i < n; ++i){
        while(cur.size() >= 2){
            int pre = cur.top();
            cur.pop();
            int pre1 = cur.top();
            cur.push(pre);
            double slope = (double) ((a[pre] - a[pre1]) / (pre - pre1));
            double cur_slope = (double) ((a[i] - a[pre]) / (i - pre));
            if(cur_slope >= slope)
                cur.pop();
            else
                break;
        }
        ans = max(ans, i - cur.top());
        cur.push(i);
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
