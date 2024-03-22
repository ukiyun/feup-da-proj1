#ifndef MENU_H
#define MENU_H

#include "fileHandler.h"

class Menu {
public:
    void open();
    bool printUserMenu();
private:
    FileHandler loadedFiles;
    string type_;
};

#endif //MENU_H
