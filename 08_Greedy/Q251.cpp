#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define ump unordered_map
#define mp make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define all(n) n.begin(), n.end()
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define bitc(n) __builtin_popcount(n)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define iter(container, it) for (__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;
template <typename T>
T gcd(T a, T b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }
vs tokenizer(string str, char ch)
{
    std::istringstream var((str));
    vs v;
    string t;
    while (getline((var), t, (ch)))
    {
        v.pb(t);
    }
    return v;
}

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
Q251.) Rearrange characters in a string such that no two adjacent are same

INPUT:
3

geeksforgeeks

bbbabaaacd

bbbbb

OUTPUT:
Case #1: 1
Case #2: 1
Case #3: 0

*/

const int MAX_CHAR = 26;
struct Key
{
    int freq; // store frequency of character
    char ch;
    bool operator<(const Key &k) const
    {
        return freq < k.freq;
    }
};

string rearrangeString(string str)
{
    int n = str.length();
    int count[MAX_CHAR] = {0};
    for (int i = 0; i < n; i++)
    {
        count[str[i] - 'a']++;
    }
    priority_queue<Key> pq;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (count[c - 'a'])
        {
            pq.push(Key{count[c - 'a'], c});
        }
    }
    str = "";
    Key prev{-1, '#'};
    while (!pq.empty())
    {
        Key k = pq.top();
        pq.pop();
        str = str + k.ch;
        if (prev.freq > 0)
        {
            pq.push(prev);
        }
        (k.freq)--;
        prev = k;
    }
    if (n != str.length())
    {
        return "-1";
    }
    else
    {
        return str;
    }
}

void solve()
{
    string str;
    cin >> str;
    str = rearrangeString(str);
    int flag = 1;
    if (str != "-1")
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (i > 0)
                if (str[i - 1] == str[i])
                    flag = 0;
        }
        if (flag == 1)
            cout << "1\n";
        else
            cout << "0\n";
    }
    else
        cout << "0\n";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    file_i_o();

    ll t = 1;
    ll case_num = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}