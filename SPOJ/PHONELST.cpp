struct trie
{
    unordered_map<char, trie *> m;
    bool end;

    trie() {
        end = false;
    }
};
bool insert(trie * root , string s)
{
    trie * curr =  root ;

    for (char ch : s)
    {
        if (!curr->m.count(ch))
            curr->m[ch] = new trie;

        curr = curr->m[ch];

        if (curr->end == true)
            return false;
    }
    curr->end = true;
    return curr->m.size() == 0; // this end shouldn' t have preexiting tail in directory
}
void solve()
{
    int  n;
    cin >> n ;

    bool flag = true;
    trie* root = new trie;
    while (n--)
    {
        string s ;
        cin >> s ;

        if (flag)
            flag =  insert(root, s);

    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
