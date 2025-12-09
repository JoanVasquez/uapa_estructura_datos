#include "../../includes/repositories/RankingRepository.h"
#include <iostream>
#include <algorithm>

RankingRepository::RankingRepository() {}

void RankingRepository::addParticipant(std::string name, int score) {
    participants.push_back(Participant(name, score));
}

void RankingRepository::quickSortByScore(std::vector<Participant>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSortByScore(arr, left, pivotIndex - 1);
        quickSortByScore(arr, pivotIndex + 1, right);
    }
}

int RankingRepository::partition(std::vector<Participant>& arr, int left, int right) {
    int pivot = arr[right].score;
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        if (arr[j].score > pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

std::vector<Participant> RankingRepository::getParticipantsSortedByScore() {
    std::vector<Participant> sortedParticipants = participants;
    
    if (!sortedParticipants.empty()) {
        quickSortByScore(sortedParticipants, 0, sortedParticipants.size() - 1);
    }
    
    return sortedParticipants;
}

int RankingRepository::searchByNameRecursive(std::string name, int index) {
    if (index >= static_cast<int>(participants.size())) {
        return -1;
    }
    
    if (participants[index].name == name) {
        return index;
    }
    
    return searchByNameRecursive(name, index + 1);
}

Participant* RankingRepository::searchParticipant(std::string name) {
    int index = searchByNameRecursive(name, 0);
    
    if (index != -1) {
        return &participants[index];
    }
    
    return nullptr;
}

double RankingRepository::calculateAverageRecursive(int index, int sum, int count) {
    if (index >= static_cast<int>(participants.size())) {
        if (count == 0) return 0.0;
        return static_cast<double>(sum) / count;
    }
    
    return calculateAverageRecursive(index + 1, sum + participants[index].score, count + 1);
}

double RankingRepository::getAverageScore() {
    return calculateAverageRecursive(0, 0, 0);
}

std::vector<Participant> RankingRepository::getAllParticipants() {
    return participants;
}

int RankingRepository::getParticipantCount() {
    return static_cast<int>(participants.size());
}

void RankingRepository::clearParticipants() {
    participants.clear();
}
