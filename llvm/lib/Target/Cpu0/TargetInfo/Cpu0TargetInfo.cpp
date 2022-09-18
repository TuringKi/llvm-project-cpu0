#include "Cpu0.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheCpu0Target() {
  static Target TheCpu0Target;
  return TheCpu0Target;
}

extern "C" void LLVMInitializeCpu0TargetInfo() {
  RegisterTarget<Triple::cpu0, /*HasJIT=*/true> X(getTheCpu0Target(),
                                                  "cpu0", "Cpu0", "Cpu0");
}