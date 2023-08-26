// DFS 
int n; cin >> n;
vector<vector<array<int, 2>>> g(n);
for(int i = 1, a, b, c; i < n; i ++)
cin >> a >> b >> c, g[--a].push_back({--b, c}), g[b].push_back({a, c});
int r = -1, maxv = 0;
auto dfs = [&](auto _, int u, int pre, int dist) -> void{
	if(dist > maxv) r = u, maxv = dist;
	for(auto& [i, w] : g[u])
		if(i ^ pre)
			_(_, i, u, dist + w);
};
dfs(dfs, 0, -1, 0);
dfs(dfs, r, -1, 0);

// DP 两个数组记录
int n; cin >> n;
vector<vector<array<int, 2>>> g(n + 1);
vector<int> d1(n + 1), d2(n + 1);
for(int i = 1, a, b, c; i < n; i ++)
cin >> a >> b >> c, g[a].push_back({b, c}), g[b].push_back({a, c});
int d = 0;
auto dfs = [&](auto _, int u, int pre) -> void{
	for(auto& [i, w] : g[u])
		if(i ^ pre)
		{
			_(_, i, u);
			int t = d1[i] + w;
			if(t > d1[u])
				d2[u] = d1[u], d1[u] = t;
			else if(t > d2[u])
				d2[u] = t;
		}
	d = max(d, d1[u] + d2[u]);
};
dfs(dfs, 1, -1);

// DP 一个数组记录
auto dp = [&](auto _, int u, int fa) -> void{
	for(auto& i : g[u])
		if(i != fa)
		{
			_(_, i, u);
			// w -> 边权
			d = max(d, d1[u] + d1[i] + w);
			d1[u] = max(d1[u], d1[i] + w);
		}
};
dp(dp, 0, -1);
