#include <iostream>
#include<string>
using namespace std;

#define max 200

const int maxnum = 300;
const int maxint = 999999;
string str[]={" ","������·","���·","һ���","����վ��","����վ","ʤ����԰","����㳡",
    "��Ŵ�·","����ʦ��","��ũ�㳡","����·","���ǹ㳡","������",
    "����·","������","˫��","������վ","��¡��","������·",
    "��ƽ���","�򸣽�","�����㳡","�����","����㳡","�Ļ��㳡",
    "��Ŵ�·","ƽ����","�Ϲ�","���ִ�·","��ʢ���",
    "������·","����","�����㳡","����վ","����·","������","�ϲ�·",
    "������","�����","������","��ƽ��","����·","�ϼ���","����·",
    "��̨��","ǰ����","ǰ�����","������","�����","���ǹ㳡","��̩������",
    "��ͨ��","ְҵѧԺ","���ֹ��","��չ����","���͹㳡","���ν�","��˶·",
"��ӽ�","ũ��԰","����̶��԰","��ɼ·","�����","��ѩ��","��Ӱ���ͳ�","����վ��",
"����̩���","α���ʹ�","������","���ִ�·","��ƽ·","����·","�ֶ�·",
"����·","����·","ְҵѧԺ","����·","�ϻ���·","��ʢ��","�칤·",
"������·","һ������ѧ","С��","С���ӽ�","��������","������԰","�Ͱ���","���·","��ѧ��·",
"������","����ƥ�˹�԰","��ͨ·"};


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
	  //���ÿһ�α����ĳ�ʼ���ֹ����·�������ظ�������
    path[k]=u;  
	 //����ǰ��ʼ�����·������
    if(u==v)   
	    //����·���Ľ�β
    {
        int m=0;
        for(int i=0;i<=k;i++)
		{
            mk[h][i]=path[i];   
			 //��ÿһ������·�������ά�����һ��

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
		//ÿһ��·���Ļ��˴���
        ck[h]=k;    
		//ÿһ��·���ĳ���
        h++;       
		 //��ά��������һ��
        
    }
    else      
	 //���û����β�Ǿʹ�������������ʼ�����ڵĵ����¿�ʼ����
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
	 //����ʼ��ı��ȡ������Ϊ��������·��
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
	// �ж��Ƿ��Ѵ���õ㵽S������
    for(int i=1; i<=n; i++)
    {
        dist[i] = c[v][i];
		//��ĵ㵽i�����ľ��� 
        s[i] = 0;   
		  // ��ʼ��δ�ù��õ�
        if(dist[i] == maxint)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;
 
   // ���ν�δ����S���ϵĽ���У�ȡdist[]��Сֵ�Ľ�㣬������S��
    // һ��S����������V�ж��㣬dist�ͼ�¼�˴�Դ�㵽������������֮������·������
    for(i=1; i<=n-1; i++)
    {
        int tmp = maxint;
        
        int u = v;
        // �ҳ���ǰδʹ�õĵ�j��dist[j]��Сֵ
        for(int j=1; j<=n; j++)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;       
				       // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ���  u��֮���û����Ϊ������±� 
                tmp = dist[j];
            }
        s[u] = 1;   
		 // ��ʾu���Ѵ���S������
 
        // ����dist
        //��uΪ����������� 
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
	//׷��  ���ص㿪ʼ����  ��֮ǰ�Ľڵ�  ֱ������һ���ڵ� 
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
        if(i==1){cout<<"    1����:"<<endl;}
        if(i==16){cout<<endl<<"    2����:"<<endl;}
        if(i==34){cout<<endl<<"    3����:"<<endl;}
        if(i==66){cout<<endl<<"    4����:"<<endl;}
        if(i==81){cout<<endl<<"    8����:"<<endl;}
        cout<<str[i]<<":"<<i<<"   ";
        if(i%5==0&&i>=5)
        {
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<"���������ѡ���������ʼ��"<<endl;
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
    cout<<"��ѡ�����·���������ٻ��ˣ���������·����ѡ��1,��������ٻ�����ѡ��2,ѡ��=:";

    int b,e,choose;
    cin>>choose;
    init();

    cout<<"��������ʼվ"<<endl;
    cin>>b;
    cout<<"�������յ�վ"<<endl;
    cin>>e;

    freopen("ditie.txt","r",stdin);
    // �����鶼���±�1��ʼ
    int dist[maxnum]; 
	    // ��ʾ��ǰ�㵽Դ������·������
    int prev[maxnum]; 
	    // ��¼��ǰ���ǰһ�����
    int c[maxnum][maxnum]; 
	  // ��¼ͼ�������·������
    int n,line;    
	         // ͼ�Ľ������·����
    cin >> n;
    // ����·����
    cin >> line;
    int p, q, len;      
	    // ����p, q���㼰��·������
 
    
    for(int i=1; i<=n;i++)
        for(int j=1; j<=n; j++)
            c[i][j] = maxint;
 
    for(i=1; i<=line; i++)  
    {
        cin >> p >> q >> len;
        if(len < c[p][q])       
		// ���ر�
        {
            c[p][q] = len;     
			 // pָ��q
            c[q][p] = len;     
			 // qָ��p��������ʾ����ͼ
        }
    }
	//�����ݸ��Ӿ�ȷ 
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
	cout<<"��̾����վ����";
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
    cout<<"���ٻ����е����·��Ϊ:";
    for(i =0;i<=ck[minindexk];i++)
    {
        cout<<str[mk[minindexk][i]]<<"   ";
    }
    cout<<endl;
    if(ifoneline(b,e)==1)
    {cout<<"���˴���Ϊ  :"<<cm[minindexk]<<"  ";}
    else
    {cout<<"���˴���Ϊ  :"<<0<<" ";
    }
    cout<<"the distance is  :"<<ck[minindexk]<<endl;break;
    }
    return 0;
}


