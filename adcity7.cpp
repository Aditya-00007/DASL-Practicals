/*There are flight paths between cities. If there is a flight between city A and city B then
there is an edge between the cities. The cost of the edge can be the time that flight take
to reach city B from A, or the amount of fuel used for the journey. Represent this as a
graph. The node can be represented by airport name or name of the city. Use adjacency
list representation of the graph or use adjacency matrix representation of the graph.
Check whether the graph is connected or not. Justify the storage representation used.*/

#include<iostream>
using namespace std;

class graph{
	public:

		string city[10];
		int arr[10][10],vn;
		
		void total()
		{
			cout<<"Enter the total number of cities in Sequence:";
			cin>>vn;
			cout<<endl;
			for(int i=0;i<vn;i++)
			{	cout<<"Enter the name of "<<i<<" city: ";
				cin>>city[i];
			}
			
		}
		
		void initialize()
		{
			for(int i=0;i<vn;i++)
			{
				for(int j=0;j<vn;j++)
			{
				arr[i][j]=0;
			}
			}
		}
		
		void accept()
		{	
			for(int i=0;i<vn;i++)
			{
				for(int j=i+1;j<vn;j++)
			{
				cout<<"Enter the time requird from "<<city[i] <<" to "<<city[j]<<" FLIGHT :";
				cin>>arr[i][j];
				arr[j][i]=arr[i][j];
			}
			}
			
		
		
		}
		
		void display()
		{
			cout<<"	";
			for(int i=0;i<vn;i++)
			{
				cout<<city[i]<<"	";
				}
			cout<<"\n";
			for(int i=0;i<vn;i++)
			{	
				cout<<city[i]<<"	";
				for(int j=0;j<vn;j++)
				{
					cout<<arr[i][j]<<"	";
				}
				cout<<endl;
			}
		
		}
	
	
	void connectivity()
	{	int sum;
		for(int i=0;i<vn;i++){
			sum=0;
			for(int j=0;j<vn;j++){
				if(arr[i][j]!=0)
					sum+=1;
				else if(sum==0 && j==vn-1)
					cout<<"graph is not connected ! "<<endl;
				else if(i==vn-1 && j==vn-1 && sum!=0)
					cout<<"graph is  connected ! "<<endl;

		}
		}
	}


};

int main()
{	
	cout<<"*************DSAL PRACTICAL NO 7****************"<<endl;
	cout<<"*************GRAPH REPRENTATION USING ADJACENCY LIST********************"<<endl;
	cout<<"\n________________Prepared by ADITYA THETE(48)_______________\n"<<endl;
	
	graph g;
	g.total();
	cout<<"\n--------------------------------------------------"<<endl;
	g.initialize();
	g.accept();
	cout<<"\n-------------------------------------------------"<<endl;
	g.connectivity();
	cout<<"\n-------------------------------------------------"<<endl;
	g.display();
	cout<<"\n---------------------------THANK YOU !-------------------------"<<endl;
	return 0;
}
