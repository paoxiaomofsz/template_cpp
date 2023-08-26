int n, m, k; cin >> n >> m >> k;
	vector<tuple<int, int, int>> v(m);
	for(int i = 0; i < m; i ++)
	{
		int a, b, c; cin >> a >> b >> c;
		v[i] = tuple<int, int, int>(a, b, c);
	}
	vector<int> d(n + 1, 1e9 + 10);
	d[1] = 0;
	while(k --)
	{
		vector<int> back = d;
		for(auto& ite : v)
		{
			int a = get<0>(ite), b = get<1>(ite), c = get<2>(ite);
			d[b] = min(d[b], back[a] + c);
		}
	}
	if(d[n] > 1e7) cout << "impossible\n";
	else
		cout << d[n] << "\n";