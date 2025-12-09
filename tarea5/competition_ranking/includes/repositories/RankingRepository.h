#ifndef RANKINGREPOSITORY_H
#define RANKINGREPOSITORY_H

#include "../entities/Participant.h"
#include <string>
#include <vector>

class RankingRepository {
private:
    std::vector<Participant> participants;
    
    void quickSortByScore(std::vector<Participant>& arr, int left, int right);
    int partition(std::vector<Participant>& arr, int left, int right);
    double calculateAverageRecursive(int index, int sum, int count);
    int searchByNameRecursive(std::string name, int index);

public:
    RankingRepository();
    void addParticipant(std::string name, int score);
    std::vector<Participant> getParticipantsSortedByScore();
    Participant* searchParticipant(std::string name);
    double getAverageScore();
    std::vector<Participant> getAllParticipants();
    int getParticipantCount();
    void clearParticipants();
};

#endif
