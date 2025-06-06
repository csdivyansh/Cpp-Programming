#include <iostream>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {

    public:
        TrieNode *root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word) {
            // base case 

            if (word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'a';

            TrieNode* child;

            if (root-> children[index] != NULL) {
                child = root->children[index];
            } else {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //recursion
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word) {
            if (word.length() == 0) {
                return root->isTerminal;
            }

            int index = word[0] - 'a';
            TrieNode * child;

            if (root-> children[index] != NULL) {
                child = root->children[index];
            } else {
                return false;
            }

            return searchUtil(child, word.substr(1));

        }

        bool searchWord(string word){
            return searchUtil(root, word);
        }
};

int main() {

    Trie *t = new Trie();
    t-> insertWord("abcd");
    t-> insertWord("bcd");
    t-> insertWord("cd");
    t-> insertWord("d");

    cout << "Search: " << t->searchWord("abcd") << endl;
    cout << "Search: " << t->searchWord("bcd") << endl;
    cout << "Search: " << t->searchWord("cd") << endl;
    cout << "Search: " << t->searchWord("d") << endl;

    return 0;
}