#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int swaps[9][4]={{1,3,0,0},{0,2,4,1},{1,5,2,2},{0,6,4,3},{1,5,7,3},{2,8,4,5},{3,7,6,6},{6,4,8,7},{7,5,8,8}};


struct state
{
	int puzzle[9];
	int stateFn;
	int parent;
};

int compare(state a,state b)
{
	int ret=0;
	for(int i=0;i<9;i++)
		ret+=a.puzzle[i]!=b.puzzle[i];
	return ret;
}

int find0(int g[])
{
	int i;
	for(i=0;i<9 && g[i]!=0;i++);
	return i;
}

void display(vector<state> s)
{
	for (int i=0;i<s.size();i++)
	{
		for(int j=0;j<9;j++){
			if(j!=0 && j%3==0) cout<<endl;
			cout<<s[i].puzzle[j]<<",";
			
			}
		cout<<endl<<endl;
	}
}

int main()
{
	state start;
	state goal;
	int cparent=0;
	for (int i=0;i<9;i++)
		cin>>start.puzzle[i];
	
	for (int i=0;i<9;i++)
		cin>>goal.puzzle[i];
	
	vector<state> travState;
	start.parent=-1;
	travState.push_back(start);
	int counter=0;
	int current=0;
	while(travState.size()!=current && compare(travState[current ],goal))
	{
		//insertNewStates(travState[0],travState);
		cparent=current;
		int pos=find0(travState[current].puzzle);
	
		for(int j=0;j<4;j++)
		{
			if(pos != swaps[pos][j])
			{
			int spos=swaps[pos][j];
			state a;
			
			for(int i=0;i<9;i++)
				a.puzzle[i]=travState[current].puzzle[i];
			
				swap(a.puzzle[pos],a.puzzle[spos]);
				int same=0;
				for(int z=0;z<=current;z++)
					if(compare(travState[z],a)==0)
						same=1;
				if (same==0) {a.parent=current;travState.push_back(a);}
				
			}
			L:;
		}
		display(travState);
		cout<<"-------------------------------"<<endl;
		//if(travState.size()!=0) travState.erase(travState.begin());
		counter++;
		current++;
	}
	cout<<counter<<" itterations";
	int itt=0;
	while(current!=-1){
		itt++;
		current=travState[current].parent;
	}
	cout<<endl<<itt-1;

}
