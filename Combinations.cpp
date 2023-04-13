//Bài 3 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> res;

bool compare(string a, string b) {// hàm viết thêm để so sánh cả độ dài và bảng chữ cái
    if (a.length() != b.length()) {
        return a.length() > b.length();
    } else {
        return a < b;
    }
}

void combinations(vector<string> arr, int targetSize, string currentStr){

    if ((int)currentStr.size() <= targetSize && count(res.begin(), res.end(), currentStr) == 0 && currentStr != "")
    {
        res.push_back(currentStr);
    }
    if((int)currentStr.size() > targetSize)return;// điều kiện dừng đệ quy

    for (int i = 0; i < (int)arr.size(); i++)
    {
        combinations(arr, targetSize, currentStr + arr[i]);
    }
}


int main(){
    int n,k; cin >> n >> k;
    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        string temp; cin >> temp; 
        arr.push_back(temp);
    }

    combinations(arr, k, "");
    sort(res.begin(), res.end(), compare);

    for (int i = 0; i < (int)res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}

//Bài 2 #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void combinations(vector<string> arr, int targetSize, string currentStr){

//     if ((int)currentStr.size() == targetSize)
//     {
//         cout << currentStr << endl;
//         return;
//     }

//     for (int i = 0; i < (int)arr.size(); i++)
//     {   
//         if (currentStr.find(arr[i]) == string::npos)
//         {
//             combinations(arr, targetSize, currentStr + arr[i]);   
//         }
//     }
// }


// int main(){
//     int n,k; cin >> n >> k;
//     vector<string> arr;
//     string temp = "a";
//     for (int i = 0; i < n; i++)
//     {
//         arr.push_back(temp);
//         temp[0]++;
//     }

//     combinations(arr, k, "");
    
//     return 0;
// }
