#ifndef MENU_H
#define MENU_H

#include "fileHandler.h"

class Menu {
public:
    void open();
    bool printUserMenu();
private:
    fileHandler loadedFiles;
    string type_;
};

v
#endif //MENU_H
