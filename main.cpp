#include <iostream>
#include "Code/include/Menu.h"
#include "Code/include/Graph.h"
#include "Code/include/Utils.h"
#include "Code/include/fileHandler.h"

#include <locale.h>

// Start program

int main() {
    setlocale(LC_ALL, "pt-PT");
    Menu m;
    m.open();
    return 0;
}
