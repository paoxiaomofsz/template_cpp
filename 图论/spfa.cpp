auto spfa = [&](int root) -> void{
        vector<bool> st(n + 1, false);
        vector<int> d(n + 1, 1e9 + 10);
        d[root] = 0;
        queue<int> q;
        q.push(root);
        while(q.size())
        {
            int t = q.front(); q.pop();
            st[t] = false;
            for(auto& [b, w] : g[t])
            {
                if(d[b] > d[t] + w)
                {
                    d[b] = d[t] + w;
                    if(!st[b])
                        st[b] = true, q.push(b);
                }
                    
            }
        }
        if(d[n] > 1e7 + 10) cout << "impossible\n";
        else
            cout << d[n] << "\n";
    };