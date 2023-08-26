auto prime = [&]() -> void{
        int res = 0;
        bool flg = true;
        vector<int> d(n + 1, 1e9 + 10);
        vector<bool> st(n + 1, false);
        d[1] = 0;
        for(int i = 0; i < n; i ++)
        {
            int t = -1;
            for(int j = 1; j <= n; j ++)
                if(!st[j] && (t == -1 or d[j] < d[t]))
                    t = j;
            if(i && d[t] == 1e9 + 10)
            {
                flg = false;
                break;
            }
            if(i)
                res += d[t];
            for(int j = 1; j <= n; j ++)
                d[j] = min(d[j], g[t][j]);
            st[t] = true;
        }
        if(flg)
            cout << res << '\n';
        else
            cout << "impossible\n";
    };
    