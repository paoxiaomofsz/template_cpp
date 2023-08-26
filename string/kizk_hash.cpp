struct kizk_hash{
    int n;
    string str;
    vector<int> p, h;
    vector<int> p1, h1; 
    int Mod = 1e9 + 7;
    int P = 13331;
    int P1 = 1333331;
    int Mod1 = 998244353;
    kizk_hash(int _n, string _str) : n(_n), str(' ' + _str){ init();}
    kizk_hash(string _str) : n(_str.size()), str(' ' + _str) {init();}
    kizk_hash(){}
    void set_mod(int _Mod){this->Mod = _Mod;}
    void set_P(int _P){this->P = _P;}
    void init(){
        p.resize(n + 1);
        h.resize(n + 1);
        p[0] = 1;
        for(int i = 1; i <= n; i ++)
        {
            h[i] = (h[i - 1] * P % Mod + str[i] - 'a' + 1) % Mod;
            p[i] = p[i - 1] * P % Mod;
        }
    }
    void init_double(){
        p1.resize(n + 1);
        h1.resize(n + 1);
        p1[0] = 1;
        for(int i = 1; i <= n; i ++)
        {
            h1[i] = (h1[i - 1] * P1 % Mod1 + str[i] - 'a' + 1) % Mod1;
            p1[i] = p1[i - 1] * P1 % Mod1;
        }
    }
    int get_hash_single(int l, int r){
        return (h[r] - h[l - 1] * p[r - l + 1] % Mod + Mod) % Mod;
    }
    pair<int, int> get_hash_double(int l, int r){
        return {(h[r] - h[l - 1] * p[r - l + 1] % Mod + Mod) % Mod, (h1[r] - h1[l - 1] * p1[r - l + 1] % Mod1 + Mod1) % Mod1};
    }
};

