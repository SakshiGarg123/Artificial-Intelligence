#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
#define length 9
void cancel_row(int value,int row,vector<vector<vector<pair<int,bool>>>>&ans,vector<vector<int>>&dup)
{
    for(int j=0; j<length; j++)
    {
        for(int k=0; k<ans[row][j].size(); k++)
        {
            if(ans[row][j][k].first==value &&
                    ans[row][j][k].second==true)
            {
                ans[row][j][k].second=false;
                dup[row][j]--;

                if(row==6 && j==1)
                {
                    cout<<"row"<<value<<dup[row][j]<<endl;
                }
            }
        }
    }
    return;
}
void cancel_column(int value,int column,vector<vector<vector<pair<int,bool>>>>&ans,vector<vector<int>>&dup)
{
    for(int i=0; i<length; i++)
    {
        for(int k=0; k<ans[i][column].size(); k++)
        {
            if(ans[i][column][k].first==value && ans[i][column][k].second==true)
            {
                ans[i][column][k].second=false;
                dup[i][column]--;

                if(i==6 && column==1)
                {
                    cout<<"col"<<value<<dup[i][column]<<endl;
                }

            }
        }
    }
    return;
}

void cancel_box(int value,int row,int column,vector<vector<vector<pair<int,bool>>>>&ans,vector<vector<int>>&dup)
{
    int new_column=column%3;
    int new_row=row/3;
    if(new_column==0)
    {
        for(int i=0; i<ans.size(); i++)
        {
            for(int j=0; j<ans[i].size(); j++)
            {
                for(int k=0; k<ans[i][j].size(); k++)
                {
                    if(i/3==new_row&&((j==column)||(j==column+1)||(j==column+2))&&ans[i][j][k].first==value&&ans[i][j][k].second==true)
                    {
                        ans[i][j][k].second=false;
                        dup[i][j]--;

                        if(i==6 && j==1)
                        {
                            cout<<"box"<<value<<dup[i][j]<<endl;
                        }

                    }
                }

            }
        }

    }
    if(new_column==1)
    {
        for(int i=0; i<ans.size(); i++)
        {
            for(int j=0; j<ans[i].size(); j++)
            {
                for(int k=0; k<ans[i][j].size(); k++)
                {
                    if(i/3==new_row&&((j==column)||(j==column+1)||(j==column-1))&&ans[i][j][k].first==value&&ans[i][j][k].second==true)
                    {
                        ans[i][j][k].second=false;
                        dup[i][j]--;

                        if(i==6 && j==1)
                        {
                            cout<<"box"<<value<<dup[i][j]<<endl;
                        }

                    }
                }

            }
        }

    }
    if(new_column==2)
    {
        for(int i=0; i<ans.size(); i++)
        {
            for(int j=0; j<ans[i].size(); j++)
            {
                for(int k=0; k<ans[i][j].size(); k++)
                {
                    if(i/3==new_row&&(j==column||j==column-1||j==column-2)&&ans[i][j][k].first==value && ans[i][j][k].second==true)
                    {
                        ans[i][j][k].second=false;
                        dup[i][j]--;

                        if(i==6 && j==1)
                        {
                            cout<<"box"<<value<<dup[i][j]<<endl;
                        }

                    }
                }

            }
        }

    }
    return;
}
vector<vector<vector<pair<int,bool>>>> domain_values(vector<vector<int>>input,vector<vector<int>>&dup)
{
    vector<pair<int,bool>>temp;
    vector<vector<vector<pair<int,bool>>>>ans(length, vector<vector<pair<int,bool>>>(length, vector<pair<int,bool>>(length)));
    for(int i=1; i<=9; i++)
    {
        temp.push_back({i,true});
    }
    for(int i=0; i<input.size(); i++)
    {
        for(int j=0; j<input[i].size(); j++)
        {
            ans[i][j]=temp;
        }
    }
    for(int i=0; i<input.size(); i++)
    {
        for(int j=0; j<input[i].size(); j++)
        {
            if(input[i][j]!=0)
            {
                cancel_row(input[i][j],i,ans,dup);
                cancel_column(input[i][j],j,ans,dup);
                cancel_box(input[i][j],i,j,ans,dup);
            }
        }
    }
    return ans;
}

