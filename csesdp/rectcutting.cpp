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
int dp[505][505];

//problem solver
void solve(){

    int a,b;
    cin>>a>>b;
    int ans=0;
    int v1=max(a,b);
    fo(i,v1)fo(j,v1)dp[i][j]=int(1e8);
    int lim=int(1e8);
    dp[1][1]=0;
    fo1(i,500){

        fo1(j,500){
            if(i==j){
                dp[i][j]=0;
                continue;
            }

           int temp=lim;
           FOR(k,1,i-1){

               temp=min(temp,dp[k][j]+dp[i-k][j]);
           }
           FOR(k,1,j-1){
               temp=min(temp,dp[i][k]+dp[i][j-k]);
           }
           dp[i][j]=temp+1;
        }
    }
    cout<<dp[a][b]<<"\n";
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



