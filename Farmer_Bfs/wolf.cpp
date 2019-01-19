#include<iostream>
#include<map>
#include<vector>
using namespace std ;
int flag=1;
int ans = 0;
void bfs(int a,int b,int c,int d,map<pair<pair<int,int>,pair<int,int> >,int>mp,vector<pair<pair<int,int>,pair<int,int> > >finalans)
{
    ///already visited
    if(flag==0)
        return ;
    cout<<"Inside dfs "<<a<<b<<c<<d<<endl;
    if(mp.find({{a,b},{c,d}})!=mp.end())
        {
            cout<<"This state exist"<<endl;
            return ;
        }


    ///goal is reached
    if(a==1&&b==1&&c==1&d==1)
    {
        flag=0;
        cout<<"Reached final state"<<endl;
        finalans.push_back({{a,b},{c,d}});
        for(int i=0; i<finalans.size(); i++)
        {
            cout<<finalans[i].first.first<<finalans[i].first.second<<finalans[i].second.first<<finalans[i].second.second<<endl;
        }
        ans = 1;
        return;
    }

    ///unsafe states
    if(b==c&a!=b)
    {
        cout<<"goat eats cabbage"<<endl;
        return;
    }
    if(c==d&a!=c)
    {
        cout<<"wolf eats goat"<<endl;
        return;
    }
    ///putting inside map
    mp[ {{a,b},{c,d}}]=1;
    finalans.push_back({{a,b},{c,d}});
    cout<<"Exploring boat is on side "<<a<<endl;
    if(a==0)
    {
        if(b==0)
        {
            cout<<"Taking away cabbage"<<a<<endl;
            bfs(1,1,c,d,mp,finalans);
        }
        if(c==0)
        {
            cout<<"Taking away goat"<<a<<endl;
            bfs(1,b,1,d,mp,finalans);

        }
        if(d==0)
        {
            cout<<"Taking away wolf"<<a<<endl;
            bfs(1,b,c,1,mp,finalans);

        }
        if(1)
        {
            bfs(1,b,c,d,mp,finalans);
        }
        ///exploring without taking any
    }
    else
    {
        if(b==1)
        {
            cout<<"Taking away cabbage"<<a<<endl;
            bfs(0,0,c,d,mp,finalans);

        }
        if(c==1)
        {
            cout<<"Taking away goat"<<a<<endl;
            bfs(0,b,0,d,mp,finalans);
        }
        if(d==1)
        {
            cout<<"Taking away wolf"<<a<<endl;
            bfs(0,b,c,0,mp,finalans);
        }
        if(1)
        {
            bfs(0,b,c,d,mp,finalans);
        }
    }
    //finalans.pop_back();
    cout<<endl;
    return ;
}
int main ()
{
    ///Possible moves
    ///1->boat
    ///cabbage
    ///goat
    ///wolf
    map<pair<pair<int,int>,pair<int,int> >,int>mp;
    vector<pair<pair<int,int>,pair<int,int>>>finalans;
    bfs(0,0,0,0,mp,finalans);
    //finalans[finalans.size()-3]={{1,1},{0,1}};
    for(int i=0; i<finalans.size(); i++)
    {
        cout<<finalans[i].first.first<<finalans[i].first.second<<finalans[i].second.first<<finalans[i].second.second<<endl;
    }
    /*
    Farmer takes Goat across (leaving Wolf and Cabbage behind)
    Farmer returns alone
    Farmer takes Wolf across
    Farmer returns with Goat
    Farmer takes Cabbage across
    Farmer returns alone
    Farmer takes Goat across
    */
    return 0 ;
}
