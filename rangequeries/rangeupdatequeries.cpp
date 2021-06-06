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
#define trav(a,x) for (auto& a: x)
#define deb(x) cout<<#x<<"="<<x<<"\n"//debugging
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


using namespace std;
const int MX=(int)(2e5)+5;
int darr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
lli arr[MX];
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

template<typename T>
struct Tree {
	

    vector<T>vec;
    vector<T>lazy;
    int nt,n;
    Tree(int ntemp){
        nt=ntemp;
        vec.resize(nt);
    }
    Tree(T arr[],int n){
        this->n=n;
        nt=4*n+1;
        vec.resize(nt);
        lazy.resize(nt,0);
        build(arr,1,1,n);
    }
    void init(T arr[],int n){
        this->n=n;
        build(arr,1,1,n);

    }
    void build(T arr[],int node,int start,int end){

            if(start==end){
                vec[node]=arr[start];
            }
            else{

                int mid=(start+end)/2;
                build(arr,2*node,start,mid);
                build(arr,2*node+1,mid+1,end);
                vec[node]=comb(vec[2*node],vec[2*node+1]);
            }


    }
    void update2(T arr[],int node,int start,int end,int l,int r,T val){

        if(lazy[node]!=0){

            vec[node]+=(end-start+1)*lazy[node];
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
            lazy[node]=0;

        }
        if(start>r || end<l)return;
        if(start>=l && end<=r){
            vec[node]+=(end-start+1)*val;
            if(start!=end){
                lazy[2*node]+=val;
                lazy[2*node+1]+=val;
            }
        }
        int mid=(start+end)/2;
        update2(arr,2*node,start,mid,l,r,val);
        update2(arr,2*node,mid+1,end,l,r,val);
        vec[node]=comb(vec[2*node],vec[2*node+1]);


    }
    void update(T arr[],int l,int r,T val){

            update2(arr,1,1,n,l,r,val);

    }
    T query(int l,int r){
        return query2(1,1,n,l,r);
    }

    T query2(int node,int start,int end,int l,int r){

            if(start>r || end<l)return 0;//for sum
            if(lazy[node]!=0){

                vec[node]+=(end-start+1)*lazy[node];
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
                lazy[node]=0;
            }
            if(start>=l && end<=r){

                return vec[node];
            }
            int mid=(start+end)/2;
            T a1=query2(2*node,start,mid,l,r);
            T b1=query2(2*node+1,mid+1,end,l,r);
            return comb(a1,b1);

    }
    
    T comb(T &a,T &b){

        return a+b;//or min or sum which means any associative function
    }


};





//problem solver
void solve(){
    
    int n,q;
    cin>>n;
    fo1(i,n)cin>>arr[i];
    Tree<lli>tr(arr,n);
    
    while(q--){

          int tp ;
          cin>>tp;
          if(tp==1){

              int a,b,c;
              cin>>a>>b>>c;
              tr.update(arr,a,b,(lli)(c));
          }
          else{
            int k;
            cin>>k;
              cout<<tr.query(k,k)<<"\n";
          }

    }
    
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


