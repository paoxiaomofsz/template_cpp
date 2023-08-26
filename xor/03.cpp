/*************************************************************************
    > File Name: 03.cpp
    > Author: kizk
    > blog: https://kizk.gitee.io
    > Created Time: Mon Jul 31 19:49:35 2023 ************************************************************************/
// 和 02.cpp 的要求一样 只不过现在 L, R <= 1e18
// 假设当前n个数字中 第k位有x个1 那么 总体的贡献为 (n - x) * (1 << k) * x // 简单的排列组合
// 现在问题变成要求第k位有几个1了
// f(x, k) -> 1 ~ k 有多少个1 根据 周期 第一位的周期为 2 第二位的周期为 4 第三位的周期为8
// ans = \sum_{i = 0}^{i = 63} * (f(r, i) - f(l - 1, i));
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define int LL

void solve(){
	int L, R; cin >> L >> R;
	L -- ;
	int n = R - L;
	vector<int> l(64), r(64);
	int p = 1;
	for(int i = 0; i < 64; i ++)
	{
		int k = (L + 1) / (p * 2), m = (L + 1) % (p * 2);
		l[i] = k * p + ((m - p) >= 0 ? m - p : 0);
		p <<= 1;
		if(p > (L + 1)) break;
	}
	p = 1;
	for(int i = 0; i < 64; i ++)
	{
		int k = (R + 1) / (p * 2), m = (R + 1) % (p * 2);
		r[i] = k * p + ((m - p) >= 0 ? m - p : 0);
		p <<= 1;
		if(p > (R + 1)) break;
	}
	int res = 0;
	for(int k = 0; k < 32; k ++)
	{
		int d = r[k]- l[k];
		res += (1 << k) * (d) * (n - d); 
	}
	cout << res << "\n";
}
signed main(){

    ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
