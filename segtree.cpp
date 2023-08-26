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
};