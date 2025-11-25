#include "entities/WebPage.h"
#include <algorithm>

WebPage::WebPage(const std::string& pageUrl, const std::string& pageTitle) 
    : url(pageUrl), title(pageTitle) {}

std::string WebPage::getUrl() const {
    return url;
}

std::string WebPage::getTitle() const {
    return title.empty() ? url : title;
}

void WebPage::setTitle(const std::string& pageTitle) {
    title = pageTitle;
}

std::string WebPage::toString() const {
    return getTitle();
}

bool WebPage::isValid() const {
    return !url.empty();
}
