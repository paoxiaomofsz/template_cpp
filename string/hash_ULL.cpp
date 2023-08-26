const int p = 13331;
typedef unsigned long long ULL;
 
void solve() {
    int n, m; cin >> n >> m;
    string str; cin >> str;
    str = " " + str;
    vector<ULL> c(n + 1), h(n + 1);
    c[0] = 1;
    for(int i = 1; i <= n; i ++)
    {
    	h[i] = h[i - 1] * p + str[i];
    	c[i] = c[i - 1] * p;
    }
    auto get = [&](int l, int r) -> int{
    	return h[r] - h[l - 1] * c[r - l + 1];
    };
    for(int i = 0; i < m; i ++)
    {
    	int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    	cout << (get(l1, r1) == get(l2, r2) ? "Yes\n" : "No\n");
    }
}