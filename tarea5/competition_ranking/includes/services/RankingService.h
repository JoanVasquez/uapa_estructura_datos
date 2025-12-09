#ifndef RANKINGSERVICE_H
#define RANKINGSERVICE_H

#include "../repositories/RankingRepository.h"
#include <string>
#include <vector>

class RankingService {
private:
    RankingRepository repository;

public:
    void addParticipant(std::string name, int score);
    void displayRanking();
    void searchParticipant(std::string name);
    void displayAverageScore();
    void displayAllParticipants();
    void displayStatistics();
    void clearParticipants();
};

#endif
