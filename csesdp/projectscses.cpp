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
lli arr[MX][3];
lli BIT[2*MX];

void update(int ind,int n,lli val){

    // I seem to have forgotten a bit about BIT's
    // Haven't used them for quite some time now
    while(ind<=n){

        BIT[ind]=max(val,BIT[ind]);
        ind+=(ind&(-ind));
    }
}
lli query(int ind){

    lli res=0;
    while(ind>=1){
        res=max(res,BIT[ind]);
        ind-=(ind&(-ind));
    }
    return res;
}


//problem solver
void solve(){
    
    int n;
    cin>>n;
    fo1(i,n){

        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    map<lli,int>mt;
    fo1(i,n){
        mt[arr[i][0]];
        mt[arr[i][1]];
    }
    int cnt=1;
    for(auto &el:mt){

        el.ss=cnt++;

    }
    // coordinate compression done
    // solution time
    // probably sorting wrt ending times isalso needed
    vector<array<int,3>>vec;
    fo1(i,n){

        vec.pb({mt[arr[i][1]],mt[arr[i][0]],i});
    }
    // lets try the other way around
    sort(all(vec));
    lli ans=0;
    fo(i,n){

        lli temp=arr[vec[i][2]][2]+query(vec[i][1]-1);
        ans=max(ans,temp);
        update(vec[i][0],2*n,temp);
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



