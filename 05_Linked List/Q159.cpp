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
Q159.) Program for n’th node from the end of a Linked List

INPUT:
4

4 5
10 5 100 5

7 5
17 15 8 9 2 4 6

4 3
1 3 5 7

9 2
1 2 3 4 5 6 7 8 9

OUTPUT:
Case #1: -1
Case #2: 8
Case #3: 3
Case #4: 8

*/

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    // using two pointers, similar to finding middle element.
    Node *currNode = head, *nthNode = head;

    // traversing first n elements with first pointer.
    while (n != 0)
    {
        if (currNode == NULL)
        {
            return -1;
        }
        currNode = currNode->next;
        n--;
    }
    // now traversing with both pointers and when first pointer gives null
    // we have got the nth node from end in second pointer since the first
    // pointer had already traversed n nodes and thus had difference of n
    // nodes with second pointer.
    while (currNode != NULL)
    {
        nthNode = nthNode->next;
        currNode = currNode->next;
    }

    // returning the data of nth node from end.
    if (nthNode != NULL)
    {
        return nthNode->data;
    }
    else
    {
        return -1;
    }
}

void solve()
{
    int i, n, l, k;
    cin >> n >> k;
    struct Node *head = NULL, *tail = NULL;
    int firstdata;
    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;
    for (i = 1; i < n; i++)
    {
        cin >> l;
        tail->next = new Node(l);
        tail = tail->next;
    }

    cout << getNthFromLast(head, k) << endl;
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