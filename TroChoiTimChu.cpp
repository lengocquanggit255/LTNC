#include <bits/stdc++.h>

using namespace std;

int modulo(int a, int b) {
    int result = abs(a) % abs(b);
    if (a < 0) {
        result = abs(b) - result;
    }
    if (result == abs(b)) {
        result = 0;
    }
    return result;
}

bool checkValid(string word)
{
    for (int i = 0; i < (int)word.size(); i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')continue;
        else return false;
    }
return true;
}

bool checkAround(vector<vector<char>> &table, string &word, int wordLen, int xpos, int ypos, int n, int m)
{
    //ktra ben phai
    string temp;
    int posX = xpos;
    int posY = ypos;
    while ((int)temp.size() < wordLen)
    {   
        temp += table[posX][posY];
        posY = modulo(posY + 1, m);
        
    }
    //cout << posX << " " << posY << endl;
    if(temp == word)
    {
        cout << xpos + 1 << " " << ypos + 1 << " " << xpos + 1 << " " << modulo(ypos + wordLen - 1, m) + 1 << endl;
        return true;
    }

    //ktra phia duoi
    temp = "";
    while ((int)temp.size() < wordLen)
    {   
        temp += table[posX][posY];
        posX = modulo(posX + 1, n);
    }
    if(temp == word)
    {
        cout << xpos + 1 << " " << ypos + 1 << " " << modulo(xpos + wordLen - 1, n) + 1 << " " << ypos + 1 << endl;
        return true;
    }

    //ktra ben trai
    temp = "";
    posX = xpos;
    posY = ypos;
    while ((int)temp.size() < wordLen)
    {   
        temp += table[posX][posY];
        posY = modulo(posY - 1, m);
        
    }
    if(temp == word)
    {
        cout << xpos + 1 << " " << ypos + 1 << " " << xpos + 1  << " " << modulo(ypos - wordLen + 1, m) + 1 << endl;
        return true;
    }

    //ktra phia tren
    temp = "";
    posX = xpos;
    posY = ypos;
    while ((int)temp.size() < wordLen)
    {   
        temp += table[posX][posY];
        posX = modulo(posX - 1, n);
    }
    if(temp == word)
    {
        cout << xpos + 1 << " " << ypos + 1 << " " << modulo(xpos - wordLen + 1, n) + 1 << " " << ypos + 1 << endl;
        return true;
    }

    //ktra goc phan tu t1
    temp = "";
    posX = xpos;
    posY = ypos;
    while ((int)temp.size() < wordLen)
    {   
        temp += table[posX][posY];
        posX = modulo(posX - 1, n);
        posY = modulo(posY + 1, m);
    }
    if(temp == word)
    {
        cout << xpos + 1 << " " << ypos + 1 << " " << modulo(xpos - wordLen + 1, n) + 1 << " " << modulo(ypos + wordLen - 1, m) + 1 << endl;
        return true;
    }
    
    //ktra goc phan tu t4
    temp = "";
    posX = xpos;
    posY = ypos;
    while ((int)temp.size() < wordLen)
    {   
        temp += table[posX][posY];
        posX = modulo(posX + 1, n);
        posY = modulo(posY + 1, m);
    }
    if(temp == word)
    {
        cout << xpos + 1 << " " << ypos + 1 << " " << modulo(xpos + wordLen - 1, n) + 1 << " " << modulo(ypos + wordLen - 1, m) + 1 << endl;
        return true;
    }

    //ktra goc phan tu t2
    temp = "";
    posX = xpos;
    posY = ypos;
    while ((int)temp.size() < wordLen)
    {   
        temp += table[posX][posY];
        posX = modulo(posX - 1, n);
        posY = modulo(posY - 1, m);
    }
    if(temp == word)
    {
        cout << xpos + 1 << " " << ypos + 1 << " " << modulo(xpos - wordLen + 1, n) + 1 << " " << modulo(ypos - wordLen + 1, m) + 1 << endl;
        return true;
    }

    //ktra goc phan tu t3
    temp = "";
    posX = xpos;
    posY = ypos;
    while ((int)temp.size() < wordLen)
    {   
        temp += table[posX][posY];
        posX = modulo(posX + 1, n);
        posY = modulo(posY - 1, m);
    }
    if(temp == word)
    {
        cout << xpos + 1 << " " << ypos + 1 << " " << modulo(xpos + wordLen - 1, n) + 1 << " " << modulo(ypos - wordLen + 1, m) + 1 << endl;
        return true;
    }

return false;
}

void findWord(vector<vector<char>> &table, string &word, int n, int m)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(table[i][j] == word[0]){
                if(checkAround(table, word, (int)word.size(), i, j, n, m))return;
            }
        }
    }
    cout << "not found" << endl;
}

int main(){
    vector<vector<char>> table;
    int n,m; cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        vector<char> temp;
        string tmpStr; cin >> tmpStr;
        for (int j = 0; j < m; j++)
        {
            temp.push_back(tmpStr[j]);
        }
        table.push_back(temp);
    }


    int k; cin >> k;
    cin.ignore();
    while (k != 0)
    {
        string word; getline(cin, word);
        if(!checkValid(word)){
            cout << "input error" << endl;
            k--;
            continue;
        }
        findWord(table, word, n, m);
        k--;
    }
    return 0;
}