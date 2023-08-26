// 计算  k mod 1 + k mod 2 + ... +  k mod n
void solve() {

    int n, k; cin >> n >> k;
    LL res = n * k;
    LL ans = 0;
    for(int l = 1, r; l <= n; l = r + 1)
    {
        r = k / l ? min(n, k / (k / l)) : n;
        ans += (r - l + 1) * (l + r) * (k / l) / 2;
    }
    cout << res - ans << "\n";
}