#include "bits/stdc++.h"

using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

string newstring = "";
bool flag = false;

int check(int r, int c, vector<vector<int>> &grid) {
    int ret = 0, temp = 0;

    for (int i = 0; i < 3; i++)
        temp += grid[r][i];

    if (temp == 3) ret++;
    temp = 0;

    for (int i = 0; i < 3; i++)
        temp += grid[i][c];
    
    if (temp == 3) ret++;
    temp = 0;

    if (r == c) {
        for (int i = 0; i < 3; i++)
            temp += grid[i][i];

        if (temp == 3) ret++;
        temp = 0;
    }

    if ((r == 0 && c == 2) || (r == 2 && c == 0) 
                           || (r == 1 && c == 1)) {
        for (int i = 0; i < 3; i++)
            temp += grid[i][2 - i];

        if (temp == 3) ret++;
    }

    return ret;
}

void backtrack(int pos, vector<vector<int>> &grid, unordered_map<char, pair<int, int>> &umap, string s, vector<int> &score) {
    if (flag == true) return;
    if (newstring.size() >= 9) {
        flag = true;
        return;
    }

    for (int i = 0; i < 9; i++) {
        if (grid[umap[s[i]].first][umap[s[i]].second] == 1) continue;
        grid[umap[s[i]].first][umap[s[i]].second] = 1;
        if (check(umap[s[i]].first, umap[s[i]].second, grid) == score[pos]) {
            newstring.push_back(s[i]);
            backtrack(pos + 1, grid, umap, s, score);
            if (flag == true) return;
            newstring.pop_back();
        }
        grid[umap[s[i]].first][umap[s[i]].second] = 0;
    }
}

void solve() {
    string s; cin >> s;
    vector<vector<int>> grid(3, vector<int>(3, 0));
    vector<int> score;
    unordered_map<char, pair<int, int>> umap;
    newstring = "";
    flag = false;

    for (int i = 0; i < 3; i++) {
        string temp; cin >> temp;
        for (int j = 0; j < 3; j++) {
            umap[temp[j]] = {i, j};
        }
    }

//calculate score
    for (auto &c : s) {
        grid[umap[c].first][umap[c].second] = 1;
        score.push_back(check(umap[c].first, umap[c].second, grid));
    }

    sort(s.begin(), s.end());
    grid = vector<vector<int>>(3, vector<int>(3, 0));
    
//find root string
    backtrack(0, grid, umap, s, score);

//print ans
    for (auto &item : score) {
        cout << item;
    }
    cout << " ";
    for (auto &item : newstring) {
        cout << item;
    }

    cout << "\n";
}

int main() {
    int test = 0;
    cin >> test;

    while (test--) {
        solve();
    }

    return 0;
}