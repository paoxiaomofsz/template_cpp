struct RMQ{ // 超时的话记得改写为数组
    int n, m;
    vector<vector<int>> f, g;
    vector<int> q;
    RMQ(int N, int M) : n(N), m(M), f(n + 1, vector<int>(m + 1)), g(n + 1, vector<int>(m + 1)), q(n + 1){}
    
	void init(){
		for(int j = 0; j < m; j ++)
			for(int i = 1; i + (1 << j) <= n + 1; i ++)
			{
				if(!j) f[i][j] = q[i];
				else
				{
					f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
					g[i][j] = min(g[i][j - 1], g[i + (1 << j - 1)][j - 1]);
				}
					
			}
	}
	int ask_max(int l, int r){
		int k = log2(r - l + 1);
		return max(f[l][k], f[r - (1 << k) + 1][k]);
	}
	int ask_min(int l, int r){
		int k = log2(r - l + 1);
		return min(g[l][k], g[r - (1 << k) + 1][k]);
	}
};