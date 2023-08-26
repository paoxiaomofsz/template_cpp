auto dijkstra = [&](int root) -> int{
        vector<int> d(n + 1, 1e9 + 10);
        vector<bool> st(n + 1, false);
        d[1] = 0;
        for(int i = 1; i < n; i ++)
        {
            int t = -1;
            for(int j = 1; j <= n; j ++)
                if(!st[j] && (t == -1 || d[j] < d[t]))
                    t = j;
            for(int j = 1; j <= n; j ++)
                d[j] = min(d[j], d[t] + g[t][j]);
            st[t] = true;
        }
        return d[n] == 1e9 + 10 ? -1 : d[n];
    };