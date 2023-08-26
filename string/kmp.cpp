struct kizk_kmp{
    string p, s;
    int n, m;
    vector<int> ne, idx;
    kizk_kmp(string& _p) : p(_p){this->n = _p.size();}
    kizk_kmp(string& _p, string& _s) : p(_p), s(_s){this->n = _p.size(), this->m = _s.size();} 
    kizk_kmp(){}
    void set_p(string& a){
        if(a == this->p) return;
        this->p = a, this->n = a.size();
        this->ne.clear();
    }
    void set_s(string& a){
        if(this->s == a) return;
        this->s = a, this->m = a.size(); 
        this->idx.clear();
    }
    vector<int> kmp_ne(){
        if(this->ne.size()) return this->ne;
        int n = this->n;
        string p = this->p;
        vector<int> ne(n + 1);
        for(int i = 1, j = 0; i < n; i ++)
        {
            while(j && p[i] != p[j]) j = ne[j];
            j += (p[i] == p[j]);
            ne[i + 1] = j;
        }
        return this->ne = ne;
    }
    vector<int> kmp_idx(){
        if(!this->ne.size()) this->kmp_ne();
        if(this->idx.size()) return this->idx; 
        int n = this->n, m = this->m;
        string p = this->p, s = this->s;
        vector<int>v;
        for(int i = 0, j = 0; i < m; i ++)
        {
            while(j && s[i] != p[j]) j = ne[j];
            j += (s[i] == p[j]);
            if(j == n)
                v.push_back(i - j + 1), j = ne[j]; 
            // left idx (i - j + 1) from zero  right idx (i) idx from zero
        }
        return this->idx = v;
    }
    vector<int> kmp_idx(string& s){
        if(!this->ne.size()) this->kmp_ne();
        int n = this->n;
        int m = s.size();
        vector<int>v;
        for(int i = 0, j = 0; i < m; i ++)
        {
            while(j && s[i] != p[j]) j = ne[j];
            j += (s[i] == p[j]);
            if(j == n)
                v.push_back(i - j + 1), j = ne[j];
        }
        return v;
    }
    int kmp_cnt(){
        return this->kmp_idx().size();
    }
    int kmp_cnt(string& s){
        return this->kmp_idx(s).size();
    }

};