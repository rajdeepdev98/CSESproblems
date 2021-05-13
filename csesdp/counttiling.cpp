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
int arr[MX];
vector<int>graph[MX];
lli modno=1e9+7;
lli dp[1050][1050];
int n,m;

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

void solve2(int x=0,int y=0,int mask=0,int next_mask=0){

    if(x==m)return;

    if(y>=n){
        (dp[x+1][next_mask]+=dp[x][mask])%=modno;
    }
    else{

        if(mask & (1<<y))solve2(x,y+1,mask,next_mask);
        else{

            solve2(x,y+1,mask,(next_mask | (1<<y)));
            if(y+1<n && !(mask & (1<<(y+1)))){
                solve2(x,y+2,mask,next_mask);
            }
        }
    }

}



//problem solver
void solve(){
    

        // int n,m;
        cin>>n>>m;
        int lim=1<<n;
        dp[0][0]=1;
        fo(i,m){

            fo(j,1<<n){

                solve2(i,0,j,0);
            }
        }
        cout<<dp[m][0];
        
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



