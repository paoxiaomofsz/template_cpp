#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n1, n2, m; cin >> n1 >> n2 >> m;
    vector<vector<int>> g(n1 + 1);
    for(int a, b; cin >> a >> b; ) g[a].push_back(b);
    int res = 0;
    vector<bool> st(n2 + 1, false);
    vector<int> ma(n2 + 1, 0);
    auto find = [&](auto find, int u) -> bool{
        for(auto& ite : g[u])
            if(!st[ite])
            {
                st[ite] = true;
                if(!ma[ite] || find(find, ma[ite]))
                {
                    ma[ite] = u;
                    return true;
                }
            }
        return false;
    };
    for(int i = 1; i <= n1; i ++)
    {
        st = vector<bool>(n2 + 1, false);
        if(find(find, i))
            res ++ ;
    }
    cout << res << "\n";
    return 0;
}