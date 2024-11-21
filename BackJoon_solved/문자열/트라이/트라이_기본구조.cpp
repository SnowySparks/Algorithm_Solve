#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;


struct Trie {
    bool isend = false;
    Trie *child[26]; //다음 노드로 이동하기 위한 것. 알파벳 값

    Trie() : isend(false) { //생성자
        memset(child, 0, sizeof(child))
    }
    ~Trie() { //소멸자
        for (int i = 0 ; i < 26; ++i) {
            if (child[i]) delete child[i];
        }
    }

    //문자열 탐색
    Trie* find(const char *key) {
        if (*key == 0) {
            return 
        }
        int index = char_to_index(*key);
        if (child[index] == 0) return NULL;
        return child[index]->find(key+1)
    }

    void *insert(char *str) {
        if (*str == NULL) {
            this -> isend = true; //str끝자락 -> 현재 위치가 종료란 뜻
            return;
        }
        int idx = *str - 'A';
        if (child[idx] == NULL) child[idx] = new Trie();
        child[idx]->insert(str + 1);
    }
};

