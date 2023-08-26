/*************************************************************************
    > File Name: 02.cpp
    > Author: kizk
    > blog: https://kizk.gitee.io
    > Created Time: Mon Jul 31 19:35:23 2023
 ************************************************************************/
// 问题描述：给出一段区间[L,R]（连续区间），假设 区间长度为len，那么一共有 len*(len-1)/2个pair，问所有pair的异或和为多少？
// [1, 3] 1 ^ 2 = 3, 1 ^ 3 = 2, 2 ^ 3 = 1 -> total = 3 + 2 + 1 = 6
//  l, r <= 1e6
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define int LL

void solve(){
	int l, r; cin >> l >> r; 
	int res = 0;
	for(int k = 0; k < 31; k ++)
	{
		int z = 0, o = 0;
		for(int i = l; i <= r; i ++)
		{
			int x = i >> k & 1;
			if(x) 
				res += (1 << k) * z, o++ ; // 对于所有当前位等于 0 当前的这位1是有效的
			else
				res += (1 << k) * o, z++ ;
		}
	}
	cout << res << "\n";
}
signed main(){

    ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T = 1;
    while(T--) solve();
    return 0;
}
