#ifndef BOX_H
#define BOX_H

#include <string>

class Box {
private:
    std::string id;
    std::string description;
    static int nextIdNumber;

    std::string generateId();

public:
    Box(const std::string& desc = "");
    Box(const std::string& boxId, const std::string& desc);
    
    std::string getId() const;
    std::string getDescription() const;
    void setDescription(const std::string& desc);
    std::string toString() const;
    bool isValid() const;
};

#endif
