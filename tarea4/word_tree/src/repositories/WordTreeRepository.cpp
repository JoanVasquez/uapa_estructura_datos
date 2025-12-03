#include "../../includes/repositories/WordTreeRepository.h"
#include <iostream>
#include <algorithm>

WordTreeRepository::WordTreeRepository() : root(nullptr) {}

WordTreeRepository::~WordTreeRepository() {
    destroyTree(root);
}

WordNode* WordTreeRepository::insertWord(WordNode* node, std::string word) {
    if (!node) {
        return new WordNode(word);
    }
    
    if (word < node->word) {
        node->left = insertWord(node->left, word);
    } else if (word > node->word) {
        node->right = insertWord(node->right, word);
    }
    
    return node;
}

void WordTreeRepository::insert(std::string word) {
    root = insertWord(root, word);
}

void WordTreeRepository::inorderTraversal(WordNode* node, std::vector<std::string>& words) {
    if (!node) return;
    
    inorderTraversal(node->left, words);
    words.push_back(node->word);
    inorderTraversal(node->right, words);
}

std::vector<std::string> WordTreeRepository::getWordsAlphabetically() {
    std::vector<std::string> words;
    inorderTraversal(root, words);
    return words;
}

bool WordTreeRepository::searchWord(WordNode* node, std::string word) {
    if (!node) return false;
    
    if (word == node->word) return true;
    
    if (word < node->word) {
        return searchWord(node->left, word);
    } else {
        return searchWord(node->right, word);
    }
}

bool WordTreeRepository::search(std::string word) {
    return searchWord(root, word);
}

void WordTreeRepository::countWordsPerLevel(WordNode* node, int level, std::vector<int>& levelCounts) {
    if (!node) return;
    
    if (level >= levelCounts.size()) {
        levelCounts.push_back(0);
    }
    
    levelCounts[level]++;
    
    countWordsPerLevel(node->left, level + 1, levelCounts);
    countWordsPerLevel(node->right, level + 1, levelCounts);
}

std::vector<int> WordTreeRepository::getWordsPerLevel() {
    std::vector<int> levelCounts;
    countWordsPerLevel(root, 0, levelCounts);
    return levelCounts;
}

int WordTreeRepository::getTreeHeight(WordNode* node) {
    if (!node) return 0;
    
    int leftHeight = getTreeHeight(node->left);
    int rightHeight = getTreeHeight(node->right);
    
    return std::max(leftHeight, rightHeight) + 1;
}

int WordTreeRepository::getTotalWords() {
    std::vector<std::string> words = getWordsAlphabetically();
    return words.size();
}

void WordTreeRepository::destroyTree(WordNode* node) {
    if (!node) return;
    
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}
