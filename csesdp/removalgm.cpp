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
const int MX=(int)(5e3)+5;
int darr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
lli  arr[MX];
lli dp[MX][MX][2];
lli prefsm[MX];
// I think I am not basing the decisions of the first player based on the decisions of the second player
// thats why the problem is arising

//problem solver
void solve(){

    int n;
    cin>>n;
    fo1(i,n)cin>>arr[i];
    fo1(i,n)prefsm[i]=prefsm[i-1]+arr[i];
    int diff=n-1;
    FORN(i,n,1){
        
        // thats the thing(dp[i][j])wont have values everywhere
        if(diff%2==0)dp[i][i][0]=arr[i];
        else dp[i][i][1]=arr[i];
        
        FOR(j,i+1,n){
           
            fo(k,2){
                //Case 1 I take i
               lli temp=prefsm[j]-prefsm[i-1];
               dp[i][j][k]=temp-min(dp[i+1][j][1-k],dp[i][j-1][1-k]);
            }
           

            
           
            
        }
    }
    cout<<dp[1][n][0]<<"\n";

    
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



