#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;
int n;

vector<string> split(string &res, char splitchar) {
    vector<string> result;
    istringstream ss(res);
    string tmp;
    while (getline(ss,tmp,splitchar))
    {
        result.push_back(tmp);
    }
    return result;
    
}

struct Trie {
    string file = "";
    map<string, Trie* > child;

    void insert(const vector<string> &root, int idx) {
        if (idx == root.size()) {
            return;
        }
        if (child.find(root[idx]) == child.end()) {
            child[root[idx]] = new Trie();
            child[root[idx]]->file = root[idx];
        }
        child[root[idx]]->insert(root, idx+1);
    }

    void print(int height) {
        for (auto info : child) {
            for (int i = 0; i < height; ++i) cout << ' ';
            cout << info.first << '\n';
            info.second->print(height+1);
        }

    }
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    string tmp;
    Trie *root = new Trie();
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        root->insert(split(tmp, '\\'),0);
    }
    root->print(0);
    return 0;
}