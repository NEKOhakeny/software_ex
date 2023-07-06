#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include <fstream>
#include <sstream>
using namespace std;
#define  vec(a)  vector<a>
#define roop(a,c) for(long long (a) = 0;(a) < (c); (a)++)
#define rep(a,b,c) for(long long (a) = (b);(a) < (c) ; (a)++)

template<class T>void chmin(T &a,T b)
{
    if(a > b) a = b;
}
template<class T>void chmax(T &a,T b)
{
    if(a < b)a = b;
}
struct edge{
    int to,cost;
    bool operator < (edge other)
    {
        return this->cost < other.cost;
    }

};

struct graph{
    
    
    
};



int main()
{
    int w,h;
    cin>>w>>h;
    vec(vec(bool)) g(h + 2,vec(bool)(w + 2,true));
    
    


    

}