#include "services/PackingService.h"
#include <sstream>

PackingService::PackingService(QueueRepository* repo) : repository(repo) {}

PackingService::~PackingService() {
    delete repository;
}

bool PackingService::addBox(const std::string& description) {
    if (description.empty()) {
        return false;
    }
    
    Box* newBox = new Box(description);
    return repository->enqueue(newBox);
}

bool PackingService::processBox(std::string& resultMessage) {
    Box* box = repository->dequeue();
    if (box == nullptr) {
        resultMessage = "No hay cajas para procesar";
        return false;
    }
    
    resultMessage = "Procesando caja " + box->toString();
    delete box;
    return true;
}

std::string PackingService::viewQueue() const {
    int boxCount = 0;
    Box** boxes = repository->getAllBoxes(boxCount);
    
    std::stringstream ss;
    
    if (boxCount == 0) {
        ss << "La cola de empaque esta vacia";
    } else {
        ss << "Cola de empaque (" << boxCount << " cajas):\n";
        for (int i = 0; i < boxCount; i++) {
            ss << "  " << (i + 1) << ". " << boxes[i]->toString() << "\n";
        }
    }
    
    delete[] boxes;
    return ss.str();
}

int PackingService::getQueueSize() const {
    return repository->getCount();
}

bool PackingService::isQueueEmpty() const {
    return repository->isEmpty();
}

std::string PackingService::getQueueStatus() const {
    std::stringstream ss;
    ss << "Estado de la cola: " << getQueueSize() << " cajas en espera";
    return ss.str();
}
