    #include <iostream>
    #include <algorithm>
    #include <cstdlib>
    #include <cstdio>
    #include <numeric>
    #include <utility>
    #include <cmath>
    #include <vector>
    #include <queue>
    #include <string>
    #include <map>
    #define MAX_U   10
    #define MIN_U   0
    #define rep(i,n) for(int i=0;i<n;i++)
    #define sz(x) ((int)(x).size())
    using namespace std;
    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<char> vc;
    typedef vector<string> vs;
    typedef queue<int> qi;
    const int INF=numeric_limits<int>::infinity();
    void printa(){cout<<"\n";}
    template<class T, class... A>void printa(const T&first,const A&... rest){cout<<first;printa(rest...);}
    template<class... A>void printa(const A&... rest){printa(rest...);}
    void prints(){cout<<" ";}
    template<class T, class... A>void prints(const T&first,const A&... rest){cout<<first;prints(rest...);}
    template<class... A>void prints(const A&... rest){prints(rest...);}
    int factorial(int x){int f=1;for(int i=1;i<x+1;i++)f=f*i;return f;}
    int sigma(int x){int s;for(int i=1;i<x+1;i++)s=s+i;return s;}
    int middle(int x){if(x%2==0)return x/2;else return x/2+1;}
    double heron(int a,int b,int c){double s;s=(a+b+c)/2;return sqrt(s*(s-a)*(s-b)*(s-c));}
    double trapezium(int a,int b,int h){return (a+b)*h/2;}
    double triangle(int a,int h){return a*h/2;}
    void sorm(vector<int> vec){sort(vec.begin(),vec.end());}
    void sorg(vector<int> vec){sort(vec.begin(),vec.end(),greater<int>());}
    int cmp( const void *p, const void *q ) {
    if( *(double*)p > *(double*)q ) return 1;
    if( *(double*)p < *(double*)q ) return -1;
    return 0;
    }
    int main(void){
        cin.tie(0);
        ios::sync_with_stdio(false);
        
       return 0;
    }
