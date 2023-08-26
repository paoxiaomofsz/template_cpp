// 快速幂
LL qmi = [&](LL a, LL b, LL p) -> LL{
    LL t = 1;
    while(b){
        if(b & 1) t = t * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return t;
};
// exgcd
LL exgcd(LL a, LL b, LL&x, LL& y){
    if(!b)
        return (x = 1, y = 0, a); 
    LL d = exgcd(b, a % b, y, x);
    return (y -= x * (a / b), d);
}
void solve(){
	LL a, b; cin >> a >> b;
    LL x, y;
    LL d = exgcd(a, b, x, y);
    if(d != 1)
    	cout << "impossible\n";
    else
    	cout << (x % b + b) % b << "\n";
}
// 递推
vector<int> inv(n + 1);
inv[1] = 1;
int p;
for(int i = 2; i <= n; i ++) inv[i] = (p - p / i) * inv[p % i] % p; 