pair<int,int>min(vector<vector<int>>dup,vector<vector<int>>input)
{
    int maxi=INT_MAX;
    int ansi,ansj;
    for(int i=0; i<input.size(); i++)
    {
        for(int j=0; j<input[i].size(); j++)
        {
            if(input[i][j]==0&&maxi>dup[i][j])
            {
                maxi=dup[i][j];
                ansi=i;
                ansj=j;
            }
        }
    }
    if(maxi==INT_MAX)
    {
        return {-1,-1};
    }
    return {ansi,ansj};

}
bool solver(vector<vector<int>>&input,vector<vector<vector<pair<int,bool>>>>domain,vector<vector<int>>dup)
{
    ///break
    pair<int,int>index=min(dup,input);
    cout<<"min "<<index.first<<" "<<index.second<<endl;
    if(index.first==-1)
    {
        cout<<"truebase";
        return true;
    }
    if(dup[index.first][index.second]==0)
    {
        cout<<"falsebase";
        return false;
    }
    for(int i=0; i<9; i++)
    {
        if(domain[index.first][index.second][i].second==true)
        {
            cout<<domain[index.first][index.second][i].first<<endl;
            vector<vector<int>> dup2 = dup;
            vector<vector<vector<pair<int,bool>>>>domain2=domain;
            input[index.first][index.second]=domain2[index.first][index.second][i].first;
            int value = domain2[index.first][index.second][i].first;
            ///cancel->what all i cancelled
            cancel_row(value,index.first,domain2,dup2);
            cancel_column(value,index.second,domain2,dup2);
            cancel_box(value,index.first,index.second,domain2,dup2);
            for(int i=0; i<dup2.size(); i++)
            {
                for(int j=0; j<dup2[i].size(); j++)
                {
                    cout<<dup2[i][j]<<" ";
                }
                cout<<endl;
            }

            ///update prirotiy queue
            ///call
            bool valid = solver(input,domain2,dup2);
            ///backtrackking
            if(valid)
            {
                cout<<"trueinner";
                return true;
            }
        }
    }
    input[index.first][index.second]=0;
    cout<<"falselast";
    return false;
}

void print_sudoku(vector<vector<int>>input)
{
    for(int i=0; i<input.size(); i++)
    {
        for(int j=0; j<input[i].size(); j++)
        {
            if(j%3==2)
                cout<<input[i][j]<<"  ";
            else
                cout<<input[i][j]<<" ";
        }
        if(i%3==2)
            cout<<endl<<endl;
        else
            cout<<endl;
    }
}
int main()
{
    vector<vector<int>>input(length);
    vector<int>temp(length);
    cout<<"pushing temp"<<endl;
    for(int i=0; i<9; i++)
    {
        input[i]=temp;
    }
    cout<<"pushed temp"<<endl;
    input[0][1]=2;
    input[1][3]=6;
    input[1][8]=3;
    input[2][1]=7;
    input[2][2]=4;
    input[2][4]=8;


    input[3][5]=3;
    input[3][8]=2;
    input[4][1]=8;
    input[4][4]=4;
    input[4][7]=1;
    input[5][0]=6;
    input[5][3]=5;

    input[6][4]=1;
    input[6][6]=7;
    input[6][7]=8;
    input[7][0]=5;
    input[7][5]=9;
    input[8][7]=4;

    print_sudoku(input);

    vector<vector<int>>dup;
    vector<int> temp2(9,9);
    for(int i=0; i<9; i++)
    {
        dup.push_back(temp2);
    }

    vector<vector<vector<pair<int,bool>>>>domain=domain_values(input,dup);
    cout<<endl;
    for(int i=0; i<input.size(); i++)
    {
        for(int j=0; j<input[i].size(); j++)
        {
            cout<<dup[i][j]<<" ";
        }
        cout<<endl;
    }

    bool ans=solver(input,domain,dup);
    cout<<ans<<endl;
    print_sudoku(input);
    return 0;
}



