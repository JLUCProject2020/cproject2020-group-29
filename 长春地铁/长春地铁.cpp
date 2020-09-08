#include <iostream>
#include<string>
using namespace std;

#define max 200

const int maxnum = 300;
const int maxint = 999999;
string str[]={" ","北环城路","庆丰路","一匡街","长春站北","长春站","胜利公园","人民广场",
    "解放大路","东北师大","工农广场","繁荣路","卫星广场","市政府",
    "华庆路","红嘴子","双丰","长春西站","兴隆堡","西环城路",
    "和平大街","万福街","景阳广场","解放桥","建设广场","文化广场",
    "解放大路","平阳街","南关","吉林大路","东盛大街",
    "东环城路","长青","东方广场","长春站","辽宁路","西安桥","南昌路",
    "朝阳桥","解放桥","湖西桥","宽平桥","抚松路","孟家屯","湖光路",
    "电台街","前进西","前进大街","卫明街","卫光街","卫星广场","亚泰立交桥",
    "伊通河","职业学院","吉林广电","会展中心","世纪广场","金鑫街","博硕路",
"金河街","农博园","净月潭公园","紫杉路","宝相街","滑雪场","长影世纪城","长春站北",
"北亚泰大街","伪满皇宫","东大桥","吉林大路","公平路","海口路","浦东路",
"威海路","北海路","职业学院","世荣路","南环城路","宜盛街","天工路",
"北环城路","一二三中学","小南","小城子街","北湖大桥","北湖公园","和安街","光机路","大学城路",
"地理所","奥林匹克公园","广通路"};


int path[max];
int visited[max]={0};
int ck[max];
int h=0;
int mk[max][max];
int cm[max];
int index[max];
int i;
int j; 

void DFS(int a[][92],int u,int v,int k)
{   
    k++;
    visited[u]=1; 
	  //标记每一次遍历的初始点防止出现路径中有重复点的情况
    path[k]=u;  
	 //将当前起始点存入路径数组
    if(u==v)   
	    //到了路径的结尾
    {
        int m=0;
        for(int i=0;i<=k;i++)
		{
            mk[h][i]=path[i];   
			 //将每一条完整路径存入二维数组的一行

        }
        
        for(int j=0;j<=k;j++)
            {
                if(mk[h][j]==1&&(mk[h][j-1]-mk[h][j+1]>2||mk[h][j-1]-mk[h][j+1]<-2))m++;
                
                if(mk[h][j]==4&&(mk[h][j-1]-mk[h][j+1]>2||mk[h][j-1]-mk[h][j+1]<-2))m++;
                
                if(mk[h][j]==5&&(mk[h][j-1]-mk[h][j+1]>2||mk[h][j-1]-mk[h][j+1]<-2))m++;
                
                if(mk[h][j]==8&&(mk[h][j-1]-mk[h][j+1]>2||mk[h][j-1]-mk[h][j+1]<-2))m++;
                
                if(mk[h][j]==12&&(mk[h][j-1]-mk[h][j+1]>2||mk[h][j-1]-mk[h][j+1]<-2))m++;
                
                if(mk[h][j]==23&&(mk[h][j-1]-mk[h][j+1]>2||mk[h][j-1]-mk[h][j+1]<-2))m++;
                
                if(mk[h][j]==29&&(mk[h][j-1]-mk[h][j+1]>2||mk[h][j-1]-mk[h][j+1]<-2))m++;
                
                if(mk[h][j]==53&&(mk[h][j-1]-mk[h][j+1]>2||mk[h][j-1]-mk[h][j+1]<-2))m++;
            }
        


            
        cm[h]=m;    
		//每一条路径的换乘次数
        ck[h]=k;    
		//每一条路径的长度
        h++;       
		 //二维数组下移一行
        
    }
    else      
	 //如果没到结尾那就从其他所有与起始点相邻的点重新开始遍历
    {
        for(int i=1;i<=92;i++)
        {
            if(a[u][i]==1&&visited[i]==0)
            {
                DFS(a,i,v,k);
            }
        }
    }
    visited[u]=0;  
	 //将起始点的标记取消，因为是求所有路径
}

int findmin(int arr[],int n)
{   
    int min=arr[0];
    
    for(int i =0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    return min;
}

int findindex(int arr[],int n)
{
    int min = arr[0];
    
    int index= 0;
    
    for(int i = 0;i<n;i++)
    {
        if(arr[i]<min)
        {
            index=i;
        }
    }
    return index;
}
int findmink(int arr1[],int arr2[],int n)
{
    int min=arr1[arr2[0]];
    
    for(int i=0;i<n;i++)
    {
        if(arr1[arr2[i]]<min)
        {
            
            min=arr1[arr2[i]];
            
        }
    }
    return min;
}
void Dijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum])
{
    
    
    bool s[maxnum];    
	// 判断是否已存入该点到S集合中
    for(int i=1; i<=n; i++)
    {
        dist[i] = c[v][i];
		//别的点到i这个点的距离 
        s[i] = 0;   
		  // 初始都未用过该点
        if(dist[i] == maxint)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;
 
   // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
    // 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
    for(i=1; i<=n-1; i++)
    {
        int tmp = maxint;
        
        int u = v;
        // 找出当前未使用的点j的dist[j]最小值
        for(int j=1; j<=n; j++)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;       
				       // u保存当前邻接点中距离最小的点的号码  u随之变成没有作为顶点的下标 
                tmp = dist[j];
            }
        s[u] = 1;   
		 // 表示u点已存入S集合中
 
        // 更新dist
        //以u为顶点更新数据 
        for(j=1; j<=n; j++)
            if((!s[j]) && c[u][j]<maxint)
            {
                int newdist = dist[u] + c[u][j];
                
                if(newdist < dist[j])
                {
                    dist[j] = newdist;
                    
                    prev[j] = u;
                }
            }
    }
}
 
