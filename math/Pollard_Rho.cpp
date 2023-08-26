std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
long long Pollard_Rho(long long x) {
  long long s = 0, t = 0;
  long long c = (long long)rng() % (x - 1) + 1;
  int step = 0, goal = 1;
  long long val = 1;
  for (goal = 1;; goal *= 2, s = t, val = 1) {  // 倍增优化
    for (step = 1; step <= goal; ++step) {
      t = ((__int128)t * t + c) % x;
      val = (__int128)val * abs(t - s) % x;
      if ((step % 127) == 0) {
        long long d = gcd(val, x);
        if (d > 1) return d;
      }
    }
    long long d = gcd(val, x);
    if (d > 1) return d;
  }
}

// 优化
#define LL long long
const __int128 ONE = 1;
static std::mt19937 MoBaiXHR;
inline LL F(LL x,LL c,LL MOD){return (ONE * x * x % MOD + c) % MOD;}
inline LL ABS(LL x){if(x < 0) return -x;return x;}
LL gcd(LL a,LL b)
{
	if(!b) return a;
	return gcd(b , a % b);
}
inline LL pr(LL n)
{
	if(n == 4) return 2;
	std::uniform_int_distribution<LL> Rand(3 , n - 1);
	LL x = Rand(MoBaiXHR) , y = x , c = Rand(MoBaiXHR);
	x = F(x , c , n) , y = F(F(y , c , n) , c , n);
	for(int lim = 1 ; x != y ; lim = min(lim << 1 , 128))
	{	
		LL cnt = 1;
		for(int i = 0 ; i < lim ; i ++) 
		{
			cnt = ONE * cnt * ABS(x - y) % n;
			if(!cnt) break;
			x = F(x , c , n) , y = F(F(y , c , n) , c , n);
		}
		LL d = gcd(cnt , n);
		if(d != 1) return d;
	}
	return n;
}