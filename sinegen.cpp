#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env){

    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    Vsinegen* top = new Vsinegen;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("sinegen.vcd");

    if(vbdOpen()!=1) return(-1);
    vbdHeader("L2T2: SigGen");

    // Initialize with reset
    top->clk = 1;
    top->rst = 1;
    top->en = 0;
    top->incr = 1;
    top->offset = 64;  // Quarter cycle phase shift

    // Reset sequence
    for (i = 0; i < 5; i++) {
        top->clk = !top->clk;
        top->eval();
    }

    // Remove reset and enable
    top->rst = 0;
    top->en = 1;

    for(i = 0; i < 1000000; i++){
        for(clk = 0; clk < 2; clk++){
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->eval ();
        }

        // Plot both waveforms
        vbdPlot(int(top->dout1), 0, 255);
        vbdPlot(int(top->dout2), 0, 255);
        
        // Update increment from rotary encoder
        top->incr = vbdValue();
        
        vbdCycle(i);

        if((Verilated::gotFinish()) || (vbdGetkey()=='q')){
            exit(0);
        }
    }

    vbdClose();
    tfp->close();
    exit(0);
}
