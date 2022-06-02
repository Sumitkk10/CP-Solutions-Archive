#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1000 + 5;
const int MOD = 1e9 + 7;
int pre_sum[N][N];

int main() {
    fast;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int x;
            cin >> x;
            pre_sum[i][j] = x + pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pre_sum[x2][y2] - pre_sum[x2][y1 - 1] - pre_sum[x1 - 1][y2] + pre_sum[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}
/*
4 4
3 4 15 23
14 20 12 9
3 8 12 15
12 20 7 5
2
2 2 3 4
4 2 4 2
 */