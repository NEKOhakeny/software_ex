#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include <fstream>
#include <sstream>
#include <map>
#include<queue>
#include<string>
using namespace std;
#define check cout<<"死ね"<<endl;
#define  vec(a)  vector<a>
#define roop(a,c) for(long long (a) = 0;(a) < (c); (a)++)
#define rep(a,b,c) for(long long (a) = (b);(a) < (c) ; (a)++)

template<class T>bool chmin(T &a,T b)
{
    if(a > b) a = b;
    return a > b;
}
template<class T>void chmax(T &a,T b)
{
    if(a < b)a = b;
}
struct Point{
    int x,y;
    Point(int x,int y):x(x),y(y){}
    Point operator + (const Point other){
        return Point(this->x + other.x,this->y + other.y);
    }
    
};
struct Product{
    string name;
    Point pt;
    Product(string name,Point pt):name(name),pt(pt){}
    bool operator < (const Product other)
    {
        return this->name < other.name;
    }
};
struct edge{
    Product p;
    int cost;
    edge(Product p,int cost):p(p),cost(cost){}
    bool operator < (edge other)
    {
        return this->cost < other.cost;
    }
};

struct Path{
    vec(string) products;
    int cost;
    Path(int val){
        cost = val;
    }
    Path(string s,int val){
        products.push_back(s);
        cost = val;
    }
    bool operator < (const Path other){
        if(this->cost < other.cost )return true;
        if(this->cost == other.cost){
            return products.size() > other.products.size();
        }else return false;

        
    }
};

struct graph{
    int w,h;
    map<string, vec(vec(Path))> dist;
    vec(vec(string)) g;
    string True = "Yes";
    string False  = "None";
    Point direct[4] = {Point(1,0),Point(0,1),Point(-1,0),Point(0,-1)};
    map<string,Point*> pxx;
    graph(int w,int h):w(w),h(h)
    {

        g = vec(vec(string))((h + 2),vec(string)(w + 2,True));
        
        roop(i,w + 2){
            g[0][i] = False;
            g[1][i] = False;
            g[h + 1][i] = False;
        }
        roop(i,h + 2)
        {
            g[i][0] = False;
            g[i][w + 1] = False;
        }
        g[1][2] = True;
        g[1][w - 1] = True;
        g[h][1] = False;
        g[h][w] = False;

    }
    void getDist(Product pi)
    {
        vec(vec(string)) searched = g;
        vec(vec(Path)) pth(h + 2,vec(Path)(w + 2,Path(w * h)));
        pth[pi.pt.y][pi.pt.x].cost = 0;
        pth[pi.pt.y][pi.pt.x].products.push_back(pi.name);
        queue<Point> que;
        que.push(pi.pt);
        while(!que.empty()){
            Point now = que.front();
            que.pop();
            for(auto di:direct){
                Path root = pth[now.y][now.x];
                root.cost += 1;
                Point dem = di + now;
                if(searched[dem.y][dem.x] == False)continue;
                if(!(searched[dem.y][dem.x] == True))root.products.push_back(g[dem.y][dem.x]);
                que.push(dem);
                if(root < pth[dem.y][dem.x]){
                    pth[dem.y][dem.x] = root;
                }
            }
            searched[now.y][now.x] = False;
        }
        
        dist[pi.name] = pth;
    }
    Path getCost(string from,string to)
    {
        vec(vec(Path)) d = dist[from];
        Point *pt = pxx[to];
        return d[pt->y][pt->x].cost;
        
    }
    void print(vec(vec(int)) dp)
    {
        int n = dp[0].size();
        roop(i,1 << n)
        {
            roop(j,n)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    

    Path shortestPath(vec(string) s)
    {
        int n = s.size();
        
        vec(vec(int)) dp((1 << n),vec(int)(n,w * h));
        dp[1][0] = 0;
        vec(string) gomi;
        roop(i,1 << n)
        {
            roop(j,n)
            {
                if((1 << j) & i)continue;
                vec(string) kuzu;
                roop(k,n)
                {
                    if(!((1 << k) & i))continue;
                    //cout<<getCost(s[k],s[i])<<endl;
                    //cout<<s[k]<<" "<<s[j]<<endl;
                    Path p = getCost(s[k],s[j]);
                    if(chmin(dp[i | 1 << j][j],dp[i][k] + p.cost))
                    {
                        kuzu = p.products;
                    }
                }
                gomi.insert(gomi.end(),kuzu.begin(),kuzu.end());
            }
        }
        //print(dp);
        Path shine(dp[(1 << n) - 1][n - 1]);
        shine.products = gomi;
        return shine;
    }
    

   

    
    
};



int main()
{
    int w,h,n;
    cin>>w>>h>>n;
    graph Graph(w,h);

    vec(Product) px;
    roop(i,n)
    {
        int x,y;
        cin>>x>>y;
        x++;
        y++;
        Graph.g[y][x] = Graph.False;
        string name;
        char c;
        cin>>name>>c;
        if(c == 'E')x++;
        else if(c == 'N')y++;
        else if(c == 'W')x--;
        else if(c == 'S')y--;
        Product p(name,Point(x,y));
        Graph.g[y][x] = name;
        //cout<<p.pt.x<<" "<<p.pt.y<<endl;
        Graph.pxx[p.name] = new Point(x,y);
        px.push_back(p);
    }
    px.push_back(Product("En",Point(2,1)));
    px.push_back(Product("Ex",Point(w - 1,1)));
    Graph.pxx["En"] = new Point(2,1);
    Graph.pxx["Ex"] = new Point(w - 1,1);
    for(auto pi:px)
    {
        Graph.getDist(pi);
    }
    /*for(auto it:Graph.pxx)
    {
        cout<<it.first<<endl;
        cout<<it.second->x<<" "<<it.second->y;
        cout<<endl;
    }*/
    int q;
    
    cin>>q;
    roop(i,q)
    {
        int  m;
        cin>>m;
        vec(string) products;
        products.push_back("En");
        roop(i,m)
        {
            string s;
            cin>>s;
            products.push_back(s);
        }
        products.push_back("Ex");
        Path ans = Graph.shortestPath(products);
        cout<<ans.cost<<endl;
        for(auto gomi:ans.products)
        {
            cout<<gomi<<" ";
        }
        cout<<endl;
    }
    

    
    


    

}