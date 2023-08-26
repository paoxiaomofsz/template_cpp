struct BIT{
    vector<int> tr;
    int n;
    BIT(int n) : tr(n + 1){this->n = n;}
    int lowbit(int x){
        return x & -x;
    }
    void insert(int x, int val){
        for(; x <= n; x += lowbit(x))
            tr[x] += val;
    }
    int sum(int x){
        int res = 0;
        for(; x; x -= lowbit(x))
            res += tr[x];
        return res;
    }
}bit;