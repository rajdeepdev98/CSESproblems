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
int arr[MX];
vector<int>graph[MX];
lli dp[12][92][2];

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

lli sm(lli n){

    lli ans=0;
    while(n!=0){
        ans+=(n%10);
        n/=10;
    }
    return ans;
}
lli brut(lli n){

    lli ans=0;
    fo1(i,n){
        ans+=sm((lli)(i));
    }
    return ans;
}

lli fnd(int pos,int sum,int n,int flag){

        if(n==0)return 0ll;
        if(pos>n)return (lli)(sum);
        if(dp[pos][sum][flag]!=-1)return dp[pos][sum][flag];
        

        int lim=9;
        if(!flag)lim=arr[pos];
        
        lli res=0;

        fo(i,lim+1){

            // recursion mann!!
            if(!flag && i<lim){
                res+=fnd(pos+1,sum+i,n,1);
            }
            else if(!flag && i==lim){
                res+=fnd(pos+1,sum+i,n,0);
            }
            else if(flag){

                res+=fnd(pos+1,sum+i,n,1);
            }

        }
        return dp[pos][sum][flag]=res;



}
int convrtint(lli n){

        int num=0;
        lli nt=n;
        while(nt!=0){
            num++;
            nt/=10;
        }
        nt=n;
        FORN(i,num,1){
            arr[i]=nt%10;
            nt/=10;
        }
        fo1(i,num){
            fo(j,92)fo(k,2){
                dp[i][j][k]=-1;
            }
        }
        return num;
}

//problem solver
void solve(){
    

    lli a,b;
    cin>>a>>b;
    if(a==-1 || b==-1){
       exit(0);
    }
    lli lft=(a==0)?0:(a-1);
    

    lli ans1=fnd(1,0,convrtint(b),0)-fnd(1,0,convrtint(lft),0);
    // lli ans2=brut(b)-brut(lft);
    // deb(ans1);
    // deb(ans2);
    // deb(brut(b));
    // cout<<brut(4ll)<<"\n";
    // cout<<sm(45ll)<<"\n";
    // arr[1]=1,arr[2]=0;
    // lli temp=fnd(1,0,2,0);
    // deb(temp);
    cout<<ans1<<"\n";

    


}


int main(){ 
   
    // OJ;

    fast;

    int t;
    // cin>>t;
    // t=1;

    while(1){
        solve();

    }
    // cout<<"lala\n";
    
    return 0;
}



