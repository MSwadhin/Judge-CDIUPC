#include<bits/stdc++.h>
using namespace std;

//#define endl        "\n"
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

vector<Point> points;
const int maxval = 200000;

vector<int> numbers[2];


void prin(int n,int r,int c){
    cout<<r<<" "<<c<<" "<<n<<endl;
    random_shuffle(numbers[0].begin(),numbers[0].end());
    random_shuffle(numbers[1].begin(),numbers[1].end());
    long long total = 0;
    FOR(i,n){
        int b = my_rand(1e8,1e9);
        cout<<numbers[0][i]<<" "<<numbers[1][i]<<" "<<b<<endl;
        total += b;
    }
    cerr<<total<<endl;
}

void solve(){
    numbers[0].clear();
    numbers[1].clear();
    int N = 100000,r = (int)2e5, c = (int)2e5;
    FOR(i,N){
        numbers[0].pb(i+1);
        numbers[0].pb(i+(int)1e5+1);
        numbers[1].pb(r);
    }

    cout<<2<<endl;
    prin(N,r,c);
    swap(r,c);
    swap(numbers[0],numbers[1]);
    prin(N,r,c);
}


int main(){


    FOR(i,10){

        int num = 20 + i +1;
        string str = to_string(num);
        string fname = "data/inputs/input" + str + ".txt";
        FILE * ff = freopen(fname.c_str(),"w",stdout);
        int t=1;
    //    cin>>t;
        while(t--){
            solve();
        }
        fclose(ff);
    }
//    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    return 0;
}


/*
54949306165527
55106376486760

*/

