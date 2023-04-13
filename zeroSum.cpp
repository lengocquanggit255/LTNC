#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;

void zeroSum(vector<int> arr, int n){// kiểm tra vector hiện tại đã tồn tại trong res chưa
    if(n == 3 &&  (arr[0] + arr[1] + arr[2] == 0)){
        auto it = find_if(res.begin(), res.end(), [&](const vector<int>& v) {
            return v.size() == arr.size() && equal(v.begin(), v.end(), arr.begin());
        });

        if (it != res.end()) {
            return;
        } else {
            res.push_back(arr);
        }
    }

    for(int i = 0; i < (int)arr.size(); i++){
        vector<int> temp;
        for (int j = 0; j < (int)arr.size(); j++)
        {
            if(i != j)temp.push_back(arr[j]);
        }
        zeroSum(temp,n-1);
    }
}

int main(){
    int n; cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    zeroSum(arr, n);

    for (int i = 0; i < (int)res.size(); i++)// sắp xếp lại res cho đúng đề bài
    {
        for (int j = i + 1; j < (int)res.size(); j++)
        {
            if (res[i][0] > res[j][0])
            {
                swap(res[i], res[j]);
            }
            if(res[i][0] == res[j][0] && res[i][1] > res[j][1])
            {
                swap(res[i], res[j]);
            }
        }
        
    }
    
    
    for (int i = 0; i < (int)res.size(); i++)// in ra
    {
        for (int j = 0; j < 3; j++)
        {
            cout << res.at(i).at(j) << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
