#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>

class Participant {
public:
    std::string name;
    int score;
    
    Participant(std::string n, int s);
};

#endif
