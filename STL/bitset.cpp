#include <bits/stdc++.h>

using namespace std;

int main(){
    bitset<100010> s;
    int pos = 1;
    s.reset(); // set all 0
    s.reset(pos); // set pos to 0
    s.set(); // set all 1
    s.set(pos); // set pot to 1
    s.set(pos, false); // set pow false/true 
    s.count(); // return count 1
    s.size(); // return size
    s.any(); // if 1 in s return true
    s.none(); // if all 0 return true
    s.all(); // if all 1 return true
    s.flip(); // ^ bitset<N> s; s.set();
    s.flip(pos); // filp pos
    s.to_string(); // to_string
    s.to_ullong(); // return unsigned long long
    s.to_ulong(); // return unsigned long
    s._Find_first(); // return first idx 1 if 1 in s else return size of s
    s._Find_next(); // return >= pos first idx 1 if 1 is s[pos:] else return size of s
    return 0;
}