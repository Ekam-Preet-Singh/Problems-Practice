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
Q220.) Huffman Coding

INPUT:
2
abcdef
5 9 12 13 16 45
qwertyuiopasdfghjklzxcv
4 4 17 28 38 41 41 48 55 56 57 66 69 71 71 72 74 75 75 77 92 96 98

OUTPUT:
Case #1: 0 100 101 1100 1101 111
Case #2: 0000 0001 0010 0011 0100 0101 0110 0111 1000 10010 10011 10100 10101 1011 1100 1101 11100000 11100001 1110001 111001 11101 11110 11111

*/

struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

class Solution
{
public:
    void getCodes(struct MinHeapNode *root, string str, vector<string> &res)
    {
        if (!root)
            return;
        if (root->data != '$')
        {
            res.push_back(str);
        }
        getCodes(root->left, str + "0", res);
        getCodes(root->right, str + "1", res);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        struct MinHeapNode *left, *right, *top;
        priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
        for (int i = 0; i < N; ++i)
            minHeap.push(new MinHeapNode(S[i], f[i]));
        while (minHeap.size() != 1)
        {
            left = minHeap.top();
            minHeap.pop();
            right = minHeap.top();
            minHeap.pop();
            top = new MinHeapNode('$', left->freq + right->freq);
            top->left = left;
            top->right = right;
            minHeap.push(top);
        }
        vector<string> res;
        getCodes(minHeap.top(), "", res);
        return res;
    }
};

void solve()
{
    string S;
    cin >> S;
    int N = S.length();
    vector<int> f(N);
    for (int i = 0; i < N; i++)
    {
        cin >> f[i];
    }
    Solution ob;
    vector<string> ans = ob.huffmanCodes(S, f, N);
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
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