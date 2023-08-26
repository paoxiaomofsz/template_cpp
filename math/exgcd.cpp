LL exgcd(LL a, LL b, LL& x, LL& y) {
    if(!b)
        return (x = 1, y = 0, a); 
    LL d = exgcd(b, a % b, y, x);
    return (y -= x * (a / b), d);
}

// 矩阵 -> 会慢一点貌似在acwing上
LL exgcd(LL a, LL b, LL &x, LL &y) {
  LL x1 = 1, x2 = 0, x3 = 0, x4 = 1;
  while (b != 0) {
    LL c = a / b;
    std::tie(x1, x2, x3, x4, a, b) =
        std::make_tuple(x3, x4, x1 - x3 * c, x2 - x4 * c, b, a - b * c);
  }
  x = x1, y = x2;
  return a;
}