add_llvm_library(LLVMCpu0Desc
  Cpu0MCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  Cpu0Info
  Support


  ADD_TO_COMPONENT
  Cpu0
  )