#include "repositories/HistoryRepository.h"
#include <iostream>

HistoryRepository::HistoryRepository() 
    : backTop(-1), forwardTop(-1), currentPage(nullptr) {
    for (int i = 0; i < MAX_HISTORY; i++) {
        backHistory[i] = nullptr;
        forwardHistory[i] = nullptr;
    }
}

HistoryRepository::~HistoryRepository() {
    clearAll();
}

bool HistoryRepository::isBackFull() const {
    return backTop >= MAX_HISTORY - 1;
}

bool HistoryRepository::isForwardFull() const {
    return forwardTop >= MAX_HISTORY - 1;
}

void HistoryRepository::clearForwardHistory() {
    for (int i = 0; i <= forwardTop; i++) {
        delete forwardHistory[i];
        forwardHistory[i] = nullptr;
    }
    forwardTop = -1;
}

bool HistoryRepository::visitPage(const std::string& url) {
    if (url.empty()) {
        return false;
    }
    
    // Si hay una página actual, la movemos al historial atrás
    if (currentPage != nullptr) {
        if (isBackFull()) {
            // Eliminar la página más antigua (bottom of stack)
            delete backHistory[0];
            // Shift elements
            for (int i = 0; i < backTop; i++) {
                backHistory[i] = backHistory[i + 1];
            }
            backHistory[backTop] = currentPage;
        } else {
            backHistory[++backTop] = currentPage;
        }
    }
    
    // Limpiar historial adelante cuando visitamos nueva página
    clearForwardHistory();
    
    // Crear nueva página actual
    currentPage = new WebPage(url);
    return true;
}

bool HistoryRepository::goBack() {
    if (backTop < 0 || currentPage == nullptr) {
        return false;
    }
    
    // Mover página actual al historial adelante
    if (isForwardFull()) {
        delete forwardHistory[0];
        for (int i = 0; i < forwardTop; i++) {
            forwardHistory[i] = forwardHistory[i + 1];
        }
        forwardHistory[forwardTop] = currentPage;
    } else {
        forwardHistory[++forwardTop] = currentPage;
    }
    
    // Obtener página anterior del historial atrás
    currentPage = backHistory[backTop];
    backHistory[backTop--] = nullptr;
    
    return true;
}

bool HistoryRepository::goForward() {
    if (forwardTop < 0 || currentPage == nullptr) {
        return false;
    }
    
    // Mover página actual al historial atrás
    if (isBackFull()) {
        delete backHistory[0];
        for (int i = 0; i < backTop; i++) {
            backHistory[i] = backHistory[i + 1];
        }
        backHistory[backTop] = currentPage;
    } else {
        backHistory[++backTop] = currentPage;
    }
    
    // Obtener página siguiente del historial adelante
    currentPage = forwardHistory[forwardTop];
    forwardHistory[forwardTop--] = nullptr;
    
    return true;
}

WebPage* HistoryRepository::getCurrentPage() const {
    return currentPage;
}

WebPage** HistoryRepository::getBackHistory(int& count) const {
    count = backTop + 1;
    return const_cast<WebPage**>(backHistory);
}

WebPage** HistoryRepository::getForwardHistory(int& count) const {
    count = forwardTop + 1;
    return const_cast<WebPage**>(forwardHistory);
}

void HistoryRepository::clearAll() {
    for (int i = 0; i <= backTop; i++) {
        delete backHistory[i];
        backHistory[i] = nullptr;
    }
    
    for (int i = 0; i <= forwardTop; i++) {
        delete forwardHistory[i];
        forwardHistory[i] = nullptr;
    }
    
    delete currentPage;
    currentPage = nullptr;
    
    backTop = -1;
    forwardTop = -1;
}
