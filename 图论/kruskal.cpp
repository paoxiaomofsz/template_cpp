int n, m; cin >> n >> m;
    vector<array<int, 3>> v;
    for(int a, b, c; cin >> a >> b >> c; )v.push_back({a, b, c});
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    auto find = [&](auto find, int x) -> int{
        return p[x] ^ x ? p[x] = find(find, p[x]) : x;
    };
    sort(v.begin(), v.end(), [&](array<int, 3>& a, array<int, 3>& b){
        return a[2] < b[2];
    });
    int res = 0;
    int cnt = n;
    for(auto&[a, b, c] : v)
    {
        a = find(find, a), b = find(find, b);
        if(a ^ b)
        {
            p[a] = b;
            res += c;
            cnt -- ;
        }
    }
    if(cnt ^ 1)
        cout << "impossible\n";
    else
        cout << res << "\n";
        