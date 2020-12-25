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
const int MX=(int)(1e3)+5;
int darr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int arr[MX][MX];
lli dp[MX][MX];
const lli modno=(lli)(1e9)+7;


//problem solver
void solve(){
    
    int n;
    cin>>n;
    string s;
    fo1(i,n){
        cin>>s;
        fo(j,n){

            if(s[j]=='*'){
                arr[i][j+1]=1;
            }
        }

    }
    if(arr[1][1]==1 || arr[n][n]==1){
        cout<<0<<"\n";
        return;
    }
    dp[1][1]=1;
    fo1(i,n){

        fo1(j,n){

            if(dp[i][j]!=0 && arr[i][j]!=1){
                if(i+1<=n && arr[i+1][j]!=1)dp[i+1][j]=(dp[i+1][j]+dp[i][j])%modno;
                if(j+1<=n && arr[i][j+1]!=1)dp[i][j+1]=(dp[i][j+1]+dp[i][j])%modno;
            }
        }
    }
    cout<<dp[n][n]<<"\n";
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



