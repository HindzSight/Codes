#include <bits/stdc++.h>

using namespace std;

/*
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL),cout.tie(NULL);
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define pob pop_back
#define ep emplace_back
#define set_bits    __builtin_popcountll
#define all(x) x.begin(), x.end()
#define f(i,a,b) for(int i = a; i < b; i++)


typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

const float PI = 3.141592653589793238462;
const int N = 1e5 + 11, mod = 1e9 + 7;
ll max(ll a, ll b) { return ((a > b) ? a : b); }
ll min(ll a, ll b) { return ((a > b) ? b : a); }
template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else 
#define debug(x)
#endif


void _print(ll z) {cerr << z;}
void _print(int z) {cerr << z;}
void _print(string z) {cerr << z;}
void _print(char z) {cerr << z;}
void _print(lld z) {cerr << z;}
void _print(double z) {cerr << z;}
void _print(ull z) {cerr << z;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
*/
/***************************************************************/

vector<int> getNextIPAddress(vector<int> arr) {
    for (int i = 0; i < 4; i++) {
        if (arr[i] < 0 || arr[i] > 255) {
            cout << "Invalid IP address!\n";
            return arr;
        }
    }

    // Increment the last byte of the IP address
    arr[3]++;
    if (arr[3] > 255) {
        // cout << "bakchodi hui h 3";
        arr[3] = 0;
        // Increment the third byte of the IP address
        arr[2]++;
        if (arr[2] > 255) {
            arr[2] = 0;
            // cout << "bakchodi hui h @ 2";

            // Increment the second byte of the IP address
            arr[1]++;
            if (arr[1] > 255) {
                arr[1] = 0;
                // cout << "bakchodi hui h @ 1";

                // Increment the first byte of the IP address
                arr[0]++;
                if (arr[0] > 255) {
                    // Overflow occurred
                    cout << "IP address overflow!\n";
                    return arr;
                }
            }
        }
    }

    return arr;
}

vector<int> IPblocks(vector<int> giv, int n) {
    vector<int> arr(4,0);
    int oct = n / 8;
    int rem = n % 8;
    for (int i = 0; i < 4; i++) {
        arr[i] = 255;
    }
    int val = (32 - n);
    int num = val / 8;
    for (int i = 1; i <= num; i++) {
        arr[4 - i] = 0;
    }
    int p = val % 8;
    int zero = 0;
    if (p != 0) {
        for (int o = 0; o < p; o++) {
            zero += pow(2, o);
        }
        int newval = 255 - zero;
        arr[3 - num] = newval;
    }

    cout << endl;
    int num_add = pow(2, val);
    cout << "Number of address in the block : " << num_add << endl;
    int first_add[4] = { 0 };
    for (int i = 0; i < 4; i++) {
        first_add[i] = arr[i] & giv[i];
    }
    cout << "\nFirst Address : ";
    for (int i = 0; i < 4; i++) {
        cout << first_add[i];
        if (i != 3)
            cout << ".";
        else
            cout << "/" << n;
    }

    vector<int> last_add= {0,0,0,0};
    for (int i = 0; i < 4; i++) {
        arr[i] = 255 - arr[i];
    }
    for (int i = 0; i < 4; i++) {
        last_add[i] = arr[i] | giv[i];
    }
    cout << "\nLast Address : ";
    for (int i = 0; i < 4; i++) {
        cout << last_add[i];
        if (i != 3)
            cout << ".";
        else
            cout << "/" << n;
    }
    vector<int> last_next(4,0);
    last_next = getNextIPAddress(last_add);
    return last_next;
}

bool checklimit(vector<pair<int, int>> grp_cust, int n) {
    int sum = 0;
    for (int i = 0; i < grp_cust.size(); i++) {
        sum += (pow(2, grp_cust[i].second)) * grp_cust[i].first;
    }
    if (sum > pow(2, n)) return false;
    return true;
}

void addressing(vector<pair<int, int>> grp_cust, int n, int giv[4]) {
    vector<int> next = {giv[0],giv[1],giv[2],giv[3]};
    for (int i = 0; i < grp_cust.size(); i++) {
        int t = 32 - ceil(log2(grp_cust[i].second));
        next = IPblocks(next, t);
    }
}

int main() {


    int n;
    int giv[4] = { 0 };
    char slash = '/';
    cout << "Enter IP address (x.y.z.t/n): ";
    cin >> giv[0] >> slash >> giv[1] >> slash >> giv[2] >> slash >> giv[3] >> slash >> n;

    vector<pair<int, int>> grp_cust;  // {Number of Customers,Number of addresses}
    int m;
    cout << "Enter the number of Groups (m) : ";
    cin >> m;
    int c = 0, a = 0;
    for (int i = 0; i < m; i++) {
        cout << "Enter N" << i + 1 << " (Customers) & n" << i + 1 << "address : ";
        cin >> c >> a;
        grp_cust.push_back(make_pair(c, a));
    }

    if (checklimit(grp_cust, n)) {
        addressing(grp_cust, n, giv);
    }
    else {
        cout << "Address block is too small" << endl;
    }

    // IPblocks(giv,n);
    return 0;
}
