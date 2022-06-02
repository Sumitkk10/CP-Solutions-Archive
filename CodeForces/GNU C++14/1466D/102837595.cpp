#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    ll weights[n + 1], indegree[n + 1], sum = 0;
    for(int i = 1; i <= n; ++i){
        cin >> weights[i];
        sum += weights[i];
        indegree[i] = 0;
    }
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        indegree[u]++;
        indegree[v]++;
    }
    priority_queue<long long int> q;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= indegree[i] - 1; ++j)
            q.push(weights[i]);
    cout << sum << ' ';
    for(int i = 2; i <= n - 1; ++i){
        sum += q.top();
        q.pop();
        cout << sum << ' ';
    }
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();    
    return 0;
}
