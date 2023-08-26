// 知识 欧拉函数式积性函数 -> \phi(ab) = \phi(a) \phi(b)
// 当 n & 1 -> \phi(2n) = \phi(n)
// n = \sum_{d|n} \phi(d) -> n 等于 其约数的所有欧拉函数之和


// 一堆性质: https://oi-wiki.org/math/number-theory/euler/

// 1 ~ n 欧拉函数的和
void get(int n){
    phi[1] = 1;
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i])
        {
            primes[cnt ++ ] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; primes[j] <= n / i; j ++)
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0)
            {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
}
// phi(x)
int x; cin >> x;
        int res = x;
        for(int i = 2; i <= x / i; i ++)
            if(x % i == 0)
            {
                res = res / i * (i - 1);
                while(x % i == 0)
                    x /= i;
            }
        if(x > 1)
            res = res / x * (x - 1);
        cout << res << endl;