#include "entities/Box.h"
#include <sstream>
#include <iomanip>

int Box::nextIdNumber = 1;

std::string Box::generateId() {
    std::ostringstream oss;
    oss << "C" << std::setw(3) << std::setfill('0') << nextIdNumber++;
    return oss.str();
}

Box::Box(const std::string& desc) : description(desc) {
    id = generateId();
}

Box::Box(const std::string& boxId, const std::string& desc) 
    : id(boxId), description(desc) {}

std::string Box::getId() const {
    return id;
}

std::string Box::getDescription() const {
    return description;
}

void Box::setDescription(const std::string& desc) {
    description = desc;
}

std::string Box::toString() const {
    return id + ": " + description;
}

bool Box::isValid() const {
    return !id.empty() && !description.empty();
}
