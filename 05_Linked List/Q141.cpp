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
Q141.) Split a Circular linked list into two halves.

INPUT:
3

5
1 2 3 4 5

3
1 5 7

6
6 5 4 3 2 1

OUTPUT:
Case #1: 
First Circular Linked List: 1 2 3 
Second Circular Linked List: 4 5 
Case #2: 
First Circular Linked List: 1 5 
Second Circular Linked List: 7 
Case #3: 
First Circular Linked List: 6 5 4 
Second Circular Linked List: 3 2 1 

*/

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

struct Node *newNode(int key)
{
    struct Node *temp = new Node(key);

    return temp;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
}

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    if (head == NULL)
    {
        return;
    }
    /* If there are odd nodes in the circular list then
          fast_ptr->next becomes head and for even nodes
          fast_ptr->next->next becomes head */
    while (fast_ptr->next != head && fast_ptr->next->next != head)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    /* If there are even elements in list
           then move fast_ptr */
    if (fast_ptr->next->next == head)
    {
        fast_ptr = fast_ptr->next;
    }
    /* Set the head pointer of first half */
    *head1_ref = head;
    /* Set the head pointer of second half */
    if (head->next != head)
    {
        *head2_ref = slow_ptr->next;
    }
    /* Make second half circular */
    fast_ptr->next = slow_ptr->next;
    /* Make first half circular */
    slow_ptr->next = head;
}

void solve()
{
    int n, x, i;
    struct Node *temp, *head = NULL;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    cin >> n >> x;
    head = new Node(x);
    temp = head;
    for (i = 0; i < n - 1; i++)
    {
        cin >> x;
        temp->next = new Node(x);

        temp = temp->next;
    }

    temp->next = head;

    splitList(head, &head1, &head2);

    cout << "\nFirst Circular Linked List: ";
    printList(head1);

    cout << "Second Circular Linked List: ";
    printList(head2);
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