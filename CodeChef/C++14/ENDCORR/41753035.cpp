#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int main(){
    fast;
    int n, m;
    cin >> n >> m;
    priority_queue<int> q;
    for(int i = 0; i < n + m; ++i){
        int x;
        cin >> x;
        if(x != -1){
            q.push(x);
            continue;
        }
        cout << q.top() << '\n';
        q.pop();
    }
    return 0;
}