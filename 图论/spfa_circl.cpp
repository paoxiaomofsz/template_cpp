auto spfa = [&](int root) -> bool{
        memset(d, 0x3f, sizeof d);
        d[1] = 0;
        queue<int> q;
        for(int i = 1; i <= n; i ++)
            st[i] = true, q.push(i);
        while(q.size())
        {
            int t = q.front();
            q.pop();
            st[t] = false;
            for(auto& [j, w] : g[t])
            {
                if(d[j] > d[t] + w) 
                {
                    d[j] = d[t] + w;
                    cnt[j] = cnt[t] + 1;
                    if(cnt[j] == n)
                        return true;
                    if(!st[j])
                    {
                        st[j] =  true;
                        q.push(j);
                    }
                }
            }
        }
        return false;
    };
    if(spfa(1))
        cout << "Yes\n";
    else
        cout << "No\n";