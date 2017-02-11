/***********Template Starts Here***********/
#include <bits/stdc++.h>

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((vlong)(x).size())
#define NORM(x) if(x>=mod)x-=mod;
#define ODD(x) (((x)&1)==0?(0):(1))

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<pii> vii;
typedef vector<int> vi;

const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
    #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
#else
    #define debug(args...)  // Just strip off all debug tokens
    #define timeStamp
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    if ( x < 0 ) x += m; //modInv is never negative
    return x;
}

inline vlong power ( vlong a, vlong p ) {
    vlong res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) 
    {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}

/***********Template Ends Here***********/


char buf[1001000];

vlong xyz, four;
int mod = 1e9+7;

void precal( vlong len, vlong n ) {
    xyz = len * (n%(mod-1));
    xyz %= mod-1;
    xyz = bigmod( 5, xyz, mod );
    xyz -= 1;
    if ( xyz < 0 ) xyz += mod;

    four = bigmod( 4, mod - 2, mod );
}

vlong g ( int p, int len, vlong n ) 
{
		cout<<"In G"<<endl;
    vlong res = bigmod( 5, p + 1, mod ) * xyz;
    res %= mod;

    vlong temp = bigmod(5,len,mod); 
    temp--; 
    if ( temp < 0 ) temp += mod; 
    NORM(temp);
    temp = bigmod(temp,mod-2,mod);

    res *= temp; 
    res %= mod;
    res -= n;
    res %= mod;
    if ( res < 0 ) res += mod;

    res *= four;
    res %= mod;

    return res;
}

int isSafe( int len ) {
    FOR(i,0,len-1) {
        if ( buf[i] >= '5' && buf[i] <= '9' ) return i;
    }
    return -1;
}

vlong f ( vlong len, vlong n, vlong x ) 
{ ///Gets sum of 5^0+5^1...5^{n*len-x-1}$
   	cout<<"F is called"<<endl;
    n %= mod - 1;
    vlong p = (len * n ) - x; 
    p %= mod - 1;
    p++; 
    p %= (mod-1);
    if ( p < 0 ) p += mod - 1;

    vlong res = bigmod( 5, p, mod );
    res--;
    res *= four;

    res %= mod;
    if ( res < 0 ) res += mod;

    return res;
}

vlong getMod ( int len, vlong n ) { /// Returns S % mod, wher S = X repeated N times
    vlong x = 0;

    FOR(i,0,len-1){
        x *= 10;
        x += (buf[i]-'0');
        x %= mod;
    }

    vlong y = bigmod(10,len,mod);

    vlong res = bigmod(y,n,mod);
    res -= 1;
    if ( res < 0 ) res += mod;
    res *= x;
    res %= mod;

    vlong temp = y - 1; 
    if ( temp < 0 ) temp += mod;
    temp = bigmod ( temp, mod - 2, mod );

    res *= temp;
    res %= mod;

    return res;
}

vlong process ( int len, vlong n ) {

cout<<"four is : "<<four<<" % "<<mod<<endl;
    ///Is it safe?

    vlong res = 0;

    int b = isSafe ( len );

    if ( b == -1 ) {
 //If the number is safe
        vlong last = g(0,len,n);

        ///Needed for O(1) calculation of g(p) from g(p-1)
        vlong add = n % mod * 5 % mod * four % mod;
        vlong sub = n % mod * four % mod;

        res += last * (buf[len-1]-'0');
        res %= mod;

        //debug ( 5*last, res, g(len-1-0, len, n ) );

        ROF(i,0,len-2) 
        {
            last = ( last * 5 ) % mod + add - sub % mod;
            if ( last < 0 ) last += mod;
            //res += (buf[i]-'0') * g ( len-1-i, len, n );
            res += (buf[i]-'0') * last;
            res %= mod;
        }
        res++; ///Cause the actual string itself is responsible
    }
    else {
        ///It's either blocking or some problem

        vlong last = f ( len, n, b + 1 );
        vlong add = 5 * four % mod;
        vlong sub = four;

        res += 5 * last % mod;
        res %= mod;

        ROF(i,0,b-1) {
            int c = buf[i] - '0';

            last = last * 5 % mod + add - sub % mod;
            if ( last < 0 ) last += mod;

            res += c * last;
            res %= mod;
        }

        if ( buf[b] == '9' ) {
            ///Could be Nine String

            bool nine = true;
            FOR(i,b,len-1) {
                if ( buf[i] != '9' ) nine = false;
            }

            if ( nine ) {
                if ( n == 1 || b == 0 ) res++; ///Since single string
            }
        }
    }
    res %= mod;
    cout<<"Res is "<<res<<endl;
    if ( res < 0 ) res += mod;

    return res;
}

void solution() {
    vlong n;
    scanf ( "%s %lld", buf, &n );

    int len = strlen ( buf );

    precal( len, n );

    vlong res = process ( len, n );

    vlong x = getMod( len, n ) + 1;
    x %= mod;
    
		cout<<x<<" - "<<res<<endl;
    res = x - res;
    if ( res < 0 ) res += mod;

    printf ( "%lld\n", res );
}

int main () {

    //freopen("input.txt", "r", stdin );
    //freopen("output00.txt", "w", stdout );

    solution();


    return 0;
}
