// find x
void solve() {
    int n; cin >> n;
    int a = 0, b = 1; // x mod b = a
    auto merge = [&](int& a, int& b, int c, int d) -> void{
        if(a == -1 || b == -1)
            return;
        LL x, y;
        LL g = exgcd(b, d, x, y);
        if((c - a) % g != 0)
        {
            a = b = -1;
            return;
        }
        d /= g; // d'
        LL t = (c - a) / g % d; 
        LL t0 = x * t % d; // ka = ka'(mod m) -> a = a'(mod m / k) 其中 k | m
        if(t0 < 0) t0 += d;
        a = a + b * t0;
        b = b * d; // lcm
    };
    for(int i = 0; i < n; i ++)
    {
        int c, d; cin >> d >> c;
        merge(a, b, c, d); 
        if(a == -1 && b == -1)
        {
            cout << "-1\n";
            return;
        }
    }    
    cout << a << "\n";
}
// check x is exist
bool solve() {
    int n; cin >> n;
    map<int, vector<pair<int, int>>> mp;
    for(int i = 0; i < n; i ++)
    {
        int x, a; cin >> x >> a;
        for(int j = 2; j <= x / j; j ++)
        {
            if(x % j == 0)
            {
                int p = j, q = j;
                while(x % j == 0) x /= j, q *= j;
                mp[p].push_back({q, a % q});
            }
        }
        if(x > 1) mp[x].push_back({x, a % x});
    }
    for(auto& ite : mp)
    {
        auto v = ite.second;
        int t = max_element(v.begin(), v.end()) -> second;
        for(auto& val : v)
            if(t % val.first != val.second) return false;
    } 
    return true;
}