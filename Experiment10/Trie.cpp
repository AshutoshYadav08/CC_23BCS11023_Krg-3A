#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr) {
                delete children[i];
            }
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    // Inserts a word into the trie.
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a'; // Assumes lowercase English letters
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Returns if the word is in the trie.
    bool search(const string& word) const {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    // Returns if there is any word in the trie that starts with the given prefix.
    bool startsWith(const string& prefix) const {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};

int main() {
    Trie trie;
    
    trie.insert("apple");
    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << "\n";
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << "\n";
    cout << "Starts with 'app': " << (trie.startsWith("app") ? "True" : "False") << "\n";
    
    trie.insert("app");
    cout << "Search 'app' after inserting 'app': " << (trie.search("app") ? "Found" : "Not Found") << "\n";
    
    return 0;
}