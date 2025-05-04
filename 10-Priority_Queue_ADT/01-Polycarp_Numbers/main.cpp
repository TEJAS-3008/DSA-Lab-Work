

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a;
        for(int i = 0;i < n;i++){
            int e;
            cin >> e;
            a.push_back(e);
        }

        unordered_set<int> seen;
        int dups_RtoL = 0;
        for(int i = n - 1;i >= 0;i--){
            if(seen.find(a[i]) == seen.end()){
                dups_RtoL++;
                seen.insert(a[i]);
            }else{
                break;
            }
        }

        cout << n - dups_RtoL << endl;
    }
}

