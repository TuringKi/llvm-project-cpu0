#include "Cpu0TargetMachine.h"
#include "Cpu0.h"


#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetPassConfig.h"


using namespace llvm;

#define DEBUG_TYPE "cpu0"

extern "C" void LLVMInitializeCpu0Target() {
}