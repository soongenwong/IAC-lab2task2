// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsinegen.h for the primary calling header

#include "Vsinegen__pch.h"
#include "Vsinegen__Syms.h"
#include "Vsinegen___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsinegen___024root___dump_triggers__stl(Vsinegen___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsinegen___024root___eval_triggers__stl(Vsinegen___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsinegen___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
