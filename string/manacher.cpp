vector<int> manacher(string a)
{
    string b = "$|";
    for (auto i : a)
    {
        b += i;
        b += '|';
    }
    int len = b.length();
    vector<int> hw(b.length());
    int maxright = 1, mid = 1;
    for (int i = 1; i < len; i++)
    {
        if (i < maxright)
            hw[i] = min(hw[mid * 2 - i], hw[mid] + mid - i);
        else
            hw[i] = 1;
        while (b[i - hw[i]] == b[i + hw[i]])
            hw[i]++;
        if (i + hw[i] > maxright)
        {
            maxright = i + hw[i];
            mid = i;
        }
    }
    return hw;
}