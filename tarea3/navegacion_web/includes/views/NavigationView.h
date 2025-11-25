#ifndef NAVIGATIONVIEW_H
#define NAVIGATIONVIEW_H

#include <string>

class NavigationView {
public:
    static void displayWelcome();
    static void displayGoodbye();
    static void displayError(const std::string& message);
    static void displaySuccess(const std::string& message);
    static void displayMenu();
};

#endif
