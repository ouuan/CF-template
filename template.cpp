#ifndef OUUAN
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#endif
#include <bits/stdc++.h>

#define int ll
// #define FAST_IOSTREAM 1

#define For(i, l, r) for (int i = (l), i##end = (r); i <= i##end; ++i)
#define FOR(i, r, l) for (int i = (r), i##end = (l); i >= i##end; --i)
#define SON(i, u) for (int i = head[u]; i; i = nxt[i])
#define BE(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pq priority_queue
#define min minOfDifferentTypes
#define isinf(x) (x >= INF ? -1 : x)
#define y1 why_is_there_a_function_called_y1

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vpii;
typedef long double ld;

const double inf = 1e121;
const double eps = 1e-10;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r) { int out = rng() % (r - l + 1) + l; return out >= l ? out : out + r - l + 1; }

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + "," + to_string(get<4>(p)) + ")";
}

void debug_out() {
    cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

template <typename T>
struct is_pair { static const bool value = false; };
template <typename T, typename U>
struct is_pair<std::pair<T, U> > { static const bool value = true; };

#ifdef OUUAN
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#ifdef int
const int INF = 0x3f3f3f3f3f3f3f3fll;
#else
const int INF = 0x3f3f3f3f;
#endif

#ifdef FAST_IOSTREAM
#define br cout << '\n'
#define sp cout << ' '
#define fl cout.flush()
ll read()
{
    ll x;
    cin >> x;
    return x;
}
template <typename T>
void read(T& x) { cin >> x; }
template <typename T>
void write(const T& x) { cout << x; }
#else
#define br putchar('\n')
#define sp putchar(' ')
#define fl fflush(stdout)
template <typename T>
typename enable_if<!is_integral<T>::value && !is_pair<T>::value, void>::type read(T& x) { cin >> x; }
ll read()
{
    char c;
    ll out = 0, f = 1;
    for (c = getchar(); !isdigit(c) && c != '-'; c = getchar());
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    for (; isdigit(c); c = getchar()) out = (out << 3) + (out << 1) + c - '0';
    return out * f;
}
template <typename T>
typename enable_if<is_integral<T>::value, T>::type read(T& x)
{
    char c;
    T f = 1;
    x = 0;
    for (c = getchar(); !isdigit(c) && c != '-'; c = getchar());
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    return x *= f;
}
char read(char& x)
{
    for (x = getchar(); isspace(x); x = getchar());
    return x;
}
double read(double& x)
{
    scanf("%lf", &x);
    return x;
}
ld read(ld& x)
{
    scanf("%Lf", &x);
    return x;
}
template <typename T>
typename enable_if<!is_integral<T>::value && !is_pair<T>::value, void>::type write(const T& x) { cout << x; }
template <typename T>
typename enable_if<is_integral<T>::value, void>::type write(const T& x)
{
    if (x < 0)
    {
        putchar('-');
        write(-x);
        return;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
void write(const char& x) { putchar(x); }
void write(const double& x) { printf("%.10lf", x); }
void write(const ld& x) { printf("%.10Lf", x); }
#endif
template <typename T>
typename enable_if<is_pair<T>::value, void>::type read(T& x)
{
    read(x.fi);
    read(x.se);
}
template <typename T>
typename enable_if<is_pair<T>::value, void>::type write(const T& x)
{
    write(x.fi);
    sp;
    write(x.se);
}
template <typename T, typename... Args>
void read(T& x, Args&... args)
{
    read(x);
    read(args...);
}
template <typename OutputIt, typename = typename enable_if<is_same<output_iterator_tag, typename iterator_traits<OutputIt>::iterator_category>::value ||
(is_base_of<forward_iterator_tag, typename iterator_traits<OutputIt>::iterator_category>::value && !is_const<OutputIt>::value)>::type>
void read(OutputIt __first, OutputIt __last) { for (; __first != __last; ++__first) read(*__first); }
template <typename InputIt, typename = typename enable_if<is_base_of<input_iterator_tag, typename iterator_traits<InputIt>::iterator_category>::value>::type>
void wts(InputIt __first, InputIt __last)
{
    bool isFirst = true;
    for (; __first != __last; ++__first)
    {
        if (isFirst) isFirst = false;
        else sp;
        write(*__first);
    }
    br;
}
template <typename InputIt, typename = typename enable_if<is_base_of<input_iterator_tag, typename iterator_traits<InputIt>::iterator_category>::value>::type>
void wtb(InputIt __first, InputIt __last)
{
    for (; __first != __last; ++__first)
    {
        write(*__first);
        br;
    }
}
template <typename T>
void wts(const T& x)
{
    write(x);
    sp;
}
template <typename T>
void wtb(const T& x)
{
    write(x);
    br;
}
template <typename T>
void wte(const T& x)
{
    write(x);
    exit(0);
}
template <typename T, typename... Args>
void wts(const T& x, Args... args)
{
    wts(x);
    wts(args...);
}
template <typename T, typename... Args>
void wtb(const T& x, Args... args)
{
    wts(x);
    wtb(args...);
}
template <typename T, typename... Args>
void wte(const T& x, Args... args)
{
    wts(x);
    wte(args...);
}

template <typename T1, typename T2>
inline bool up(T1& x, const T2& y) { return x < y ? x = y, 1 : 0; }
template <typename T1, typename T2>
inline bool dn(T1& x, const T2& y) { return y < x ? x = y, 1 : 0; }
template <typename T>
inline bool inRange(const T& x, const T& l, const T& r) { return !(x < l) && !(r < x); }
template <typename T1, typename T2>
inline auto minOfDifferentTypes(const T1 &x, const T2 &y)->decltype(x < y ? x : y) { return x < y ? x : y; }



signed main()
{
#ifdef FAST_IOSTREAM
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#endif
	
	
	
	return 0;
}
