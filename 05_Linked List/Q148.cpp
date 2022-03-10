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
Q148.) Rotate DoublyLinked list by N nodes.

INPUT:
2

6 2
1 2 3 4 5 6

8 4
1 2 3 4 5 6 7 8

OUTPUT:
Case #1:
3 4 5 6 1 2
2 1 6 5 4 3
Case #2:
5 6 7 8 1 2 3 4
4 3 2 1 8 7 6 5

*/

typedef struct node
{
    int data;
    struct node *next, *prev;

    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }

} Node;

class Solution
{
public:
    Node *update(Node *start, int p)
    {
        Node *ptr1 = start, *ptr2 = start, *ptr3;
        int k = 0;
        while (ptr1 != NULL)
        {
            if (k == p)
            {
                break;
            }
            k++;
            ptr1 = ptr1->next;
        }
        ptr3 = ptr1->prev;
        while (ptr2->next != NULL)
        {
            ptr2 = ptr2->next;
        }
        ptr2->next = start;
        ptr3->next = NULL;
        start->prev = ptr2;
        start = ptr1;
        ptr1->prev = NULL;
        return start;
    }
};

void solve()
{
    int n, p;
    cin >> n >> p;
    struct node *start = NULL;
    struct node *cur = NULL;
    struct node *ptr = NULL;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ptr = new node(a);
        ptr->data = a;
        ptr->next = NULL;
        ptr->prev = NULL;
        if (start == NULL)
        {
            start = ptr;
            cur = ptr;
        }
        else
        {
            cur->next = ptr;
            ptr->prev = cur;
            cur = ptr;
        }
    }
    Solution obj;
    struct node *str = obj.update(start, p);
    while (1)
    {
        cout << str->data << " ";
        if (str->next == NULL)
        {
            break;
        }
        str = str->next;
    }
    cout << endl;
    while (str != NULL)
    {
        cout << str->data << " ";
        str = str->prev;
    }
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
        cout << "Case #" << case_num++ << ":\n";
        solve();
    }

    return 0;
}