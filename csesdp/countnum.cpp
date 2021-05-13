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
int arr[20],barr[20];
lli dp[20][10][2];
lli dpp[21];
lli pref[21];
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

    fo1(i,n)fo(j,10)fo(k,2)dp[i][j][k]=-1;
}

lli fnd(int pos,int lst,int n,int ar[],int flag){

        if(n==1)return ar[1]+1;

        
        if(pos>n)return 1ll;
        // if(lst!=-1){if(dp[pos][lst][flag]!=-1)return dp[pos][lst][flag];}
        if(dp[pos][lst][flag]!=-1)return dp[pos][lst][flag];

        int lim=9;
        if(!flag)lim=ar[pos];
        lli res=0;
        fo(i,lim+1){
            if(i==lst)continue;
            if(!flag && i<lim){

                res+=fnd(pos+1,i,n,ar,1);
            }
            else if(!flag && i==lim)res+=fnd(pos+1,i,n,ar,0);
            else if(flag){

                res+=fnd(pos+1,i,n,ar,1);
            }
        }
        if(lst==-1)return res;
        else return dp[pos][lst][flag]=res;
}

//problem solver
void solve(){
    

        string a,b;
        cin>>a>>b;
        int na=a.length(),nb=b.length();
        fo1(i,na)arr[i]=a[i-1]-'0';
        fo1(i,nb)barr[i]=b[i-1]-'0';
        init(nb);
        lli ans=fnd(1,0,nb,barr,0);
        
        ans+=pref[nb-1];
        deb(ans);

        init(na);
        ans-=fnd(1,0,na,arr,0);
        ans-=pref[na-1];
        bool possbl=true;
        fo1(i,na-1){
            if(arr[i]==arr[i+1]){
                possbl=false;
                break;
            }
        }
        if(possbl)ans++;
        cout<<ans<<"\n";
        // arr[1]=0;
        // deb(fnd(1,-1,1,arr,0));
        // deb(pref[0]);
        // deb(pref[2]);



}


int main(){ 
   
    // OJ;

    fast;

    int t;
    // cin>>t;
    t=1;
    dpp[1]=10;
    dpp[2]=81;
    FOR(i,3,18){
        dpp[i]=dpp[i-1]*9ll;
    }
    fo1(i,18)pref[i]=pref[i-1]+dpp[i];
    while(t--){
        solve();

    }
    
    return 0;
}



