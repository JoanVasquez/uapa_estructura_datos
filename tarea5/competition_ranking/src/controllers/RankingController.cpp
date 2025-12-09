#include "../../includes/controllers/RankingController.h"
#include <iostream>

void RankingController::executeOption(int option) {
    std::string name;
    int score;
    
    switch (option) {
        case 1:
            std::cout << "Enter participant name: ";
            std::getline(std::cin, name);
            std::cout << "Enter score: ";
            std::cin >> score;
            std::cin.ignore();
            service.addParticipant(name, score);
            break;
        case 2:
            service.displayRanking();
            break;
        case 3:
            std::cout << "Enter participant name to search: ";
            std::getline(std::cin, name);
            service.searchParticipant(name);
            break;
        case 4:
            service.displayAverageScore();
            break;
        case 5:
            service.displayAllParticipants();
            break;
        case 6:
            service.displayStatistics();
            break;
        case 7:
            service.clearParticipants();
            break;
    }
}
