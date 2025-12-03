#include "../../includes/controllers/PrimeTreeController.h"

void PrimeTreeController::executeOption(int option) {
    switch (option) {
        case 1:
            service.buildTree();
            break;
        case 2:
            service.displayPrimesInorder();
            break;
        case 3:
            service.displayLeafCount();
            break;
        case 4:
            service.displayTreeHeight();
            break;
        case 5:
            service.displayAllInformation();
            break;
    }
}
