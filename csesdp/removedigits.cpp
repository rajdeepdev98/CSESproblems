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
int dp[MX];
 
void put_digits(int val,set<int>&st){

    while(val!=0){
        int temp=val%10;
        if(temp!=0)st.in(temp);
        val/=10;
    }
} 
//problem solver
void solve(){
    
        int n;
        cin>>n;
        dp[n]=0;
        fo(i,n)dp[i]=int(1e7);
        int lim=int(1e7);
        FORN(i,n,1){

        

            if(dp[i]!=lim){

                set<int>st;
                put_digits(i,st);
                for(auto el:st){
                    if(i-el>=0){
                        dp[i-el]=min(dp[i-el],dp[i]+1);
                    }
                }
               
            }

        }
        cout<<dp[0]<<"\n";
        // fo(i,28)cout<<dp[i]<<" "<<i<<"\n";
        // cout<<"\n";

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



