#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define in insert
#define mp make_pair
#define pii pair<int,int>
#define piil pair<lli,lli>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORN(i,a,b) for(int i=a;i>=b;i--)
#define b_pop(x)  __builtin_popcount(x)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie()
#define deb(x) cout<<#x<<"="<<x<<"\n"//debugging
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


using namespace std;
const int MX=(int)(1e6)+5;
int darr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const lli modno=(lli)(1e9)+7;
lli dp[MX][2];


//GCD portion (without Euclids)

template<typename T>
T GCD(T a,T b){
    if(b==0)return a;
    else return GCD(b,a%b);
}


// //adding a graph template
// void ipgraph(int n,int m){

//     int u,v;
//     fo1(i,m){
//         cin>>u>>v;
//         graph[u].pb(v);
//         graph[v].pb(u);
//     }
// }




void init(){

        dp[1][0]=1;
        dp[1][1]=1;
        fo1(i,MX-1){

            // first dp[i+1][0] the unllinked one
            dp[i+1][0]=(4ll*dp[i][0]+dp[i][1])%modno;
            //not ext + both ext + 1 ext
            // not ext=dp[i][0]+dp[i][1]
            //both ext=dp[i][0]
            // one ext=2*dp[i][0]

            // now the linked one dp[i+1][1]
            dp[i+1][1]=(2ll*dp[i][1]+dp[i][0])%modno;
            // =ext+not ext
            // ext=dp[i][1]
            // not ext=dp[i][0]+dp[i][1]

        }
}
//problem solver
void solve(){
    
        lli n;
        cin>>n;
        // vector<vector<lli>>dp(n+1,vector<lli>(2,0));

        // dp[i]no of ways to form 0 to i
        //dp[i][0]ith position is reached by two unlinked tiles
        // dp[i][1]ith position is reached by a linked tile
        // ans=dp[n][0]+dp[n][1];
       
        cout<<(dp[n][0]+dp[n][1])%modno<<"\n";
       

       
       
}


int main(){ 
   
    // OJ;

    fast;

    int t;
    cin>>t;
    // t=1;
    init();

    while(t--){
        solve();

    }
    
    return 0;
}



