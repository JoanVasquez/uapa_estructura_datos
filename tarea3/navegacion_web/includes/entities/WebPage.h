#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <string>

class WebPage {
private:
    std::string url;
    std::string title;

public:
    WebPage(const std::string& pageUrl, const std::string& pageTitle = "");
    
    std::string getUrl() const;
    std::string getTitle() const;
    void setTitle(const std::string& pageTitle);
    std::string toString() const;
    bool isValid() const;
};

#endif
