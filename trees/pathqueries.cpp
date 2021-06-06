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
lli BIT[MX];
int tin[MX],tout[MX],depth[MX],cnt=1;
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
void update(int node,int val,int n){


        while(node<=n){

            BIT[node]+=val;
            node+=(node&(-node));
        }

}
lli query(int i){

    lli ans=0;
    while(i>0){

        ans+=BIT[i];
        i-=(i&(-i));
    }
    return ans;
}
void dfs(int s=1,int p=0){

    tin[s]=cnt++;
    depth[s]=depth[p]+1;
    for(auto el:graph[s]){

        if(el!=p){
            dfs(el,s);
        }
    }
    tout[s]=cnt;
}




//problem solver
void solve(){
    
    int n,q;
    cin>>n>>q;
    fo1(i,n)cin>>arr[i];
    ipgraph(n,n-1);
    dfs();
    fo1(i,n){

        update(tin[i],arr[i],n);
        update(tout[i],-arr[i],n);
    }
    while(q--){

        int typ,s;
        cin>>typ>>s;
        if(typ==1){

            int x;
            cin>>x;
            update(tin[s],x-arr[s],n);
            update(tout[s],arr[s]-x,n);
            arr[s]=x;
        }
        else{
            cout<<query(tin[s])<<"\n";
        }
    }

    
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



