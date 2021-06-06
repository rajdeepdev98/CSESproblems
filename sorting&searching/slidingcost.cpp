#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define lli long long int
#define pb push_back
#define in insert
#define er erase
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
#define trav(a,x) for (auto& a: x)
#define deb(x) cout<<#x<<"="<<x<<"\n"//debugging
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


using namespace std;
const int MX=(int)(2e5)+5;
int darr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int arr[MX];
vector<int>graph[MX];

// Utility functions
void setPrec() { cout << fixed << setprecision(15); }
template<typename A>
A Max(A a,A b){
    return max(a,b);
}
template<typename A,typename... Args>
A Max(A a,A b,Args... args){
    return Max(Max(a,b),args...);
}
template<typename A>
void amin(A& a, A b){
    a=min(a,b);
}
template<typename A>
void amax(A& a, A b){
    a=max(a,b);
}

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





//problem solver
void solve(){
    
   int n,k;
   cin>>n>>k;
   fo1(i,n)cin>>arr[i];
   if(n==1){

       fo1(i,n)cout<<arr[i]<<" ";
       cout<<"\n";
       return;
   }
   multiset<int>lset,rset;
   lli lsum=0,rsum=0;
   int no=(k+1)/2;
   int no2=k-no;
//    fo1(i,no)lset.in(arr[i]);
//    FOR(i,no+1,k)rset.in(arr[i]);
    
   auto med=[&](){

      lli val=*prev(lset.end());
      return 1ll*no*val-lsum+rsum-1ll*no2*val;

   };
   auto inval=[&](int val){

       if( !rset.empty()&&val>*rset.begin()){

           rset.in(val);
           rsum+=val;
           if(rset.size()>no2){
               lset.in(*rset.begin());
               lsum+=(*rset.begin());
               rsum-=(*rset.begin());
               rset.er(rset.begin());

           }
       }
       else {
           lset.in(val);
           lsum+=val;
           if(lset.size()>no){
               rset.in(*prev(lset.end()));
               rsum+=(*prev(lset.end()));
               lsum-=(*prev(lset.end()));
               lset.er(prev(lset.end()));
           }
       }
   };
   auto delval=[&](int val){

       if(val>*prev(lset.end())){
           rset.erase(rset.find(val));
           rsum-=val;
       }
       else {
           lset.er(lset.find(val));
           lsum-=val;
           }
   };
   multiset<int>temp;
   fo1(i,k)temp.in(arr[i]);
   int cnt=1;
   for(auto el:temp){

       if(cnt<=no){
           lset.in(el);
           lsum+=el;
           }
       else {
           rset.in(el);
           rsum+=el;
       }
       cnt++;
   }
//    int ans=0;
//    int val=med();
//    fo1(i,k)ans+=(abs(val-arr[i]));
   fo1(i,n-k+1){
       int l=i,r=i+k-1;
       
       cout<<med()<<" ";
       if(i!=n-k+1){
           delval(arr[i]);
           inval(arr[r+1]);
       }

   }
   cout<<"\n";
//    for(auto el:lset)cout<<el<<" ";
//    cout<<"lll\n";
//    for(auto el:rset)cout<<el<<" ";

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



