#include<bits/stdc++.h>
using namespace std;
//(row,column)
int n;
int heuristic=0;
int stepsAfterLastRestart= 0;
int stepsClimbed = 0;
int randomRestarts = 0;

vector<pair<int,int> > generateBoard(){
    vector<pair<int,int> > v;
    int i;
    for(i=0;i<n;++i){
        v.push_back(make_pair(rand()%n,i));//time attribute
    }
    return v;
}

bool isConflict(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first || a.second==b.second)
        return true;
    else if(abs(a.second-b.second)==abs(a.first-b.first))
            return true;
    return false;
}

int findHeuristic(vector<pair<int,int> > v){
    int i,j,heuristic = 0;
    for (i=0;i<v.size();i++) {
        for (j=i+1;j<v.size();j++) {
            if(isConflict(v[i],v[j])) {
                heuristic++;
            }
        }
    }
    return heuristic;
}

vector<pair<int,int> > nextBoard(vector<pair<int,int> > presentBoard){
    vector<pair<int,int> > nextBoard(n);
    vector<pair<int,int> > tmpBoard(n);
    int i,j;
    int presentHeuristic = findHeuristic(presentBoard);
    int bestHeuristic = presentHeuristic;
    int tempH;
    for (i=0; i<n; i++) {
        nextBoard[i] = make_pair(presentBoard[i].first,presentBoard[i].second);
        tmpBoard[i] = make_pair(presentBoard[i].first,presentBoard[i].second);
    }

    for (i=0; i<n; i++) {
        if (i>0)
            tmpBoard[i-1] = make_pair(presentBoard[i-1].first,presentBoard[i-1].second);;
        tmpBoard[i] = make_pair(0,tmpBoard[i].second);
        for (j=0; j<n; j++) {
            tempH = findHeuristic(tmpBoard); //Get the heuristic
            if (tempH < bestHeuristic) { //Check if temp board better than best board
                bestHeuristic = tempH;
                for (int k=0; k<n; k++) {
                    nextBoard[k] = make_pair(tmpBoard[k].first,tmpBoard[k].second); //copy
                }
            }
            if (tmpBoard[i].first!=(n-1))
                tmpBoard[i].first++; //Move the queen
        }
    }
    if (bestHeuristic == presentHeuristic) {
        randomRestarts++;
        stepsAfterLastRestart = 0;
        nextBoard = generateBoard();
        heuristic = findHeuristic(nextBoard);
    }
    else
        heuristic = bestHeuristic;
    stepsClimbed++;
    stepsAfterLastRestart++;
    return nextBoard;
}

void printBoard(vector<pair<int,int> > v){
    int i,j;
    cout<<"\nOne of the possible solution is: \n";
    int b[100][100] = {0};
    for(auto it = v.begin(); it!=v.end(); ++it){
        int r = it->first;
        int c = it->second;
        //cout<<r<<" "<<c<<endl;
        b[r][c]=1;
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int presentHeuristic;
    int i,j;
    cout<<"Enter the value of n for n-queen problem: ";
    cin>>n;
    if(n<=3){
        cout<<"No solution exists\n";
        return 0;
    }
    vector<pair<int,int> > presentBoard = generateBoard();
    presentHeuristic = findHeuristic(presentBoard);
    //printBoard(presentBoard);
    while (presentHeuristic != 0){
        presentBoard = nextBoard(presentBoard);
        presentHeuristic  = heuristic;
        //printBoard(presentBoard);
    }
    cout<<"\nTotal number of steps climbed: "<<stepsClimbed<<"\n";
    cout<<"Number of random restarts: "<<randomRestarts<<"\n";
    cout<<"Steps climbed after last restart: "<<stepsAfterLastRestart<<"\n\n";
    printBoard(presentBoard);
    return 0;
}
