

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(vector<int>& a, int size);

void sort(vector<int>& a, int size);

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> arr;
        int n;
        cin >> n;
        int max = 0;
        for(int i = 0;i < n;i++){
            int e;
            cin >> e;
            arr.push_back(e);
        }
        sort(arr, arr.size());

        cout << solve(arr, n) << endl;
    }    
}


int solve(vector<int>& a, int size){
    for(int i = 0;i < size; i++){
        while(a[0] < a[i]){
            a[0] = a[0] + 1;
            a[i] = a[i] - 1;
        }
    }
    int max_blocks = a[0];
    return max_blocks;
}

void sort(vector<int>& a, int size){
    sort(a+1, a.size() + a);
}