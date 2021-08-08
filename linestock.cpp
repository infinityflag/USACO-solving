#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//#define mod 1e9;
typedef long long ll;

vector<string> cows=[]{
vector<string> tmp{
    "Beatrice",
    "Sue",
    "Belinda",
    "Bessie",
    "Betsy",
    "Blue",
    "Bella",
    "Buttercup"
};
sort(begin(tmp), end(tmp));
return tmp;
}();
vector<int> adj[8];
int index(string cow){
    return find(begin(cows), end(cows), cow) - begin(cows);
}

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s1, s2, trash;
        cin >> s1 >> trash >> trash >> trash >> trash >> s2;
        int c1 = index(s1);
        int c2 = index(s2);
        adj[c1].push_back(c2); 
        adj[c2].push_back(c1);
    }

    vector<int> seq;
    vector<bool> done(8);

    for(int i=0;i<8;i++){
        if(!done[i] && adj[i].size() <= 1){
            int cur = i;
            while(adj[cur].size() == 1){
                seq.push_back(cur);
                done[cur] = 1;
                int nex = adj[cur][0];
                adj[nex].erase(find(begin(adj[nex]), end(adj[nex]), cur));
                cur = nex;
            }
            seq.push_back(cur);
            done[cur] = 1;
        }
    }

    for(int i=0;i<seq.size(); i++){
        int t = seq[i];
        cout << cows[t]<<'\n';
    }

}

