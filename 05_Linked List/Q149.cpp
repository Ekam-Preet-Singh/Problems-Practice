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
Q149.) Rotate a Doubly Linked list in group of Given Size.[Very IMP]

INPUT:
4

7
9 8 6 5 4 2 1
17

7
1 2 4 5 6 8 9
15

6
8 56 12 2 6 3
2

10
1 2 3 4 5 6 7 8 9 10
4

OUTPUT:
Case #1:
9 8 6 5 4 2 1
1 2 4 5 6 8 9
Case #2:
1 2 4 5 6 8 9
9 8 6 5 4 2 1
Case #3:
8 56 12 2 6 3
56 8 2 12 3 6
Case #4:
1 2 3 4 5 6 7 8 9 10
4 3 2 1 8 7 6 5 10 9

*/

struct Node
{
    int data;
    Node *next, *prev;
};
// function to add Node at the end of a Doubly LinkedList
Node *insertAtEnd(Node *head, int data)
{

    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    Node *temp = head;
    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
        return head;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    return head;
}
// function to print Doubly LinkedList
void printDLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
// function to Reverse a doubly linked list
// in groups of given size
Node *reverseByN(Node *head, int k)
{
    if (!head)
    {
        return NULL;
    }
    head->prev = NULL;
    Node *temp, *curr = head, *newHead;
    int count = 0;
    while (curr != NULL && count < k)
    {
        newHead = curr;
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
        count++;
    }
    // checking if the reversed LinkedList size is
    // equal to K or not
    // if it is not equal to k that means we have reversed
    // the last set of size K and we don't need to call the
    // recursive function
    if (count >= k)
    {
        Node *rest = reverseByN(curr, k);
        head->next = rest;
        if (rest != NULL)
        {
            // it is required for prev link otherwise u wont
            // be backtrack list due to broken links
            rest->prev = head;
        }
    }
    return newHead;
}

void solve()
{
    Node *head = NULL;
    int n, val, pos;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        head = insertAtEnd(head, val);
    }
    printDLL(head);
    cin >> pos;
    head = reverseByN(head, pos);
    printDLL(head);
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