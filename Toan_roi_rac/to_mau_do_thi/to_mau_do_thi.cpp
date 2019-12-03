#include<bits/stdc++.h>
 
using namespace std;
typedef pair<int,int> ii;
vector<ii> display;
int v,e;
vector<vector<int> > graph;
vector<int> color;
string color1[7]={"LightCyan","MistyRose","green","blue","pink","red","yellow"};
void greedyColoring()
{
    color[0] = 0;
    for (int i=1;i<v;i++)
        color[i] = -1;
 
    bool used[v];//bảng màu đã dùng.
 
    for (int i=0;i<v;i++)
        used[i]=0;
 
 
    for (int i = 1; i < v; i++)
    {
        for (int j=0;j<graph[i].size();j++){
            if (color[graph[i][j]] != -1){//nếu đỉnh đã tô 
                used[color[graph[i][j]]] = true;//đánh dấu đã tô màu
            }
        } 
        int mau;// màu cần tô
        for (mau=0;mau<v;mau++){
            if (used[mau] == false)//nếu màu chưa tô
                break;
        }
        color[i] = mau;//tô màu cho đỉnh 
 
        for (int j=0;j<graph[i].size();j++)
            if (color[graph[i][j]] != -1)
                used[color[graph[i][j]]] = false;
    }
}
void docfile(){
    int x,y;
    ifstream dothi ("dothi.txt");
    dothi >> v;
    dothi >> e;
    graph.resize(v);
    color.resize(v);
    while(!dothi.eof()){
        dothi >> x;
        dothi >> y;
        display.push_back(make_pair(x,y));
        x--,y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dothi.close();
}
void ghifile(){
    ofstream ketqua ("ketqua.dot");
    ketqua<<"graph dothi"<<endl;
    ketqua<<"{"<<endl;
    for(int i=0;i<v;i++)
        ketqua<<"\t"<<i+1<<" [fillcolor="<<color1[color[i]]<<", style=filled]"<<endl;
    for(int i=0;i<display.size()-1;i++){
        ketqua<<"\t"<<display[i].first<<" -- "<<display[i].second<<endl;
    }
    ketqua<<"}"<<endl;
    ketqua.close();
}
int main()
{
    docfile();
    greedyColoring();
    ghifile();
    //dot -Tpdf ketqua.dot -o graph.pdf
}
