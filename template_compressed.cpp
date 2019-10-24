																																				#ifndef OUUAN
																																				#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
																																				#endif
																																				#include<bits/stdc++.h>

#define int LoveLive
//#define FAST_IOSTREAM 1

																																				#define For(i,l,r)for(int i=(l),i##end=(r);i<=i##end;++i)
																																				#define FOR(i,r,l)for(int i=(r),i##end=(l);i>=i##end;--i)
																																				#define SON(i,u)for(int i=head[u];i;i=nxt[i])
																																				#define ms(a,x)memset(a,x,sizeof(a))
																																				#define fi first
																																				#define se second
																																				#define pb emplace_back
																																				#define pq priority_queue
																																				#define isinf(x)(x>=INF?-1:x)
																																				#define y1 why_is_there_a_function_called_y1
																																				#define DEBUG(x)cerr<<(#x)<<":"<<x<<endl
																																				using namespace std;typedef long long LoveLive;typedef pair<int,int>pii;typedef vector<int>vi;
																																				#ifdef int
																																				const int INF=0x3f3f3f3f3f3f3f3fll;
																																				#else
																																				const int INF=0x3f3f3f3f;typedef long long ll;
																																				#endif
																																				const double eps=1e-9;mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());int randint(int l,int r){int out=rng()%(r-l+1)+l;return out>=l?out:out+r-l+1;}
																																				#ifdef FAST_IOSTREAM
																																				#define br cout<<'\n'
																																				#define sp cout<<' '
																																				long long read(){long long x;cin>>x;return x;}template<typename T>void read(T&x){cin>>x;}template<typename T>void write(const T&x){cout<<x;}
																																				#else
																																				#define br putchar('\n')
																																				#define sp putchar(' ')
																																				template<typename T>typename enable_if<!is_integral<T>::value,void>::type read(T&x){cin>>x;}long long read(){char c;long long out=0,f=1;for(c=getchar();!isdigit(c)&&c!='-';c=getchar());if(c=='-'){f=-1;c=getchar();}for(;isdigit(c);c=getchar())out=(out<<3)+(out<<1)+c-'0';return out*f;}template<typename T>typename enable_if<is_integral<T>::value,T>::type read(T&x){char c;T f=1;x=0;for(c=getchar();!isdigit(c)&&c!='-';c=getchar());if(c=='-'){f=-1;c=getchar();}for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';return x*=f;}char read(char&x){for(x=getchar();isspace(x);x=getchar());return x;}double read(double&x){scanf("%lf",&x);return x;}template<typename T>typename enable_if<!is_integral<T>::value,void>::type write(const T&x){cout<<x;}template<typename T>typename enable_if<is_integral<T>::value,void>::type write(const T&x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}void write(const char&x){putchar(x);}void write(const double&x){printf("%.10lf",x);}
																																				#endif
																																				template<typename T,typename...Args>void read(T&x,Args&...args){read(x);read(args...);}template<typename OutputIt,typename=typename enable_if<is_same<output_iterator_tag,typename iterator_traits<OutputIt>::iterator_category>::value||(is_base_of<forward_iterator_tag,typename iterator_traits<OutputIt>::iterator_category>::value&&!is_const<OutputIt>::value)>::type>void read(OutputIt __first,OutputIt __last){for(;__first!=__last;++__first)read(*__first);}template<typename InputIt,typename=typename enable_if<is_base_of<input_iterator_tag,typename iterator_traits<InputIt>::iterator_category>::value>::type>void wts(InputIt __first,InputIt __last){bool isFirst=true;for(;__first!=__last;++__first){if(isFirst)isFirst=false;else sp;write(*__first);}br;}template<typename InputIt,typename=typename enable_if<is_base_of<input_iterator_tag,typename iterator_traits<InputIt>::iterator_category>::value>::type>void wtb(InputIt __first,InputIt __last){for(;__first!=__last;++__first){write(*__first);br;}}template<typename T>void wts(const T&x){write(x);sp;}template<typename T>void wtb(const T&x){write(x);br;}template<typename T>void wte(const T&x){write(x);exit(0);}template<typename T,typename...Args>void wts(const T&x,Args...args){wts(x);wts(args...);}template<typename T,typename...Args>void wtb(const T&x,Args...args){wts(x);wtb(args...);}template<typename T,typename...Args>void wte(const T&x,Args...args){wts(x);wte(args...);}template<typename T>inline bool up(T&x,const T&y){return x<y?x=y,1:0;}template<typename T>inline bool dn(T&x,const T&y){return y<x?x=y,1:0;}template<typename valueType,typename tagType>class segmentTreeNode{public:int id,left,right;valueType val;tagType tag;};template<typename valueType, typename tagType, valueType(*merge)(valueType,valueType), void(*update)(segmentTreeNode<valueType,tagType>&,tagType)>class segmentTree{private:int leftRange,rightRange;std::vector<segmentTreeNode<valueType,tagType>>nodes;valueType zero;void pushup(int cur){nodes[cur].val=merge(nodes[cur<<1].val,nodes[cur<<1|1].val);}void pushdown(int cur){update(nodes[cur<<1],nodes[cur].tag);update(nodes[cur<<1|1],nodes[cur].tag);nodes[cur].tag=0;}void build(int cur,int l,int r,const std::vector<valueType>&initValue){nodes[cur].id=cur;nodes[cur].left=l;nodes[cur].right=r;nodes[cur].tag=0;if(l==r-1)nodes[cur].val=initValue[l-leftRange];else{build(cur<<1,l,(l+r)>>1,initValue);build(cur<<1|1,(l+r)>>1,r,initValue);pushup(cur);}}void init(const std::vector<valueType>&_initValue,const valueType&_zero){zero=_zero;nodes.resize((rightRange-leftRange)<<2);build(1,leftRange,rightRange,_initValue);}void modify(int cur,int l,int r,int L,int R,const tagType&tag){if(l>=R||r<=L)return;if(L<=l&&r<=R)update(nodes[cur],tag);else{pushdown(cur);modify(cur<<1,l,(l+r)>>1,L,R,tag);modify(cur<<1|1,(l+r)>>1,r,L,R,tag);pushup(cur);}}valueType query(int cur,int l,int r,int L,int R){if(l>=R||r<=L)return zero;if(L<=l&&r<=R)return nodes[cur].val;pushdown(cur);return merge(query(cur<<1,l,(l+r)>>1,L,R), query(cur<<1|1,(l+r)>>1,r,L,R));}public:segmentTree(){}segmentTree(int _leftRange,int _rightRange,const std::vector<valueType>&_initValue,const valueType&_zero){leftRange=_leftRange;rightRange=_rightRange;init(_initValue,_zero);}segmentTree(int size,const std::vector<valueType>&_initValue,const valueType&_zero){leftRange=1;rightRange=size+1;init(_initValue,_zero);}void modify(int l,int r,const tagType&tag){modify(1,leftRange,rightRange,l,r,tag);}void modify(int p,const tagType&tag){modify(p,p+1,tag);}valueType query(int l,int r){return query(1,leftRange,rightRange,l,r);}valueType query(int p){return query(p,p+1);}};class maxFlow{private:typedef long long ll;std::queue<int>q;std::vector<int>head,cur,nxt,to,dep;std::vector<ll>cap;public:maxFlow(int _n=0){init(_n);}void init(int _n){head.clear();head.resize(_n+1,0);nxt.resize(2);to.resize(2);cap.resize(2);}void init(){init(head.size()-1);}void add(int u,int v,ll w){nxt.push_back(head[u]);head[u]=to.size();to.push_back(v);cap.push_back(w);}void Add(int u,int v,ll w){add(u,v,w);add(v,u,0);}void del(int x){cap[x<<1]=cap[x<<1|1]=0;}bool bfs(int s,int t){dep.clear();dep.resize(head.size(),-1);dep[s]=0;q.push(s);while(!q.empty()){int u=q.front();q.pop();for(int i=head[u];i;i=nxt[i]){int v=to[i];ll w=cap[i];if(w>0&&dep[v]==-1){dep[v]=dep[u]+1;q.push(v);}}}return ~dep[t];}ll dfs(int u,ll flow,int t){if(dep[u]==dep[t])return u==t?flow:0;ll out=0;for(int&i=cur[u];i;i=nxt[i]){int v=to[i];ll w=cap[i];if(w>0&&dep[v]==dep[u]+1){ll f=dfs(v,std::min(w,flow-out),t);cap[i]-=f;cap[i ^ 1]+=f;out+=f;if(out==flow)return out;}}return out;}ll maxflow(int s,int t){ll out=0;while(bfs(s,t)){cur=head;out+=dfs(s,0x7fffffffffffffffll,t);}return out;}ll getflow(int x)const{return cap[x<<1|1];}};struct customHash{static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x ^(x>>30))*0xbf58476d1ce4e5b9;x=(x ^(x>>27))*0x94d049bb133111eb;return x ^(x>>31);}size_t operator()(uint64_t x)const{static const uint64_t FIXED_RANDOM=rng();return splitmix64(x+FIXED_RANDOM);}};

const int N = 1000010;
const int mod = 1000000007;



signed main()
{
#ifdef FAST_IOSTREAM
    cin.sync_with_stdio(false);
    cin.tie(0);
#endif
    
    
    
    return 0;
}
