#include "ram.h"

int sc_main(int argc, char* argv[]) {
    try {
        Memory mem("main_memory");
        sc_start();
    } catch (exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
