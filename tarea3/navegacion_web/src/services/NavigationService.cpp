#include "services/NavigationService.h"
#include <sstream>

NavigationService::NavigationService(HistoryRepository* repo) : repository(repo) {}

NavigationService::~NavigationService() {
    delete repository;
}

bool NavigationService::visit(const std::string& url) {
    return repository->visitPage(url);
}

bool NavigationService::back() {
    return repository->goBack();
}

bool NavigationService::forward() {
    return repository->goForward();
}

std::string NavigationService::getCurrentPageInfo() const {
    WebPage* current = repository->getCurrentPage();
    if (current == nullptr) {
        return "No hay pagina actual";
    }
    return "Pagina actual: " + current->toString();
}

std::string NavigationService::getBackHistoryInfo() const {
    int count = 0;
    WebPage** backPages = repository->getBackHistory(count);
    
    std::stringstream ss;
    ss << "Historial atras: [";
    for (int i = 0; i < count; i++) {
        ss << backPages[i]->toString();
        if (i < count - 1) {
            ss << ", ";
        }
    }
    ss << "]";
    
    return ss.str();
}

std::string NavigationService::getForwardHistoryInfo() const {
    int count = 0;
    WebPage** forwardPages = repository->getForwardHistory(count);
    
    std::stringstream ss;
    ss << "Historial adelante: [";
    for (int i = 0; i < count; i++) {
        ss << forwardPages[i]->toString();
        if (i < count - 1) {
            ss << ", ";
        }
    }
    ss << "]";
    
    return ss.str();
}

std::string NavigationService::getFullStatus() const {
    std::stringstream ss;
    ss << getCurrentPageInfo() << "\n";
    ss << getBackHistoryInfo() << "\n";
    ss << getForwardHistoryInfo();
    return ss.str();
}

bool NavigationService::hasCurrentPage() const {
    return repository->getCurrentPage() != nullptr;
}
