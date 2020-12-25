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
const int MX=(int)(1e5)+5;
int darr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
lli arr[MX];
lli modno=(lli)(1e9)+7;
lli dp[105][2];
lli ans=1;
int n,m;


lli fnd(int v1,int v2,int diff,int flag){
     fo(j,m+1){
            dp[j][0]=0;
            dp[j][1]=0;
        }
        // dp[v1]=1;
        dp[v1][0]=1;
        FOR(j,1,diff){

            fo1(k,m){
                if(dp[k][0]!=0){

                    if(k+1<=m)dp[k+1][1]=(dp[k+1][1]+dp[k][0])%modno;
                    if(k-1>=0)dp[k-1][1]=(dp[k-1][1]+dp[k][0])%modno;
                    dp[k][1]=(dp[k][1]+dp[k][0])%modno;

               
            }
            }
            fo1(k,m){
                dp[k][0]=dp[k][1];
                dp[k][1]=0;
                // I am not sure if what I'm doing is actually right
            }

        }
        
        if(flag==0)return dp[v2][0];
        else{

            lli temp=0;
            fo1(i,m)temp=(dp[i][0]+temp)%modno;
            return temp;

        }



}

//problem solver
void solve(){
    
    
    cin>>n>>m;
    fo1(i,n)cin>>arr[i];
  
    lli last=1;
    vector<int>vec;
    fo1(i,n)if(arr[i]>0)vec.pb(i);
    ans=1;
    // cout<<vec.size()<<"\n";
    // my solution might not have been the most elegant but 
    // I am glad that it is 100 percent mine!!
    for(int i=1;i<vec.size();i++){


        int pos1=vec[i];
        int pos2=vec[i-1];
        int diff=abs(pos1-pos2);
        if(abs(pos2-pos1)==1){
            if(abs(arr[pos1]-arr[pos2])>1)ans*=0;
            continue;
        }
        int val1=arr[pos1];
        int val2=arr[pos2];
        int v1=min(val1,val2);
        int v2=max(val1,val2);

       
        ans=(ans*fnd(v1,v2,diff,0))%modno;
        

    }
    if(vec.size()==0){
        lli temp=0;
        fo1(i,m){
            temp=(temp+fnd(i,i,n-1,1))%modno;
        }
        ans=temp;
        // deb(ans);
    }else{
       if(arr[1]==0){

           ans=(ans*fnd(arr[vec[0]],1,vec[0]-1,1))%modno;
       }
       if(arr[n]==0){

           ans=(ans*fnd(arr[vec.back()],1,n-vec.back(),1))%modno;
       }

    }
    
    cout<<ans<<"\n";

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



