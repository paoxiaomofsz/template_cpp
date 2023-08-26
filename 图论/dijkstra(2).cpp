auto dijkstra = [&](int root) -> int{
        vector<int> d(n + 1, 1e9 + 10);
        d[root] = 0;	
        priority_queue<PII, vector<PII>, greater<PII> > q;
        q.push({0, root});
        while(q.size())
        {
            auto [dist, id] = q.top(); q.pop();
            if(d[id] != dist) continue;
            for(auto& [b, w] : g[id])
            {
                if(d[b] > dist + w)
                {
                    d[b] = dist + w;
                    q.push({d[b], b});
                }
            }
        }
        return d[n] == 1e9 + 10 ? -1 : d[n];
    };