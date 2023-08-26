const int p1 = 13331, p2 = 1333331;
typedef unsigned long long ULL;
 
void solve() {
    int n, m; cin >> n >> m;
    string str; cin >> str;
    str = " " + str;
    vector<ULL> c1(n + 1), c2(n + 1), h1(n + 1), h2(n + 1);
    c1[0] = c2[0] = 1;
    for(int i = 1; i <= n; i ++)
    {
    	h1[i] = h1[i - 1] * p1 + str[i];
    	c1[i] = c1[i - 1] * p1;
    	h2[i] = h2[i - 1] * p2 + str[i];
    	c2[i] = c2[i - 1] * p2;
    }
    auto get = [&](int l, int r) -> pair<ULL, ULL>{
    	return {h1[r] - h1[l - 1] * c1[r - l + 1], h2[r] - h2[l - 1] * c2[r - l + 1]};
    };
    for(int i = 0; i < m; i ++)
    {
    	int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    	cout << (get(l1, r1) == get(l2, r2) ? "Yes\n" : "No\n");
    }
}