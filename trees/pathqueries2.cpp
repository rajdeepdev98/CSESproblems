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
int arr[MX];
vector<int>graph[MX];
int L=21;
int tin[MX],dis[MX],siz[MX],chain[MX],up[MX][21],bigchild[MX],barr[MX],cnt=0;
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
 
template<typename T>
struct Tree {
	
 
    vector<T>vec;
    int nt,n;
    Tree(int ntemp){
        nt=ntemp;
        vec.resize(nt,0);
    }
    Tree(T arr[],int n){
        this->n=n;
        nt=5*n+1;
        vec.resize(nt,0);
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
    void update(T arr[],int idx,T val){
        update2(arr,1,1,n,idx,val);
    }
    void update2(T arr[],int node,int start,int end,int idx,T val){
 
            if(start==end){
                arr[start]=val;
                vec[node]=val;
            }
            else{
 
                int mid=(start+end)/2;
                if(idx>=start && idx<=mid){
                    update2(arr,2*node,start,mid,idx,val);
                }
                else{
                    update2(arr,2*node+1,mid+1,end,idx,val);
                }
                vec[node]=comb(vec[2*node],vec[2*node+1]);
            }
 
    }
    T query(int l,int r){
        return query2(1,1,n,l,r);
    }
    T query2(int node,int start,int end,int l,int r){
 
            if(start>r || end<l)return -1;//for sum its zero for min its max and for max its min
            if(start>=l && end<=r)return vec[node];
            int mid=(start+end)/2;
            T a1=query2(2*node,start,mid,l,r),b1=query2(2*node+1,mid+1,end,l,r);
            return comb(a1,b1);
 
    }
    T comb(T &a,T &b){
 
        return max(a,b);//or min or sum which means any associative function
    }
 
 
};
Tree<int>tr(4*MX+5);
 
//adding a graph template
void ipgraph(int n,int m){
 
    int u,v;
    fo1(i,m){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
}
 
 
void dfs_size(int s,int p){
 
    dis[s]=dis[p]+1;
    // tin[s]=++cnt;
    up[s][0]=p;
    
     for(int i=1;i<21;i++){
 
        up[s][i]=up[up[s][i-1]][i-1];//binary lifting
 
    }
    siz[s]=1;
    int bigv=-1,bigc=-1;
    for(auto el:graph[s]){
 
        if(el==p)continue;
        dfs_size(el,s);
        siz[s]+=siz[el];
        if(siz[el]>bigv){
            bigv=siz[el];
            bigc=el;
        }
 
    }
    bigchild[s]=bigc;
}
int LCA(int u,int v){
 
    if(dis[u]<dis[v]){
        int temp=dis[v]-dis[u];
        for(int i=0;i<L;i++){
            if(temp &(1<<i))v=up[v][i];
        }
    }
    else if(dis[v]<dis[u]){
 
        int temp=dis[u]-dis[v];
        for(int i=0;i<L;i++){
            if(temp &(1<<i))u=up[u][i];
 
        }
    }
    if(u==v)return u;
    for(int i=L-1;i>=0;i--){
 
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}
 
void chain_init(int n){
 
    fo1(i,n)chain[i]=i;
 
}
void dfs_chains(int s,int p){
 
        if(bigchild[s]!=-1){
            chain[bigchild[s]]=chain[s];
        }
        for(auto el:graph[s]){
 
            if(el!=p){
 
                dfs_chains(el,s);
            }
        }
 
 
}
void dfs_labels(int s,int p){
 
    tin[s]=++cnt;
    tr.update(barr,tin[s],arr[s]);//segment tree or BIT whichever is better
   if(bigchild[s]!=-1) dfs_labels(bigchild[s],s);
    for(auto el:graph[s]){
            if(el!=p && el!=bigchild[s]){
                dfs_labels(el,s);
            }
    }
}
 
int get_anc(int u,int k){
 
    fo(i,18){
        if(k& 1<<i){
            u=up[u][i];
 
        }
    }
    return u;
}
int query_chains(int u,int p){
    //gets the sum till the value below the LCA
    int val=0;
    while(chain[u]!=chain[p]){

        amax(val,tr.query(tin[chain[u]],tin[u]));
        u=chain[u];
        u=up[u][0];
    }
    amax(val,tr.query(tin[p],tin[u]));
    return val;
 
}
 
int path_query(int u,int v){
 
    int lc=LCA(u,v);
    int val=max(query_chains(u,lc),query_chains(v,lc));
    // amax(val,tr.query(tin[lc],tin[lc]));//bit query;
    return val;
    
}
int path_update(int u,int v){
    //will need lazyprop for this
    return 0;
    
}
 
 
 
//problem solver
void solve(){
    
    int n,q;
    cin>>n>>q;
    fo1(i,n)cin>>arr[i];
    ipgraph(n,n-1);
    // cout<<"lele\n";
 
    
    chain_init(n);
    dfs_size(1,0);
    // fo1(i,n)barr[tin[i]]=arr[i];
    // tr.init(barr,n);
    tr.n=n;
    // tr.build(barr,1,1,n);
   // cout<<"hello\n";
   
    dfs_chains(1,0);
    dfs_labels(1,0);
 
    // dfs_labels(1,0);
    // fo1(i,n)cout<<chain[i]<<" ";
    // cout<<"\n";
    // cout<<"test\n";
    // cout<<path_query(1,1)<<"\n";
    
    while(q--){
 
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
 
            tr.update(barr,tin[b],c);
            arr[b]=c;
        }
        else{
            cout<<path_query(b,c)<<" ";
        }
    }
    
    // cout<<tr.query(1,1)<<"lala\n";
    // cout<<LCA(4,5)<<"lllaa\n";
    // cout<<query_chains(4,2)<<" "<<query_chains(5,2)<<"\n";
    // cout<<"\n";
    // fo1(i,n)cout<<chain[i]<<" ";
    
 
    
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
 
 