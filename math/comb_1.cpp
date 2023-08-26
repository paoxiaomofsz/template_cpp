namespace kizk_math{

    LL mul(LL a, LL b, LL m) {
        return static_cast<__int128>(a) * b % m;
    }
    LL qmi(LL a, LL b, LL m = mod) {
        LL res = 1 % m;
        for (; b; b >>= 1, a = mul(a, a, m))
            if (b & 1)
                res = mul(res, a, m);
        return res;
    }
    LL inv(LL a, LL p){
        return qmi(a, p - 2, p);
    }
    LL inv(LL a){
        return qmi(a, mod - 2, mod); // define mod
    }
    
    bool isprime(LL n) {
        if (n < 2)
            return false;
        static constexpr int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
        int s = __builtin_ctzll(n - 1);
        LL d = (n - 1) >> s;
        for (auto a : a) {
            if (a == n)
                return true;
            LL x = qmi(a, d, n);
            if (x == 1 || x == n - 1)
                continue;
            bool ok = false;
            for (int i = 0; i < s - 1; ++i) {
                x = mul(x, x, n);
                if (x == n - 1) {
                    ok = true;
                    break;
                }
            }
            if (!ok)
                return false;
        }
        return true;
    }
    std::vector<LL> factorize(LL n) {
        std::vector<LL> p;
        std::function<void(LL)> f = [&](LL n) {
            if (n <= 10000) {
                for (int i = 2; i * i <= n; ++i)
                    for (; n % i == 0; n /= i)
                        p.push_back(i);
                if (n > 1)
                    p.push_back(n);
                return;
            }
            if (isprime(n)) {
                p.push_back(n);
                return;
            }
            auto g = [&](LL x) {
                return (mul(x, x, n) + 1) % n;
            };
            LL x0 = 2;
            while (true) {
                LL x = x0;
                LL y = x0;
                LL d = 1;
                LL power = 1, lam = 0;
                LL v = 1;
                while (d == 1) {
                    y = g(y);
                    ++lam;
                    v = mul(v, std::abs(x - y), n);
                    if (lam % 127 == 0) {
                        d = std::gcd(v, n);
                        v = 1;
                    }
                    if (power == lam) {
                        x = y;
                        power *= 2;
                        lam = 0;
                        d = std::gcd(v, n);
                        v = 1;
                    }
                }
                if (d != n) {
                    f(d);
                    f(n / d);
                    return;
                }
                ++x0;
            }
        };
        f(n);
        std::sort(p.begin(), p.end());
        return p;
    }
}

using namespace kizk_math;
namespace binom {
    LL fac[N], ifac[N];
    int __ = []
    {
        fac[0] = 1;
        for (int i = 1; i <= N - 5; i++)
            fac[i] = fac[i - 1] * i % mod;
        ifac[N - 5] = qmi(fac[N - 5], mod - 2);
        for (int i = N - 5; i; i--)
            ifac[i - 1] = ifac[i] * i % mod;
        return 0;
    }();

    inline LL C(int n, int m)
    {
        if (n < m || m < 0)return 0;
        return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
    }

    inline LL A(int n, int m)
    {
        if (n < m || m < 0)return 0;
        return fac[n] * ifac[n - m] % mod;
    }
}
using namespace binom;