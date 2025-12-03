#ifndef WORDNODE_H
#define WORDNODE_H

#include <string>

class WordNode {
public:
    std::string word;
    WordNode* left;
    WordNode* right;

    WordNode(std::string w);
};

#endif
