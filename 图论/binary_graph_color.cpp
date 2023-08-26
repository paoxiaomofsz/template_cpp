#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int a, b; cin >> a >> b; ) g[a].push_back(b), g[b].push_back(a);
    vector<int> color(n + 1, 0);
    auto dfs = [&](auto dfs, int u, int c) -> bool{
        color[u] = c;
        for(auto& ite : g[u])
        {
            if(!color[ite]) if(!dfs(dfs, ite, 3 - c)) return false;
            if(color[ite] == c)
                return false;
        }
        return true;
    };
    for(int i = 1; i <= n; i ++)
        if(!color[i])
        {
            if(!dfs(dfs, i, 1))
            {
                cout << "No\n";
                return 0;
            }
        }
    cout << "Yes\n";
}