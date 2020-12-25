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
const int MX=(int)(5e3)+5;
int darr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int dp[MX][MX];
//problem solver
void solve(){
    
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n=s1.length();
    int m=s2.length();
    fo1(i,n)dp[i][0]=i;
    fo1(i,m)dp[0][i]=i;
    fo1(i,n){

        fo1(j,m){

            if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];
            else{


                int temp=min(dp[i-1][j-1],dp[i-1][j]);
                temp=min(temp,dp[i][j-1]);
                dp[i][j]=temp+1;
            }
        }
    }
    cout<<dp[n][m]<<"\n";
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



