// ax = b(mod m)
// ax - my = b;
LL exgcd(LL a, LL b, LL&x, LL& y){
	if(!b)
	{
		x = 1, y = 0;
		return a;
	}
	LL d = exgcd(b, a % b, y, x);
	y -= x * (a / b);
	return d;
}
 
void solve() {
    LL a, b, m; cin >> a >> b >> m;
    LL x, y;
    LL d = exgcd(a, m, x, y);
    if(b % d != 0)
    {
    	cout << "impossible\n";
    	return;
    }
    LL t = b / d;
    cout << x * t % m << "\n";
}