
#include <iostream>
using namespace std;

class que{
    public:
        int fr,re,q[50];
    que(){
        fr=-1;
        re=-1;
    }
    bool isempty(){
        if(fr==-1)
            return 1;
        else 
            return 0;
    }
    void push(int x){
        if(isempty())
                fr++;
        re++;
        q[re]=x;
    }
    void pop(){
        if(isempty())
            return;
        else
        fr++;
    }
    void disp(){
        cout<<q[fr];
    }


};

class graph{
    public:
        int adj[10][10];
        int i,j,vn,en,k;
        que q1;
        int visited[10];
        int v;
   
   
   void initialize(){
    cout<<"Enter the total number of vertices:"<<endl;
   cin>>vn;
  for( i=0;i<vn;i++)
  {
      for( j=0;j<vn;j++){
          adj[i][j]=0;
      }
  }
     for( i=0;i<vn;i++){
            visited[i]=0;
        }
   }
  void adjancymat(){
 
  for( i=0;i<vn;i++)
  {   cout<<"Enter the total Degree of "<<i+1<<" th vertex :"<<endl;
   cin>>en;  
      cout<<"Enter the adjucent vertices of "<<i+1<<" th vertex:"<<endl;
         
      for( j=0;j<en;j++){
          cin>>k;
          adj[i][k]=1;
          adj[k][i]=1;
         
      }
     
  }
  }
   void display()
   {
     for( i=0;i<vn;i++)
     {
      for( j=0;j<vn;j++){
          cout<<adj[i][j]<<"    ";
      }
      cout<<endl;
     }  
    }

   int sm(){
    int su=0;
    for ( i = 0; i < vn; i++)
    {
        su+=visited[i];
    }
    return su;
    
   }

    void check(int k)
    {
       int val=sm();
        if (val==vn)
        {
            return;
        }
        while(!q1.isempty())
       { q1.push(k);
        visited[k]=1;
        q1.disp();
        q1.pop();
        for ( i = 0; i <vn; i++)
        {
           if(adj[k][i]==1){
                if(visited[i]==0){
                    check(i);
                                 }
                            }
        }
       }
    }

   void bsf()
   {
        cout<<"Enter the starting node:\n";
        cin>>v;
            check(v);
    }


};
int main() {
    graph g;
    g.initialize();
    cout<<endl;
    g.adjancymat();
    cout<<endl;
    g.display();
    g.bsf();

    return 0;
}