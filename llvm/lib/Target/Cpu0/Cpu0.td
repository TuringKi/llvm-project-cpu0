
include "llvm/Target/Target.td"

def Cpu0InstrInfo : InstrInfo;



def Cpu0 : Target {
  // def Cpu0InstrInfo : InstrInfo as before.
  let InstructionSet = Cpu0InstrInfo;
}