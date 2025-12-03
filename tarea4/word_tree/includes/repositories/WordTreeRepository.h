#ifndef WORDTREEREPOSITORY_H
#define WORDTREEREPOSITORY_H

#include "../entities/WordNode.h"
#include <string>
#include <vector>

class WordTreeRepository {
private:
    WordNode* root;
    
    WordNode* insertWord(WordNode* node, std::string word);
    void inorderTraversal(WordNode* node, std::vector<std::string>& words);
    bool searchWord(WordNode* node, std::string word);
    void countWordsPerLevel(WordNode* node, int level, std::vector<int>& levelCounts);
    void destroyTree(WordNode* node);
    int getTreeHeight(WordNode* node);

public:
    WordTreeRepository();
    ~WordTreeRepository();
    void insert(std::string word);
    std::vector<std::string> getWordsAlphabetically();
    bool search(std::string word);
    std::vector<int> getWordsPerLevel();
    int getTotalWords();
};

#endif
