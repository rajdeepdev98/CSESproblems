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
lli dp[20][10][2][2];
// lli dpp[21];
// lli pref[21];
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

    fo1(i,n)fo(j,10)fo(k,2)fo(l,2)dp[i][j][k][l]=-1;
}

lli fnd(int pos,int last,int n,int ar[],int lead,int flag){ 

    // if(pos==3 && last==1 && lead==0)cout<<"lll\n";
    if(pos>n)return 1ll;
    // if(n==1)return (lli) (ar[1]+1);
    // if(n==1)return ar[1]+1;
    if(last!=-1){if(dp[pos][last][lead][flag]!=-1)return dp[pos][last][lead][flag];}

    int lim=9;
    lli res=0;
    if(flag)lim=ar[pos];
    // actually I want a generalised solution
    // if(pos==2){
    //     deb(flag);
    //     deb(lim);
    //     if(lim==1)deb(lead);
    // }

    fo(i,lim+1){
            if(last==i &&(lead!=1)){

                continue;
            }
            
            res+=fnd(pos+1,i,n,ar,(int)(lead && (i==0)),(int)(flag && (i==lim)));
            // if(pos==1 && i==0){
            //     int lim3=lim;
            //     // deb(lim3);
            //     // deb(res);
            // }
    }
    // if(pos==2 && lim==1)deb(res);
    // if(pos==1){
    //     int lim2=lim;
    //     // deb(lim2);
    //     // deb(res);
    // }
    if(last!=-1)return dp[pos][last][lead][flag]=res;
    else return res;
}

//problem solver
void solve(){
    

        string a,b;
        cin>>a>>b;
        int na=a.length(),nb=b.length();
        fo1(i,na)arr[i]=a[i-1]-'0';
        fo1(i,nb)barr[i]=b[i-1]-'0';
        // deb(nb),deb(na);
        init(nb);
        lli ans=fnd(1,-1,nb,barr,1,1);
        // deb(ans); 
        // deb(dp[2][1][0][1]);
        // ans+=pref[nb-1];
        init(na);
        ans-=fnd(1,-1,na,arr,1,1);
        // ans-=pref[na-1];
        bool possbl=true;
        fo1(i,na-1){
            if(arr[i]==arr[i+1]){
                possbl=false;
                break;
            }
        }
        // deb(ans);
        if(possbl)ans++;
        cout<<ans<<"\n";
        // arr[3]=9;
        // arr[2]=0;
        // arr[1]=1;
        // init(3);
        // deb(fnd(1,-1,3,arr,0,0));
        // arr[1]=0;
        // init(1);
        // deb(fnd(1,-1,1,arr,0,0));
        // deb(pref[0]);
        // deb(pref[2]);
        // cou



}


int main(){ 
   
    // OJ;

    fast;

    int t;
    // cin>>t;
    t=1;
    // dpp[1]=10;
    // dpp[2]=81;
    // FOR(i,3,18){
    //     dpp[i]=dpp[i-1]*9ll;
    // }
    // fo1(i,18)pref[i]=pref[i-1]+dpp[i];
    while(t--){
        solve();

    }
    
    return 0;
}



