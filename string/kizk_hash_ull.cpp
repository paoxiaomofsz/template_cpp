
typedef unsigned long long ULL;

struct kizk_hash_ull{
    int n;
    string str;
    vector<ULL> p, h, p1, h1;
    int P = 13331, P1 = 1333331;
    kizk_hash_ull(int _n, string _str) : n(_n), str(' ' + _str) {this->init();}
    kizk_hash_ull(string _str) : n(_str.size()), str(' ' + _str) {this->init();}
    void init(){
        p.resize(n + 1);
        h.resize(n + 1);
        p1.resize(n + 1);
        h1.resize(n + 1);
        p[0] = p1[0] = 1;
        for(int i = 1; i <= n; i ++)
        {
            h[i] = h[i - 1] * P + str[i] - 'a' + 1;
            p[i] = p[i - 1] * P;
            h1[i] = h1[i - 1] * P1 + str[i] - 'a' + 1;
            p1[i] = p1[i - 1] * P1;
        }
    } 
    int get_hash_single(int l, int r){
        return h[r] - h[l - 1] * p[r - l + 1];
    }
    pair<int, int> get_hash_double(int l, int r){
        return {h[r] - h[l - 1] * p[r - l + 1], h1[r] - h1[l - 1] * p1[r - l + 1]};
    }
    
};
