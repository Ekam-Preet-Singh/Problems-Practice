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
Q299.) Reverse the first ???K??? elements of a queue

INPUT:
2

5 3
1 2 3 4 5

4 4
4 3 2 1

OUTPUT:
Case #1: 3 2 1 4 5
Case #2: 1 2 3 4

*/

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    // using a stack and another queue to reverse first k elements.
    stack<int> s;
    queue<int> qq;

    // we pop first k elements from queue and push it in the stack.
    while (k-- > 0)
    {
        int a = q.front();
        q.pop();
        s.push(a);
    }

    // while stack is not empty, we push the elements into the new queue.
    while (!s.empty())
    {
        int a = s.top();
        s.pop();
        qq.push(a);
    }

    // then we add rest of the elements of original queue to the new queue.
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        qq.push(a);
    }

    // returning the new queue.
    return qq;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    queue<int> q;
    while (n-- > 0)
    {
        int a;
        cin >> a;
        q.push(a);
    }
    queue<int> ans = modifyQueue(q, k);
    while (!ans.empty())
    {
        int a = ans.front();
        ans.pop();
        cout << a << " ";
    }
    cout << endl;
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