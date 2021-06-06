#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define in insert
#define mp make_pair
#define pii pair<int,int>
#define piil pair<lli,lli>
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
#define trav(a,x) for (auto& a: x)
#define deb(x) cout<<#x<<"="<<x<<"\n"//debugging
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


using namespace std;
const int MX=(int)(2e5)+5;
int darr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int arr[MX];
vector<int>graph[MX];
vector<pii>edges;
int cnt;
int dp[MX][2];

// Utility functions
void setPrec() { cout << fixed << setprecision(15); }
template<typename A>
A Max(A a,A b){
    return max(a,b);
}
template<typename A,typename... Args>
A Max(A a,A b,Args... args){
    return Max(Max(a,b),args...);
}
template<typename A>
void amin(A& a, A b){
    a=min(a,b);
}
template<typename A>
void amax(A& a, A b){
    a=max(a,b);
}

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



void dfs(int s,int p){

    for(auto el:graph[s]){
        if(el!=p){

            dfs(el,s);
            dp[s][0]+=(max(dp[el][1],dp[el][0]));
        }
    }
    for(auto el:graph[s]){
        
        if(el!=p){

            amax(dp[s][1],dp[el][0]+1+dp[s][0]-max(dp[el][0],dp[el][1]));
        }
    }
}

//problem solver
void solve(){
    

        int n;
        cin>>n;
        edges.clear();
        fo1(i,n-1){
            int u,v;
            cin>>u>>v;
            edges.pb(mp(u,v));
            graph[u].pb(v);
            graph[v].pb(u);
        }
        if(n<=3){
            cout<<(n>1?1:0)<<"\n";
            return;
        }
        cnt=0;
        dfs(1,0);
        cout<<max(dp[1][0],dp[1][1])<<"\n";
    
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



