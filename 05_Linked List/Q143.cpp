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
Q143.) Deletion from a Circular Linked List.

INPUT:
2

5
2 5 7 8 10
7

6
1 2 3 4 5 6
7

OUTPUT:
Case #1:
List Before Deletion: 10 8 7 5 2
List After Deletion: 10 8 5 2
Case #2:
List Before Deletion: 6 5 4 3 2 1
No Such Key Found

*/

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int data)
{

    Node *ptr1 = new Node();
    ptr1->data = data;
    ptr1->next = *head_ref;

    if (*head_ref != NULL)
    {
        Node *temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;

    *head_ref = ptr1;
}

void printList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }

    cout << endl;
}

bool deleteNode(Node **head, int key)
{

    if (*head == NULL)
    {
        return 0;
    }

    if ((*head)->data == key && (*head)->next == *head)
    {
        delete (*head);
        *head = NULL;
        return 1;
    }

    Node *last = *head, *d;

    if ((*head)->data == key)
    {

        while (last->next != *head)
        {
            last = last->next;
        }

        last->next = (*head)->next;
        delete (*head);
        *head = last->next;
    }

    while (last->next != *head && last->next->data != key)
    {
        last = last->next;
    }

    if (last->next->data == key)
    {
        d = last->next;
        last->next = d->next;
        delete (d);
        return 1;
    }
    else
    {
        cout << "No Such Key Found\n";
        return 0;
    }
}

void solve()
{
    Node *head = NULL;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        push(&head, val);
    }

    cout << "List Before Deletion: ";
    printList(head);
    cin >> val;
    bool a = deleteNode(&head, val);
    if (a)
    {
        cout << "List After Deletion: ";
        printList(head);
    }
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