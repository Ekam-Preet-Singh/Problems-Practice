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
Q144.) Reverse a Doubly Linked list.

INPUT:
9

5
1 2 3 4 5

3
1 5 7

6
6 5 4 3 2 1

5
1 2 3 4 5

3
1 2 1

4
1 2 3 4

6
6 5 4 4 5 6

3
3 4 5

4
75 122 59 196

OUTPUT:
Case #1: 5 4 3 2 1
Case #2: 7 5 1
Case #3: 1 2 3 4 5 6
Case #4: 5 4 3 2 1
Case #5: 1 2 1
Case #6: 4 3 2 1
Case #7: 6 5 4 4 5 6
Case #8: 5 4 3
Case #9: 196 59 122 75

*/

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *newNode(int data)
{
    Node *temp = new Node(data);

    return temp;
}

void displayList(Node *head)
{
    while (head->next)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
}

int getLength(Node *head)
{
    Node *temp = head;

    int count = 0;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count + 1;
}

bool verify(Node *head)
{
    int fl = 0;
    int bl = 0;

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
        fl++;
    }
    while (temp->prev)
    {
        temp = temp->prev;
        bl++;
    }
    return fl == bl;
}

Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL, *curr = head;

    while (curr != NULL)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;

        curr = curr->prev;
    }

    return prev->prev;
}

void solve()
{
    int n;
    cin >> n;
    Node *head = NULL, *tail = NULL;
    int x;
    cin >> x;
    head = newNode(x);
    tail = head;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        Node *temp = newNode(x);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    head = reverseDLL(head);

    if (verify(head))
        displayList(head);
    else
        cout << "Your pointers are not correctly connected";

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