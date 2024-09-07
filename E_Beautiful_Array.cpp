//Jai Bajrang Bali
#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define vi vector
#define pb push_back
#define mod 1000000007
#define srt(v) sort(v.begin(),v.end())
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define all(v)  v.begin(),v.end()
//int ind = max_element(all(a)) - a.begin();
#define dis(v)  distance(v.begin(),max_element(all(v)))
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));// Apply after Sorting
// else only consecutive duplicates would be removed 
//s.erase(unique(s.begin(), s.end()), s.end());
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b + mod) % mod) + mod) % mod;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

void solve(){ 
    int n,k; 
    cin>>n>>k; 
    vector<ll>a(n); 
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,set<int>>mp; 
    for(int x:a){ 
        if(mp[x%k].find(x)!=mp[x%k].end()){ 
            mp[x%k].erase(x); 
        }else{ 
            mp[x%k].insert(x); 
        } 
    } 
    int cnt=0,val=-1; 
    for(auto x:mp){ 
        int sz=x.second.size(); 
        if(sz%2){ 
            cnt++; 
            val=x.first; 
        } 
    } 
    if(cnt>1){ 
        cout<<-1<<endl; 
        return; 
    } 
    int ans=0; 
    bool flg=false; 
    for(auto x:mp){ 
        if(x.first==val){ 
            continue; 
        } 
        while(x.second.size()>0){ 
            int b=*x.second.begin(); 
            x.second.erase(b); 
            int tp=*x.second.begin(); 
            ans+=(tp-b)/k; 
            x.second.erase(tp);             
        } 
    } 
   
    if(cnt){ 
        vector<long long> v; 
        for(int x:mp[val]){ 
            v.pb(x); 
        } 
        
        int n=v.size(); 
        if(n==1){ 
            cout<<ans<<endl; 
            return; 
        } 
        vector<ll> pref(n,0),suf(n,0); 
        pref[1]=v[1]-v[0]; 
        for(int i=3;i<n-1;i++){ 
            pref[i]=v[i]-v[i-1]+pref[i-2]; 
        } 
        suf[n-2]=v[n-1]-v[n-2]; 
        for(int i=n-4;i>=0;i--){ 
            suf[i]=v[i+1]-v[i]+suf[i+2]; 
        } 
        int ta=LLONG_MAX; 
        for(int i=0;i<n;i+=2){ 
            int x=0; 
            if(i>0){ 
                x+=pref[i-1]; 
            } 
            if(i+1<n){ 
                x+=suf[i+1]; 
            } 
            ta=min(ta,x); 
        } 
        ans+=ta/k; 
    } 
    cout<<ans<<endl; 
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}