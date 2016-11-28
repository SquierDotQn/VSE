// ram.h
#include "systemc.h"
SC_MODULE(ram) {
    sc_in<int> addr;
    sc_in<int> datain;
    sc_in<bool> rwb;
    sc_out<int> dout;
    
    int memdata[64];
    int i;
    
    // local memory storage
    void ramread();
    void ramwrite();
    
    SC_CTOR(ram){
        SC_METHOD(ramread);
        sensitive << addr << rwb;
        SC_METHOD(ramwrite)
        sensitive << addr << datain << rwb;
        for (i=0; i++; i<64) {
            memdata[i] = 0;
        }
    }
};