//searchPath(prev, 1, i);

void searchPath(int *prev,int v, int u)
{
    
    int que[maxnum];
    
    int tot = 1;
    
    que[tot] = u;
	//追溯  从重点开始往回  找之前的节点  直到到第一个节点 
    tot++;
    
    int tmp = prev[u];
    
    while(tmp != v)
    {
        que[tot] = tmp;
        
        tot++;
        
        tmp = prev[tmp];
    }
    que[tot] = v;
    for(int i=tot; i>=1; i--)
    
        if(i != 1)
            cout << str[que[i]] << " -> ";
        else
            cout << str[que[i]] << endl;
}

void init()
{
    for(int i=1;i<=92;i++)
    {
        if(i==1){cout<<"    1号线:"<<endl;}
        if(i==16){cout<<endl<<"    2号线:"<<endl;}
        if(i==34){cout<<endl<<"    3号线:"<<endl;}
        if(i==66){cout<<endl<<"    4号线:"<<endl;}
        if(i==81){cout<<endl<<"    8号线:"<<endl;}
        cout<<str[i]<<":"<<i<<"   ";
        if(i%5==0&&i>=5)
        {
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<"请根据数字选择所需的起始点"<<endl;
}
int ifoneline(int b,int e)
{
    int m;
    int n;
    if(b>=1&&b<=15)
        m=1;
    if(b>=16&&b<=33)
        m=2;
    if(b>=34&&b<=65)
        m=3;
    if(b>=66&&b<=80)
        m=4;
    if(b>=81&&b<=92)
        m=8;
    if(e>=1&&e<=15)
        n=1;
    if(e>=16&&e<=33)
        n=2;
    if(e>=34&&e<=65)
        n=3;
    if(e>=66&&e<=80)
        n=4;
    if(e>=81&&e<=92)
        n=8;
    if(m==n)
        return 0;
    if(m!=n)
        return 1;
}
int main()
{
    cout<<"请选择最短路径或者最少换乘，如果是最短路径则选择1,如果是最少换乘则选择2,选择=:";

    int b,e,choose;
    cin>>choose;
    init();

    cout<<"请输入起始站"<<endl;
    cin>>b;
    cout<<"请输入终点站"<<endl;
    cin>>e;

    freopen("ditie.txt","r",stdin);
    // 各数组都从下标1开始
    int dist[maxnum]; 
	    // 表示当前点到源点的最短路径长度
    int prev[maxnum]; 
	    // 记录当前点的前一个结点
    int c[maxnum][maxnum]; 
	  // 记录图的两点间路径长度
    int n,line;    
	         // 图的结点数和路径数
    cin >> n;
    // 输入路径数
    cin >> line;
    int p, q, len;      
	    // 输入p, q两点及其路径长度
 
    
    for(int i=1; i<=n;i++)
        for(int j=1; j<=n; j++)
            c[i][j] = maxint;
 
    for(i=1; i<=line; i++)  
    {
        cin >> p >> q >> len;
        if(len < c[p][q])       
		// 有重边
        {
            c[p][q] = len;     
			 // p指向q
            c[q][p] = len;     
			 // q指向p，这样表示无向图
        }
    }
	//将数据更加精确 
    fclose(stdin);
    for(i=1; i<=n; i++)
        dist[i] = maxint;
    int a[92][92];
    
    freopen("output.txt","r",stdin);
    for(i=1;i<=92;i++)



    {
        for(int j=1;j<=92;j++)
        {
            
            cin>>a[i][j];
        }
    }
    int k =-1;
    switch(choose)
    {
    case 1:Dijkstra(n, b, dist, prev, c);
	cout<<"最短距离的站数是";
	cout<<dist[e]<<endl;
	searchPath(prev,b,e);
	break;
    case 2:DFS(a,b,e,k);
	fclose(stdin);
	int f=0;
    for(int j=0;j<h;j++)
    {
        if(cm[j]==findmin(cm,h))
        {
            index[f]=j;
            f++;
        }
    }
    int minindexk;
  
for(j=0;j<f;j++)
        if(ck[index[j]]==findmink(ck,index,f))
            minindexk=index[j];
    cout<<"========================"<<endl;
    cout<<"最少换乘中的最短路径为:";
    for(i =0;i<=ck[minindexk];i++)
    {
        cout<<str[mk[minindexk][i]]<<"   ";
    }
    cout<<endl;
    if(ifoneline(b,e)==1)
    {cout<<"换乘次数为  :"<<cm[minindexk]<<"  ";}
    else
    {cout<<"换乘次数为  :"<<0<<" ";
    }
    cout<<"the distance is  :"<<ck[minindexk]<<endl;break;
    }
    return 0;
}


