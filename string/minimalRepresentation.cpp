auto minimalRepresentation = [&](string& s) -> string{
        int n = s.size();
        int i = 0, j = 1, k = 0; 
        while(i < n && j < n && k < n)
        {
            char a = s[(i + k) % n], b = s[(j + k) % n];
            if(a == b) k ++ ;
            else
            {
                if(a > b) i += k + 1;
                else j += k + 1;
                if(i == j) i ++ ;
                k = 0;
            }
        }
        i = min(i, j);
        return s.substr(i) + s.substr(0, i);
    };