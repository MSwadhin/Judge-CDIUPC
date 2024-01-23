#include<bits/stdc++.h>
using namespace std;

#define endl        "\n"
#define LL          long long
#define READ(x)     freopen(x,"r",stdin)
#define WRITE(x)    freopen(x,"w",stdout)
#define BOOST       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb          push_back
#define mem(x,y)    memset(x,y,sizeof x )
#define ch          printf("Came Here!!!!!!!!!!!!!!!\n")
#define deb(x)      cerr<<#x<<" :: "<<x<<" "
#define dnl         cerr<<endl
#define FOR(i,n)    for(int i=0;i<n;i++)
#define cnd         tree[idx]
#define lc          tree[idx*2]
#define rc          tree[idx*2+1]
#define lnd         (2*idx),(b),( (b+e) /2 )
#define rnd         ((2*idx)+1),(((b+e)/2)+1),(e)
#define popcount    __builtin_popcount




const LL        INF = 1LL<<60;
const double    PI = 2.0 * acos(0.0);

typedef pair<int,int>   pii;
typedef pair<LL,LL>     pll;
typedef vector<int>     vi;
typedef vector<LL>      vl;
typedef vector<pii>     vii;
typedef vector<pll>     vll;

//// Including Policy Based DS
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
/////cout<<*X.find_by_order(1)<<endl;
/////cout<<X.order_of_key(-5)<<endl;
//typedef tree<
//pii,
//null_type,
//less<pii>,
//rb_tree_tag,
//tree_order_statistics_node_update>
//ordered_set;

// Grid direction array [4]
int X[4]={0,0,-1,1};
int Y[4]={1,-1,0,0};
// Grid direction array [8]
int X8[8]={0,0,1,-1,-1,1,1,-1};
int Y8[8]={1,-1,0,0,-1,-1,1,1};
// Bishop direction array
int BX[8]={0,0,1,-1,-1,1,1,-1};
int BY[8]={1,-1,0,0,-1,-1,1,1};
// Knight Direction Array
int KX[8] = {1,1,2,2,-1,-1,-2,-2};
int KY[8] = {2,-2,1,-1,2,-2,1,-1};

inline LL modMul(LL a, LL b,LL mod){
    LL ans = 0;
    a = a % mod;
    while (b > 0){
        if ( b % 2 )ans = (ans%mod+ a%mod) % mod;
        a = (a%mod * 2%mod) % mod;
        b /= 2;
    }
    return ans % mod;
}
inline LL power(LL a,LL b,LL mod){
    if(b==0)return 1LL%mod;
    LL x=power( a,b/2,mod );
    x = (x*x) % mod;
    if( b%2==1 )x = (x*a)%mod;
    return x%mod;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
LL  my_rand(LL l, LL r) {
    return uniform_int_distribution<LL>(l, r) (rng);
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
const int mx = 200005;

struct Point{
    int r,c,b;
    Point(){}
    Point(int x,int y,int z){
        r=x,c=y,b=z;
    }
};


bool cmp(const Point &p, const Point &q){
    if( p.r==q.r ){
        return p.c < q.c;
    }
    return p.r < q.r;
}

bool sorted(vector<Point> arr){
    int n = (int)arr.size();
    for(int i=1;i<n;i++){
        if( arr[i].r < arr[i-1].r )return false;
        if( arr[i].c < arr[i-1].c )return false;
    }
    return true;
}

vector<Point> points;

long long tree[4*mx];
void build(int idx,int b,int e){
    cnd = 0;
    if(b!=e){
        build(lnd);
        build(rnd);
    }
}

void update(int idx,int b,int e,int pos,long long val){
    if(b==e and b==pos){
        cnd = max(cnd,val);
        return;
    }
    int mid = (b+e)>>1;
    if( pos <= mid )update(lnd,pos,val);
    else update(rnd,pos,val);
    cnd = max(lc,rc);
}


long long query(int idx,int b,int e,int l,int r){
    if(l>e or r<b)return 0;
    if(l<=b and r>=e)return cnd;
    return max( query(lnd,l,r),query(rnd,l,r) );
}

void solve(){
    int R,C,N;cin>>R>>C>>N;
    points.clear();
    points.resize(N);
    vector<int> ys;
    FOR(i,N){
        cin>>points[i].r;
        cin>>points[i].c;
        cin>>points[i].b;
        ys.pb(points[i].c);
    }
    sort(points.begin(),points.end(),cmp);


    // compression
    int cnt = 0;
    sort(ys.begin(),ys.end());
    map<int,int> mp;
    for(int a:ys){
        if(mp.find(a)==mp.end()){
            mp[a] = ++cnt;
        }
    }
    FOR(i,N){
        points[i].c = mp[ points[i].c ];
    }

    build(1,1,cnt);
    long long ans = 0;
    for(int i=N-1;i>=0;i--){
        int cr = points[i].r,cc = points[i].c;
        long long val = points[i].b;
        long long cur = query(1,1,cnt,cc,cnt);
        long long dp = cur + val;
        update(1,1,cnt,cc,dp);
        ans = max(ans,dp);
    }
    cout<<ans<<endl;



}



int main(){
    READ("data/inputs/input1.txt");
    WRITE("data/outputs/output1.txt");
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cerr<<t<<"\n";
        solve();
    }
    return 0;
}


