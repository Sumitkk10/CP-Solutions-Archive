#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long long long int
#define ld long double
using namespace std;
const long long int N = 1e3 + 5;
const long long int MOD = 1e9 + 7;
bool vis[N][N];

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int> > white, black;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if((i + j) % 2 == 0) black.push_back({i, j});
            else white.push_back({i, j});
        }
    }

    // (i + j) % 2 --> prefer 2

    // (i + j) % 2  == 0 --> prefer 1

    int i = 0, j = 0;

    for(int k = 0; k < (n * n); ++k){

        int col;
        cin >> col;
        
        if(col == 2){
            if(i < white.size()){
                cout << 1 << ' ' << white[i].first << ' ' << white[i].second << endl;
                ++i;
            }
            else{
                cout << 3 << ' ' << black[j].first << ' ' << black[j].second << endl;
                ++j;
            }
        }

        else if(col == 1){
            if(j < black.size()){
                cout << 2 << ' ' << black[j].first << ' ' << black[j].second << endl;
                ++j;
            }
            else{
                cout << 3 << ' ' << white[i].first << ' ' << white[i].second << endl;
                ++i;
            }
        }

        else{
            if(i < white.size()){
                cout << 1 << ' ' << white[i].first << ' ' << white[i].second << endl;
                ++i;
            }
            else{
                cout << 2 << ' ' << black[j].first << ' ' << black[j].second << endl;
                ++j;
            }
        }
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
