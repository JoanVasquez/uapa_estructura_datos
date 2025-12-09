#include "../../includes/services/RankingService.h"
#include <iostream>
#include <iomanip>

void RankingService::addParticipant(std::string name, int score) {
    repository.addParticipant(name, score);
    std::cout << "Participant '" << name << "' added with score: " << score << "\n";
}

void RankingService::displayRanking() {
    std::vector<Participant> ranking = repository.getParticipantsSortedByScore();
    
    if (ranking.empty()) {
        std::cout << "No participants in the competition.\n";
        return;
    }
    
    std::cout << "=== COMPETITION RANKING ===\n";
    std::cout << std::left << std::setw(5) << "Rank" 
              << std::setw(20) << "Name" 
              << std::setw(10) << "Score" << "\n";
    std::cout << std::string(35, '-') << "\n";
    
    for (size_t i = 0; i < ranking.size(); i++) {
        std::cout << std::left << std::setw(5) << i + 1
                  << std::setw(20) << ranking[i].name
                  << std::setw(10) << ranking[i].score << "\n";
    }
}

void RankingService::searchParticipant(std::string name) {
    Participant* participant = repository.searchParticipant(name);
    
    if (participant) {
        std::cout << "Participant found:\n";
        std::cout << "Name: " << participant->name << "\n";
        std::cout << "Score: " << participant->score << "\n";
    } else {
        std::cout << "Participant '" << name << "' not found.\n";
    }
}

void RankingService::displayAverageScore() {
    double average = repository.getAverageScore();
    std::cout << "Average score of all participants: " << std::fixed << std::setprecision(2) << average << "\n";
}

void RankingService::displayAllParticipants() {
    std::vector<Participant> participants = repository.getAllParticipants();
    
    if (participants.empty()) {
        std::cout << "No participants in the competition.\n";
        return;
    }
    
    std::cout << "=== ALL PARTICIPANTS ===\n";
    std::cout << "Total participants: " << participants.size() << "\n\n";
    
    for (size_t i = 0; i < participants.size(); i++) {
        std::cout << i + 1 << ". " << participants[i].name << " - Score: " << participants[i].score << "\n";
    }
}

void RankingService::displayStatistics() {
    int count = repository.getParticipantCount();
    double average = repository.getAverageScore();
    
    std::cout << "=== COMPETITION STATISTICS ===\n";
    std::cout << "Total participants: " << count << "\n";
    std::cout << "Average score: " << std::fixed << std::setprecision(2) << average << "\n";
    
    if (count > 0) {
        std::vector<Participant> ranking = repository.getParticipantsSortedByScore();
        std::cout << "\nTop 3 participants:\n";
        for (int i = 0; i < std::min(3, count); i++) {
            std::cout << i + 1 << ". " << ranking[i].name << " - " << ranking[i].score << " points\n";
        }
    }
}

void RankingService::clearParticipants() {
    repository.clearParticipants();
    std::cout << "All participants cleared.\n";
}
