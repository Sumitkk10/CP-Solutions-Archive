#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 9, N = 101;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), lis;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    lis.push_back(a[0]);
    for(int i = 1; i < n; ++i){
        if(a[i] >= lis.back())
            lis.push_back(a[i]);
        else{
            int low = 0, high = lis.size() - 1, x = -1;
            while(low <= high){
                int mid = (low+high)/2;
                if(lis[mid] >= a[i]){
                    x = mid;
                    high = mid - 1;
                }
                else
                    low = mid+1;
            }
            if(x != -1)
                lis[x] = a[i];
        }
    }
    cout << n - lis.size();
    return 0;
}