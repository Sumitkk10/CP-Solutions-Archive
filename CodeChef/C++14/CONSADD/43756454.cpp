#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1005;
int n, m, x, a[N][N], b[N][N];

bool ok(){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(a[i][j] != b[i][j])
            return false;
    return true;
}

void solve(){
    cin >> n >> m >> x;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> b[i][j];
    if(ok()){
        cout << "Yes\n";
        return;
    }
    if(x > n){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= (m - x); ++j){
                if(a[i][j] == b[i][j]) 
                    continue;
                int diff = b[i][j] - a[i][j];
                a[i][j] += diff;
                int temp = x - 1, cur = j + 1;
                while(temp--){
                    a[i][cur] += diff;
                    ++cur;
                }
            }
        }
        if(ok()){
            cout << "Yes\n";
            return;
        }
        else{
            cout << "No\n";
            return;
        }
    }
    if(x > m){
        for(int j = 0; j < m; ++j){
            for(int i = 0; i <= (n - x); ++i){
                if(a[i][j] == b[i][j]) 
                    continue;
                int diff = b[i][j] - a[i][j];
                a[i][j] += diff;
                int temp = x - 1, cur = i + 1;
                while(temp--){
                    a[cur][j] += diff;
                    ++cur;
                }
            }
        }
        if(ok()){
            cout << "Yes\n";
            return;
        }
        else{
            cout << "No\n";
            return;
        }
    }
    else{
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= (m - x); ++j){
                if(a[i][j] == b[i][j])
                    continue;
                int diff = b[i][j] - a[i][j];
                a[i][j] += diff;
                int temp = x - 1, cur = j + 1;
                while(temp--){
                    a[i][cur] += diff;
                    ++cur;
                }
            }
        }
        for(int j = 0; j < m; ++j){
            for(int i = 0; i <= (n - x); ++i){
                if(a[i][j] == b[i][j]) 
                    continue;
                int diff = b[i][j] - a[i][j];
                a[i][j] += diff;
                int temp = x - 1, cur = i + 1;
                while(temp--){
                    a[cur][j] += diff;
                    ++cur;
                }
            }
        }
        if(ok()){
            cout << "Yes\n";
            return;
        }
        else{
            cout << "No\n";
            return;
        }
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
	return 0;
}
