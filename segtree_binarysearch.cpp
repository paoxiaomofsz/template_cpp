
#define ls u << 1
#define rs u << 1 | 1
struct SegTree{
    
    struct Node{
        // to do
        
    };
    
    vector<int> w;
    vector<Node> tr;
    SegTree(int n) :tr(n * 4 + 1), w(n + 1){}
    
    void pushup(Node& u, Node& l, Node& r){
        // to do
        
    }
    void pushup(int u){
        pushup(tr[u], tr[ls], tr[rs]);
    }
    void build(int u, int l, int r){
        tr[u] = {l, r};
        if(l == r)
        {
            // to do 
            
            return;
        }
        int mid = l + r >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int idx, int val){
        if(tr[u].l == tr[u].r && tr[u].l == idx)
        {
            // to do 
            
            return;
        }
        int mid = tr[u].l + tr[u].r >> 1;
        if(idx <= mid) modify(ls, idx, val);
        else
            modify(rs, idx, val);
        pushup(u);
    }
    
    Node query(int u, int L, int R){
        if(tr[u].l >= L && tr[u].r <= R)
            return tr[u];
        int mid = tr[u].l + tr[u].r >> 1;
        if(R <= mid) return query(ls, L, R);
        else if (L > mid) return query(rs, L, R);
        else
        {
            // to do
        }
    }
    int ask(int u, int L, int R, int d){
        if(tr[u].l == L && tr[u].r == R)
        {
            if(tr[u].maxv < d) return -1;
            if(tr[u].l == tr[u].r) return tr[u].l; 
            int mid = tr[u].l + tr[u].r >> 1;
            if(tr[ls].maxv >= d) return ask(ls, L, mid, d);
            return ask(rs, mid + 1, R, d);
        }
        int mid = tr[u].l + tr[u].r >> 1;
        if(R <= mid) return ask(ls, L, R, d);
        else if(L > mid) return ask(rs, L, R, d);
        else
        {
            int pos = ask(ls, L, mid, d);
            if(pos == -1) return ask(rs, mid + 1, R, d);
            else
                return pos;
        }
    }
};

void solve() {
    int n, q; cin >> n >> q;
    SegTree se(n);
    for(int i = 1; i <= n; i ++) cin >> se.w[i];
    se.build(1, 1, n);
    while(q --)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int x, d; cin >> x >> d;
            se.modify(1, x, d);
        }
        else
        {
            int l, r, d; cin >> l >> r >> d;
            cout << se.ask(1, l, r, d) << "\n";
        }
    }
}
 