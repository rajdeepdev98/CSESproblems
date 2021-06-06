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
int no=0;
int primes[105];
int arr[10],barr[10];
lli dp[10][102][2];
vector<int>graph[MX];

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



void init(int n){
    fo1(i,n)fo(j,101)fo(k,2)dp[i][j][k]=-1;
}
int fnd(int pos,int sum,int n,int ar[],int flag){

    if(n==1 && ar[1]==0)return 0;
    if(pos>n)return primes[sum];
    if(dp[pos][sum][flag]!=-1)return dp[pos][sum][flag];

    int lim=9;
    if(!flag)lim=ar[pos];
    int res=0;
    fo(i,lim+1){

        if(!flag && i<lim){

            res+=fnd(pos+1,sum+i,n,ar,1);

        }
        else if(!flag && i==lim)res+=fnd(pos+1,sum+i,n,ar,0);
        else if(flag){
            res+=fnd(pos+1,sum+i,n,ar,1);
        }
    }
    return dp[pos][sum][flag]=res;
}


//problem solver
void solve(){
    

        
        string a ,b;
        cin>>a>>b;
        int na=a.length(),nb=b.length();
        fo1(i,na)arr[i]=a[i-1]-'0';
        fo1(i,nb)barr[i]=b[i-1]-'0';
        init(na);
        
        int ans=-fnd(1,0,na,arr,0);
        init(nb);
        ans+=fnd(1,0,nb,barr,0);
        int sm=0;
        fo1(i,na)sm+=arr[i];
        if(primes[sm])ans++;
        cout<<ans<<"\n";
        // arr[1]=1,arr[2]=9;
        // init(2);
        // deb(fnd(1,0,2,arr,0));




}
void sieve(){

    vector<bool>isprime(102,true);
    isprime[1]=false;
    for(int i=2;i*2<=101;i++)isprime[i*2]=false;

    for(int i=3;i<=101;i+=2){

        if(isprime[i]){
            for(int j=i;j*i<=101;j++){

                isprime[i*j]=false;
            }
        }
    }
    FOR(i,2,101){
        if(isprime[i])primes[i]=1;
    }
} 

int main(){ 
   
    // OJ;

    fast;

    int t;
    cin>>t;
    
    sieve();
    // fo1(i,20){
    //     if(primes[i])cout<<i<<" ";
    // }
    // cout<<"\n";

    while(t--){
        solve();

    }
    
    return 0;
}



