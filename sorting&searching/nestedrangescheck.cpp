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
 




//problem solver
void solve(){
    
    int n;
    cin>>n;
    vector<pair<pii,int>>vec,vec2;
    fo1(i,n){

        int u,v;
        cin>>u>>v;
        vec.pb(mp(mp(u,v),i));
        vec2.pb(mp(mp(v,u),i));
    }
   
    
    
    auto cmp=[&](pair<pii,int> &a,pair<pii,int> &b)->bool{

        if(a.ff.ff<b.ff.ff)return true;
        else if(b.ff.ff<a.ff.ff)return false;
        else return a.ff.ss>b.ff.ss;

    };
    sort(all(vec),cmp);
    sort(all(vec2),cmp);
    vector<int>ans1(n+1,0),ans2(n+1,0);
    int mn1=INT_MAX;
    // for(int i=n-1;i>=0;i--){
    //     int v=vec2[i].ff.ff,u=vec2[i].ff.ss,ind=vec2[i].ss;
    //     if(mn1<=u)ans2[ind]=1;
    //     amin(mn1,u);
    // }
    int mn=INT_MAX;
    int mx1=0;
    fo(i,n){

        int u=vec[i].ff.ff,v=vec[i].ff.ss,ind=vec[i].ss;
        if(mx1>=v)ans2[ind]=1;
        amax(mx1,v);

    }
    for(int i=n-1;i>=0;i--){
        int u=vec[i].ff.ff,v=vec[i].ff.ss,ind=vec[i].ss;
        if(mn<=v)ans1[ind]=1;
        amin(mn,v);
    }
    fo1(i,n)cout<<ans1[i]<<" ";
    cout<<"\n";
    fo1(i,n)cout<<ans2[i]<<" ";
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



