#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
map<vector<vector<int>>,int>intialmp;
int helmanhattan(int i,int j,int x)
{
    if(x==0)
        return 0;
    if(x==1)
    {
        return abs(i-0)+abs(j-0);
    }
    if(x==2)
    {
        return abs(i-0)+abs(j-1);
    }
    if(x==3)
    {
        return abs(i-0)+abs(j-2);
    }
    if(x==4)
    {
        return abs(i-1)+abs(j-0);
    }
    if(x==5)
    {
        return abs(i-1)+abs(j-1);
    }
    if(x==6)
    {
        return abs(i-1)+abs(j-2);
    }
    if(x==7)
    {
        return abs(i-2)+abs(j-0);
    }
    if(x==8)
    {
        return abs(i-2)+abs(j-1);
    }

}
int calcmanhattan(vector<vector<int>>v)
{
    int sum=0;
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            sum=sum+helmanhattan(i,j,v[i][j]);
        }
    }
    return sum;
}
void print(vector<vector<int>>v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}
map<vector<vector<int> >,vector<vector<int> >>parent;
int rec(int x,int y,int cs,vector<vector<int> >v,priority_queue<pair<pair<pair<int,vector<vector<int> > >,pair<int,int> >,pair<int,int> >,vector<pair<pair<pair<int,vector<vector<int> > >,pair<int,int> >,pair<int,int> >> , greater<pair<pair<pair<int,vector<vector<int> > >,pair<int,int> >,pair<int,int> >> >pq,map<vector<vector<int> >,bool>mp)
{
    int ans=0;
    int count=20;
    int moves=0;
    pq.push({{{cs+moves,v},{x,y}},{cs,moves}});
    int net_heurestic;
    while(!pq.empty()&&cs!=0)
    {
        pair<pair<pair<int,vector<vector<int> > >,pair<int,int> >,pair<int,int> > front1=pq.top();
        pq.pop();
        count--;
        x=front1.first.second.first;
        y=front1.first.second.second;
        v=front1.first.first.second;
        net_heurestic=front1.first.first.first;
        cs=front1.second.first;
        moves=front1.second.second;
        if(mp[v]==true)
            continue;
        else
        {
            // cout<<"count is : "<<count<<endl;
//            cout<<"popping position blank x,y and current score"<<x<<" , "<<y<<"  "<<cs<<endl;
//            cout<<"printing vector"<<endl;
            print(v);
            if(cs==0)
            {
                cout<<"finished job"<<endl;
                vector<vector<int>>finalans=v;
                int countnew=0;
                while(intialmp.find(finalans)==intialmp.end()&&countnew<8)
                {
                    print(parent[finalans]);
                    cout<<countnew<<endl;
                    finalans=parent[finalans];
                    countnew++;
                }
                ///break;
                return net_heurestic;
            }

            ans++;
            mp[v]=true;
        }

        vector<vector<int> >newv=v;
        if(x==0)
        {
            if(y==0)
            {

                swap(v[x][y],v[0][1]);
                int ns1=calcmanhattan(v);

                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns1+moves+1,v},{0,1}},{ns1,moves+1}});
                }
                swap(v[x][y],v[0][1]);

                swap(v[x][y],v[1][0]);

                int ns2=calcmanhattan(v);
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns2+moves+1,v},{1,0}},{ns2,moves+1}});
                }

                //pq.push({{ns2,v},{1,0}});
                swap(v[x][y],v[1][0]);

            }
            if(y==1)
            {
                swap(v[x][y],v[0][0]);
                int ns1=calcmanhattan(v);

                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns1+moves+1,v},{0,0}},{ns1,moves+1}});
                }

                //pq.push({{ns1,v},{0,0}});
                swap(v[x][y],v[0][0]);

                swap(v[x][y],v[1][1]);
                int ns2=calcmanhattan(v);

                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns2+moves+1,v},{1,1}},{ns2,moves+1}});
                }

                //pq.push({{ns2,v},{1,1}});
                swap(v[x][y],v[1][1]);

                swap(v[x][y],v[0][2]);

                int ns3=calcmanhattan(v);
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns3+moves+1,v},{0,2}},{ns3,moves+1}});
                }

                //pq.push({{ns3,v},{0,2}});
                swap(v[x][y],v[0][2]);

            }
            else
            {
                swap(v[x][y],v[0][1]);

                int ns1=calcmanhattan(v);
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns1+moves+1,v},{0,1}},{ns1,moves+1}});
                }

                //pq.push({{ns1,v},{0,1}});
                swap(v[x][y],v[0][1]);

                swap(v[x][y],v[1][2]);

                int ns2=calcmanhattan(v);
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns2+moves+1,v},{1,2}},{ns2,moves+1}});
                }

                //pq.push({{ns2,v},{1,2}});
                swap(v[x][y],v[1][2]);

            }

        }
        if(x==1)
        {
            if(y==0)
            {
                swap(v[x][y],v[0][0]);

                int ns1=calcmanhattan(v);
                //pq.push({{ns1,v},{0,0}});
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns1+moves+1,v},{0,0}},{ns1,moves+1}});
                }

                swap(v[x][y],v[0][0]);

                swap(v[x][y],v[1][1]);

                int ns2=calcmanhattan(v);
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns2+moves+1,v},{1,1}},{ns2,moves+1}});
                }
                //pq.push({{ns2,v},{1,1}});
                swap(v[x][y],v[1][1]);

                swap(v[x][y],v[2][0]);

                int ns3=calcmanhattan(v);
                //pq.push({{ns3,v},{2,0}});
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns3+moves+1,v},{2,0}},{ns3,moves+1}});
                }
                swap(v[x][y],v[2][0]);

            }
            if(y==1)
            {
                swap(v[x][y],v[0][1]);

                int ns1=calcmanhattan(v);
                //pq.push({{ns1,v},{0,1}});
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns1+moves+1,v},{0,1}},{ns1,moves+1}});
                }
                swap(v[x][y],v[0][1]);

                swap(v[x][y],v[1][2]);

                int ns3=calcmanhattan(v);
                //pq.push({{ns3,v},{1,2}});
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns3+moves+1,v},{1,2}},{ns3,moves+1}});
                }

                swap(v[x][y],v[1][2]);

                swap(v[x][y],v[1][0]);

                int ns2=calcmanhattan(v);
                //pq.push({{ns2,v},{1,0}});
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns2+moves+1,v},{1,0}},{ns2,moves+1}});
                }

                swap(v[x][y],v[1][0]);

                swap(v[x][y],v[2][1]);

                int ns4=calcmanhattan(v);
                //pq.push({{ns4,v},{2,1}});
                if(mp[v]!=true)
                {
                    parent[v]=newv;

                    pq.push({{{ns4+moves+1,v},{2,1}},{ns4,moves+1}});

                }
                swap(v[x][y],v[2][1]);

            }
            else
            {
                swap(v[x][y],v[0][2]);
                int ns1=calcmanhattan(v);

                //pq.push({{ns1,v},{0,2}});
                if(mp[v]!=true)
                {
                    parent[v]=newv;

                    pq.push({{{ns1+moves+1,v},{0,2}},{ns1,moves+1}});
                }
                swap(v[x][y],v[0][2]);

                swap(v[x][y],v[1][1]);
                int ns2=calcmanhattan(v);

                //pq.push({{ns2,v},{1,1}});
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns2+moves+1,v},{1,1}},{ns2,moves+1}});
                }
                swap(v[x][y],v[1][1]);

                swap(v[x][y],v[2][2]);
                int ns3=calcmanhattan(v);

                //pq.push({{ns3,v},{2,2}});
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns3+moves+1,v},{2,2}},{ns3,moves+1}});
                }
                swap(v[x][y],v[2][2]);
            }
        }
        else
        {
            if(y==0)
            {
                swap(v[x][y],v[2][1]);
                int ns1=calcmanhattan(v);
                //pq.push({{ns1,v},{2,1}});
                if(mp[v]!=true)
                {
                    parent[v]=newv;
                    pq.push({{{ns1+moves+1,v},{2,1}},{ns1,moves+1}});
                }

                swap(v[x][y],v[2][1]);

                swap(v[x][y],v[1][0]);
                int ns2=calcmanhattan(v);
                //pq.push({{ns2,v},{1,0}});
                if(mp[v]!=true)
                {
                    pq.push({{{ns2+moves+1,v},{1,0}},{ns2,moves+1}});
                    parent[v]=newv;
                }

                swap(v[x][y],v[1][0]);

            }
            if(y==1)
            {
                swap(v[x][y],v[2][0]);
                int ns1=calcmanhattan(v);
                //pq.push({{ns1,v},{2,0}});
                if(mp[v]!=true)
                {

                    pq.push({{{ns1+moves+1,v},{2,0}},{ns1,moves+1}});
                    parent[v]=newv;
                }
                swap(v[x][y],v[2][0]);

                swap(v[x][y],v[1][1]);
                int ns2=calcmanhattan(v);
                //pq.push({{ns2,v},{1,1}});
                if(mp[v]!=true)
                {
                    pq.push({{{ns2+moves+1,v},{1,1}},{ns2,moves+1}});
                    parent[v]=newv;
                }

                swap(v[x][y],v[1][1]);

                swap(v[x][y],v[2][2]);
                int ns3=calcmanhattan(v);
                //pq.push({{ns3,v},{2,2}});
                if(mp[v]!=true)
                {

                    pq.push({{{ns3+moves+1,v},{2,2}},{ns3,moves+1}});
                    parent[v]=newv;
                }
                swap(v[x][y],v[2][2]);

            }
            else
            {
                swap(v[x][y],v[2][1]);
                int ns1=calcmanhattan(v);
                //pq.push({{ns1,v},{2,1}});
                if(mp[v]!=true)
                {

                    pq.push({{{ns1+moves+1,v},{2,1}},{ns1,moves+1}});
                    parent[v]=newv;

                }
                swap(v[x][y],v[2][1]);

                swap(v[x][y],v[1][2]);
                int ns2=calcmanhattan(v);
                //pq.push({{ns2,v},{1,2}});
                if(mp[v]!=true)
                {

                    pq.push({{{ns2+moves+1,v},{1,2}},{ns2,moves+1}});
                    parent[v]=newv;
                }
                swap(v[x][y],v[1][2]);

            }

        }
    }
    return ans;
}
int main()
{
    vector<vector<int>>v(3);
    int n=9;
    int x=0;
    int y=0;
    int a;
    cout<<"Blank is denoted by a zero"<<endl;
    cout<<"Enter the 9 nos :"<<endl;
    pair<int,int>intial;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        v[x].push_back(a);
        if(a==0)
        {
            intial= {x,y};
        }
        y++;
        if(y==3)
        {
            x++;
        }
        y=y%3;
    }
    print(v);

    intialmp[v]=1;
    cout<<"Intial Value of Board"<<endl;
    cout<<calcmanhattan(v)<<endl;

    cout<<"Intial Position Of Blank"<<endl;
    cout<<intial.first<<" "<<intial.second<<endl;

    map<vector<vector<int>>,bool>mp;
    priority_queue<pair<pair<pair<int,vector<vector<int> > >,pair<int,int> >,pair<int,int> >,vector<pair<pair<pair<int,vector<vector<int> > >,pair<int,int> >,pair<int,int> >> , greater<pair<pair<pair<int,vector<vector<int> > >,pair<int,int> >,pair<int,int> >> >pq;
    int moves=rec(intial.first,intial.second,calcmanhattan(v),v,pq,mp);
    cout<<"No of moves= "<<moves<<endl;
    return 0 ;
}
///imput
/*1
2
3
4
0
5
7
6
8
internet copied
0
1
3
4
2
5
7
8
6
assignment copied
0
1
3
4
2
5
7
8
6
second version
4
1
3
0
2
5
7
8
6

*/

