#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOW(i, a, b) for(int i=a; i>=b; i--)
#define S(a)  scanf("%d",&a)
#define LS(a) scanf("%lld",&a)
#define DS(a) scanf("%lf",&a)
#define PC(a) printf("Case %d: ",a)
#define P(a) printf("%d\n",a)
#define LP(a)  printf("%lld",a)
#define DP(a) printf("%.04lf",a)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi   first
#define se     second
#define fast std::ios::sync_with_stdio(false),cin.tie(0)
#define init freopen("input.txt","r",stdin)
#define outit freopen("output.txt","w",stdout)
#define INF 0xfffffff
#define gc getchar
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii>  vii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ii>> vvii;

void read(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(; (c>47 && c<58); c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}
inline void write(int x)
{

    register char buffor[35];
    register int i=0;
    do
    {
        buffor[i++]=(x%10)+'0';
        x/=10;
    }
    while(x);
    i--;
    while(i>=0) putchar(buffor[i--]);
    putchar('\n');
}
ll l[302],c[302];
ll dp[302][(1<<9) + 2];
int n,N;
vector<int> pf;
ll solve(int i,int found)
{
    if(found == (1 << N) - 1) return 0;
    if(i == n ) return INF;
    if(dp[i][found] != -1) return dp[i][found];
    ll ans = INF;
    ans = min(ans, solve(i + 1,found));
    int got = 0;
    for(int k = 0 ; k < N; k++)
    {
        if(l[i] % pf[k] != 0)
        {

            got = got | (1 << k);




        }


    }
    ans = min(ans, c[i] + solve(i + 1,found | got));
   return dp[i][found] = ans;
}

int main()
{


    //int t;
//    S(t);
  //  for(int tc=1; tc<=t; tc++)
    {

        S(n);
        for(int i = 0 ; i < n; i++) LS(l[i]);
        for(int i = 0 ; i < n; i++) LS(c[i]);
        ll ans = INF;
        for(int i = 0 ; i < n; i++)
        {

            pf.clear();

            ll s = l[i];
            for(int j = 2; j * j <= s; j++)
            {

                if(s % j == 0)
                {

                    pf.push_back(j);
                    while(s % j == 0)
                    {

                        s/=j;



                    }


                }

            }
            if(s > 1) pf.push_back(s);
            N = pf.size();
            for(int i = 0 ; i <= n; i++)
             for(int j = 0 ;j < (1<< N); j++)
                  dp[i][j] = -1;
            ans = min(ans,c[i] + solve(i + 1,0));


        }

     if(ans == INF) ans = -1;
     printf("%lld\n",ans);
    }

    return 0;

}
