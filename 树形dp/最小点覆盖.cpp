#include <bits/stdc++.h>
 
typedef long long LL;

using namespace std;
 
void solve() {
    int n;
    while(cin >> n)
    {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for(int i = 0; i < n; i ++)
        {
            int a, m, b;
            scanf("%d:(%d)", &a, &m);
            while(m --)
                cin >> b, g[a].push_back(b), d[b] ++;
        }
        vector<vector<int>> f(n, vector<int>(2, 0));
        auto dfs = [&](auto dfs, int u) -> void{
            f[u][1] = 1;
            for(auto& i : g[u])
            {
                dfs(dfs, i);
                f[u][0] += f[i][1];
                f[u][1] += min(f[i][0], f[i][1]);
            }
        };
        int idx = find(d.begin(), d.end(), 0) - d.begin();
        dfs(dfs, idx);
        cout << min(f[idx][0], f[idx][1]) << "\n";
    }
}

 
int main() {
    // std::ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int T = 1;
    // cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}