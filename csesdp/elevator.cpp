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
const int MX=(int)(2e5)+5;
int darr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
lli arr[MX];
vector<int>graph[MX];

//GCD portion (without Euclids)

template<typename T>
T GCD(T a,T b){
    if(b==0)return a;
    else return GCD(b,a%b);
}


//adding a graph template
void ipgraph(int n,int m){

    int u,v;
    fo1(i,m){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
}





//problem solver
void solve(){
    
    lli n,x;
    cin>>n>>x;
    fo1(i,n)cin>>arr[i];
    vector<vector<lli>>dp(1ll<<n,vector<lli>(2,n+1));
    lli lim=(1ll<<n)-1;
    dp[0][0]=0;
    dp[0][1]=0;
    fo(i,lim+1)dp[i][1]=0;


    fo(i,lim){

        fo(j,n){
            if(!(i &(1<<j))){
                if(dp[i][1]-arr[j+1]>=0){
                    if(dp[i|(1<<j)][0]>dp[i][0]){
                       dp[i|(1<<j)][0]=dp[i][0];
                       dp[i|(1<<j)][1]=dp[i][1]-arr[j+1];
                    }
                    else if(dp[i|(1<<j)][0]==dp[i][0]){
                       dp[i|(1<<j)][1]=max(dp[i|(1<<j)][1],dp[i][1]-arr[j+1]);
                    }
                }
                else{

                    if(dp[i|(1<<j)][0]>dp[i][0] +1){
                        dp[i|(1<<j)][0]=dp[i][0]+1;
                        dp[i|(1<<j)][1]=x-arr[j+1];
                    }
                    else if(dp[i|(1<<j)][0]==dp[i][0]+1){

                        dp[i|(1<<j)][1]=max(dp[i|(1<<j)][1],x-arr[j+1]);
                    }
                }
            }
        }
        
    }
    cout<<dp[lim][0]<<"\n";
}


int main(){ 
   
    // OJ;

    fast;

    int t;
    // cin>>t;
    t=1;

    while(t--){
        solve();

    }
    
    return 0;
}



