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
vector<pii>paths;
int dis[MX],up[MX][20], ans[MX];

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
    
    dis[s]=dis[p]+1;
    up[s][0]=p;
    
    
    for(int i=1;i<20;i++){

        up[s][i]=up[up[s][i-1]][i-1];//binary lifting

    }
    for(auto el:graph[s]){
        if(el!=p){

            dfs(el,s);
        }
    }
    




}
int LCA(int u,int v){

    if(dis[u]<dis[v]){
        int temp=dis[v]-dis[u];
        for(int i=0;i<20;i++){
            if(temp &(1<<i))v=up[v][i];
        }
    }
    else if(dis[v]<dis[u]){

        int temp=dis[u]-dis[v];
        for(int i=0;i<20;i++){
            if(temp &(1<<i))u=up[u][i];

        }
    }
    if(u==v)return u;
    for(int i=19;i>=0;i--){

        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}

int dfs2(int s,int p){

    for(auto el:graph[s]){

        if(el!=p){
            arr[s]+=dfs2(el,s);
        }
    }
    return arr[s];

}

void precom(){

    for(auto el:paths){

        int u=el.ff,v=el.ss;
        int lc=LCA(u,v);
        arr[u]++;
        arr[v]++;
        arr[lc]--;
        if(lc!=1){
            arr[up[lc][0]]--;
        }
    }
    
    
}
//problem solver
void solve(){
    
    int n,m;
    cin>>n>>m;
    ipgraph(n,n-1);
    fo1(i,m){

        int u,v;
        cin>>u>>v;
        paths.pb(mp(u,v));
    }
    dfs(1,0);
    precom();
    dfs2(1,0);
    // fo1(i,n)cout<<en[i]<<" ";
    // cout<<"\n";
    fo1(i,n)cout<<arr[i]<<" ";
    cout<<"\n";


    
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



