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
lli arr[MX];
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
        fo1(i,n)cin>>arr[i];
        sort(arr+1,arr+n+1);
        // int pos=n/2+1;
        // lli ans=0;
        // fo1(i,n)ans+=abs(arr[i]-arr[pos]);
        // cout<<ans<<"\n";
        auto cmpcost=[&](lli val){

            lli cost=0;
            fo1(i,n)cost+=abs(arr[i]-val);
            return cost;
        };

        // lets use median method
        lli l=arr[1],r=arr[n];
        while(r-l>2){

            lli mid1=l+(r-l)/3;
            lli mid2=r-(r-l)/3;

            lli cost1=cmpcost(mid1);
            lli cost2=cmpcost(mid2);
            if(cost1<cost2){
                r=mid2;
            }
            else l=mid1;

        }
        lli ans2=cmpcost(l);
        FOR(i,(int)(l),(int)(r)){
            amin(ans2,cmpcost(i));
        }
        cout<<ans2<<"\n";


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



