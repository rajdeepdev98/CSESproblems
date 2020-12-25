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
#define deb(x) cout<<#x<<"="<<x<<"\n"//debugging
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


using namespace std;
const int MX=(int)(1e6)+5;
int darr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int arr[MX];
lli dp[MX];

//problem solver
void solve(){

    int n,x;
    cin>>n>>x;
    fo1(i,n)cin>>arr[i];
    dp[0]=1;
    fo1(i,x)dp[i]=0;
    // int lim=int(1e7);
   
    lli modno=(lli)(1e9)+7;
    
    fo1(j,n){

        fo(i,x){
            if(i+arr[j]<=x )dp[i+arr[j]]=(dp[i+arr[j]]+dp[i])%modno;
        }
    }
     cout<<dp[x]<<"\n";
    
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



