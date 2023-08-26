/*************************************************************************
    > File Name: 01.cpp
    > Author: kizk
    > blog: https://kizk.gitee.io
    > Created Time: Mon Jul 31 19:28:50 2023
 ************************************************************************/
// 给 一个序列中 有多少异或和为 x 比如 输入 
// 3
// 1 2 3
// 0
// output: 1
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define int LL

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(int& i : v) cin >> i;
	int x; cin >> x;
	unordered_map<int, int> mp;
	int t = 0, res = 0;
	mp[0] = 1;
	for(int& i : v)
	{
		t ^= i;
		res += mp[t];
		mp[t] ++ ;
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
