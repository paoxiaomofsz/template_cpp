struct node
{
    int fail;
    int ch[26];
    int ans;
};
struct node NIL = {0};
struct trie
{
    vector<node> tr;
    vector<int> in;
    map<int, int> ref;
    int siz = 0;
    void insert(string s,int x)
    {
        if(!tr.size())
            tr.push_back(NIL);
        int place = 0;
        for (int i = 0; i < s.length();i++)
        {
            if (tr[place].ch[s[i] - 97] == 0)
            {
                tr[place].ch[s[i] - 97] = ++siz;
                tr.push_back(NIL);
                in.push_back(0);
            }
            place = tr[place].ch[s[i] - 97];
        }
        ref[x] = place;
    }
    void build()
    {
        queue<int> q;
        for (int i = 0; i < 26;i++)
            if(tr[0].ch[i])
                q.push(tr[0].ch[i]);
        while(!q.empty())
        {
            int tp = q.front();
            q.pop();
            for (int i = 0; i < 26;i++)
                if(tr[tp].ch[i])
                {
                    tr[tr[tp].ch[i]].fail = tr[tr[tp].fail].ch[i];
                    in[tr[tr[tp].fail].ch[i]]++;
                    q.push(tr[tp].ch[i]);
                }
                else
                    tr[tp].ch[i] = tr[tr[tp].fail].ch[i];
        }
    }
    void query(string t)
    {
        int place = 0;
        for (int i = 0; i < t.length();i++)
        {
            place = tr[place].ch[t[i] - 97];
            tr[place].ans++;
        }
    }
    void topo()
    {
        queue<int> q;
        for (int i = 1; i <= siz;i++)
            if(!in[i])
                q.push(i);
        while(!q.empty())
        {
            int tp = q.front();
            q.pop();
            tr[tr[tp].fail].ans += tr[tp].ans;
            in[tr[tp].fail]--;
            if(!in[tr[tp].fail])
                q.push(tr[tp].fail);
        }
    }
};