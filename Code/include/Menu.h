#ifndef MENU_H
#define MENU_H

#include "fileHandler.h"

class Menu {
public:
    void open();
    bool printUserMenu();
private:

    void displayMainMenu();
    void readAndParseData();
    void determineMaxWaterFlow();
    void verifyWaterNeeds();
    void balanceLoad();
    void resilienceAnalysis();
    void pipelineFailureAnalysis();
    void exitProgram();
    
    FileHandler loadedFiles;
    string type_;
};

#endif //MENU_H
