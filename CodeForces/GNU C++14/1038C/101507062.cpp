#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
    fast;
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    sort(a, a + n, greater<int>());
    sort(b, b + n, greater<int>());
    int i = 0, j = 0;
    long long int score_a = 0, score_b = 0, chance = 0;
    while(i < n or j < n){
        if(chance % 2 == 0){
            if(j >= n){
                score_a += a[i];
                ++i;
            }
            else if(i >= n)
                ++j;
            else{
                if(a[i] >= b[j]){
                    score_a += a[i];
                    ++i;
                }
                else
                    ++j;
            }
            chance = 1;
        }
        else{
            if(i >= n){
                score_b += b[j];
                ++j;
            }
            else if(j >= n)
                ++i;
            else{
                if(a[i] <= b[j]){
                    score_b += b[j];
                    ++j;
                }
                else
                    ++i;
            }
            chance = 0;
        }
    }
    cout << score_a - score_b << '\n';
    return 0;
}
