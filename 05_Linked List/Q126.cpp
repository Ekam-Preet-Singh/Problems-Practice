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
Q126.) Reverse a Linked List in group of Given Size. [Very Imp]

INPUT:
4

5
1 2 3 4 5
2

10
0 1 2 3 4 5 6 7 8 9
4

5
1 2 3 4 5
3

8
1 2 2 4 5 6 7 8
4

OUTPUT:
Case #1: 2 1 4 3 5
Case #2: 3 2 1 0 7 6 5 4 9 8
Case #3: 3 2 1 5 4
Case #4: 4 2 2 1 8 7 6 5

*/

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution
{
public:
    Node *reverse(Node *head, int k)
    {
        Node *current = head;
        Node *next = NULL;
        Node *prev = NULL;
        int count = 0;

        while (current != NULL && count < k)
        // reversing k elements :
        {
            next = current->next; // marking next Node
            current->next = prev; // reversing link
            prev = current;       // updating prev
            current = next;       // updating current
            count++;
        }

        // checking if there are Nodes ahead
        if (next != NULL)
        {
            head->next = reverse(next, k); // reversing those recursively
        }

        return prev; // returning new head
    }
};

void solve()
{
    Node *head = NULL;
    Node *temp = NULL;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        if (i == 0)
        {
            head = new Node(value);
            temp = head;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }

    int k;
    cin >> k;

    Solution ob;
    head = ob.reverse(head, k);
    printList(head);
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