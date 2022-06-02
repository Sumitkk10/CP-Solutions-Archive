#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;
int n, m, pos[N];
string a, b;
map<int, vector<int> > mp;

bool possible(int mid){
    int last = mp[b[0] - 'a'][0];
    for(int i = 1; i < m; ++i){
        if(i == m - 1){
            if(pos[i] - last >= mid)
                return true;
            continue;
        }
        int cur = last + mid;
        if(pos[i] >= cur)
            return true;
        int low = 0, high = mp[b[i] - 'a'].size() - 1, ok = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mp[b[i] - 'a'][mid] > last){
                ok = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        last = mp[b[i] - 'a'][ok];
    }
    return false;
}

int main() {
    fast;
    cin >> n >> m;
    cin >> a >> b;
    for(int i = 0; i < a.size(); ++i)
        mp[a[i] - 'a'].push_back(i + 1);
    pos[m - 1] = mp[b[m - 1] - 'a'][mp[b[m - 1] - 'a'].size() - 1];
    int last = pos[m - 1];
    for(int i = b.size() - 2; i >= 0; --i){
        int low = 0, high = mp[b[i] - 'a'].size() - 1, ok = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mp[b[i] - 'a'][mid] < last){
                ok = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        pos[i] = mp[b[i] - 'a'][ok];
        last = pos[i];
    }
    int ans = 0, low = 0, high = n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(possible(mid)){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << "\n";
	return 0;
}
