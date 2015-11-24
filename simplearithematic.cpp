#include<iostream>

using namespace std;
int look(int tsy[],int t)
{
  int ti=0;
  while(t!=tsy[ti])
    ti++;
  return ti;
}
int main()
{
  int n;
  cout<<"enter number of symbols : ";
  cin>>n;
  int sy[n];

  for(int i=0;i<n;i++)
  {
    char c;
    cin>>c;
    sy[i]=(int )c;
    //cout<<(char)in[i];
  }

  cout<<"\nEnter the probabilities\n";
  float syp[n];
  cin>>syp[0];
  for(int i=1;i<n;i++)
  {
    cin>>syp[i];
    syp[i]+=syp[i-1];
    cout<<(char)sy[i]<<" : "<<syp[i]<<endl;
  }
  cout<<"enter number of characters : ";
  cin>>n;
  int in[n];
  cout<<"\nEnter characters\n";
  string str;
  cin>>str;
  float l=0,u=1,l1,u1;
  string map;
  float tag;
  for(int i=0;i<str.length();i++)
  {
    char tc=str[i];
    int ind=look(sy,(int)tc);
    l1=l+(u-l)*syp[ind-1];
    u1=l+(u-l)*syp[ind];
    l=l1;
    u=u1;

    while(!(l<0.5 && u>0.5))
    {
      if(l<0.5 && u<0.5)
      {
        l=2*l;
        u=2*u;
        map+="0";
      }
      else if(l>0.5 && u>0.5)
      {
        l=2*(l-0.5);
        u=2*(u-0.5);
        map+="1";
      }
      cout<<l<<" "<<u<<endl;
    }
cout<<l<<" "<<u<<endl;
cout<<endl;
  }
  tag=(u+l)/2;
  cout<<map<<" "<<tag;

}
