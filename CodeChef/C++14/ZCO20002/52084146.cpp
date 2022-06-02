#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 100000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 105

ll dp[105][105][205][3] = {0};

ll add(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}

int main() {
    
    fast;

    tc{
        ll n,m,block;
        cin in n in m in block;

        vi a(n+5);
        vi b(m+5);

        fo(i,1,n) cin in a[i];
        fo(i,1,m) cin in b[i];

        // dp[i][j][k][1] = number of ways to interleave first i elements from first array and first j elements from second array with exactly k blocks and the last element is from first array

        // dp[i][j][k][2] = number of ways to interleave first i elements from first array and first j elements from second array with exactly k blocks and the last element is from second array

        // base case :

        memset(dp, 0, sizeof dp);

        dp[1][0][1][1] = 1;
        dp[0][1][1][2] = 1;
        int cur = 1;
        for(int j = 2; j <= m; ++j){
            if(b[j] == b[j - 1])
                dp[0][j][cur][2] = 1;
            else{
                ++cur;
                dp[0][j][cur][2] = 1;
            }
        }
        cur = 1;
        for(int i = 2; i <= n; ++i){
            if(a[i] == a[i - 1])
                dp[i][0][cur][1] = 1;
            else{
                ++cur;
                dp[i][0][cur][1] = 1;
            }
        }

        // recursive relation :

        fo(i,1,n){
            fo(j,1,m){
                fo(k,1,block){
                    
                    // dp[i][j][k][1] : interleaving ith element from first array

                    if(a[i] == a[i-1]) dp[i][j][k][1] = dp[i-1][j][k][1];
                    else dp[i][j][k][1] = dp[i-1][j][k-1][1];

                    if(a[i] == b[j]) dp[i][j][k][1] = add(dp[i][j][k][1], dp[i-1][j][k][2]);
                    else dp[i][j][k][1] = add(dp[i][j][k][1], dp[i-1][j][k-1][2]);

                    // dp[i][j][k][2] : interleaving jth element from second array

                    if(b[j] == a[i]) dp[i][j][k][2] = dp[i][j-1][k][1];
                    else dp[i][j][k][2] = dp[i][j-1][k-1][1];

                    if(b[j] == b[j-1]) dp[i][j][k][2] = add(dp[i][j][k][2], dp[i][j-1][k][2]);
                    else dp[i][j][k][2] = add(dp[i][j][k][2], dp[i][j-1][k-1][2]);
                }
            }
        }

        // optimal solution :

        cout out add(dp[n][m][block][1], dp[n][m][block][2]) nextline;
    }

    return 0;
}