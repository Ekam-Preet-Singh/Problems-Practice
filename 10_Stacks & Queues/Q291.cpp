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
Q291.) Implement Stack using Queue

INPUT:
2

5
1 2 1 3 2 1 4 2

4
1 2 2 2 1 3

OUTPUT:
Case #1: 3 4
Case #2: 2 -1

*/

class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int num)
    {
        // while first queue is not empty, we keep popping the front element
        // from first queue and storing that element in second queue.
        while (!q1.empty())
        {
            int k = q1.front();

            // popping element from first queue.
            q1.pop();

            // pushing it into second queue.
            q2.push(k);
        }

        // q1 is empty now and we push the given number into first queue.
        q1.push(num);

        // while second queue is not empty, we keep popping the front element
        // from second queue and storing that element in first queue.
        while (!q2.empty())
        {
            int k = q2.front();
            // popping element from second queue.
            q2.pop();

            // pushing it into first queue.
            q1.push(k);
        }
    }
    int pop()
    {

        // if first queue is not empty, then we can pop an element.
        if (!q1.empty())
        {
            // we store the front element from the queue in a
            // variable and pop that element.
            int r = q1.front();
            q1.pop();

            // returning the popped element.
            return r;
        }
        // else we return -1.
        return -1;
    }
};

void solve()
{
    QueueStack *qs = new QueueStack();

    int Q;
    cin >> Q;
    while (Q--)
    {
        int QueryType = 0;
        cin >> QueryType;
        if (QueryType == 1)
        {
            int a;
            cin >> a;
            qs->push(a);
        }
        else if (QueryType == 2)
        {
            cout << qs->pop() << " ";
        }
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