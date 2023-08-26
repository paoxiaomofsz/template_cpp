auto insert = [&](string& str) -> void{
        int p = 0;
        for(auto& ite : str)
        {
            int u = ite - 'a';
            if(!s[p][u]) s[p][u] = ++ idx;
            p = s[p][u];
        }
        cnt[p] ++ ;
    };
    auto query = [&](string& str) -> int{
        int p = 0;
        for(auto& ite : str)
        {
            int u = ite - 'a';
            if(!s[p][u]) return 0;
            p = s[p][u];
        }
        return cnt[p];
    };