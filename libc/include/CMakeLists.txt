set(LIBC_INCLUDE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
include(LLVMLibCHeaderRules)

add_subdirectory(llvm-libc-macros)
add_subdirectory(llvm-libc-types)

add_header(
  llvm_libc_common_h
  HDR
    __llvm-libc-common.h
)

add_gen_header(
  ctype
  DEF_FILE ctype.h.def
  GEN_HDR ctype.h
  DEPENDS
    .llvm_libc_common_h
)

add_gen_header(
  dirent
  DEF_FILE dirent.h.def
  GEN_HDR dirent.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-types.DIR
    .llvm-libc-types.ino_t
    .llvm-libc-types.struct_dirent
)

add_gen_header(
  fcntl
  DEF_FILE fcntl.h.def
  GEN_HDR fcntl.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-macros.fcntl_macros
    .llvm-libc-types.mode_t
)

add_gen_header(
  fenv
  DEF_FILE fenv.h.def
  GEN_HDR fenv.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-types.fenv_t
    .llvm-libc-types.fexcept_t
)

add_gen_header(
  inttypes
  DEF_FILE inttypes.h.def
  GEN_HDR inttypes.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-types.imaxdiv_t
)

add_gen_header(
  math
  DEF_FILE math.h.def
  GEN_HDR math.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-types.double_t
    .llvm-libc-types.float_t
)

add_gen_header(
  assert_h
  DEF_FILE assert.h.def
  GEN_HDR assert.h
  DEPENDS
    .llvm_libc_common_h
)

add_gen_header(
  string
  DEF_FILE string.h.def
  GEN_HDR string.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-types.size_t
)

add_gen_header(
  time
  DEF_FILE time.h.def
  GEN_HDR time.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-types.time_t
    .llvm-libc-types.struct_tm
)

add_gen_header(
  threads
  DEF_FILE threads.h.def
  GEN_HDR threads.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-types.__call_once_func_t
    .llvm-libc-types.cnd_t
    .llvm-libc-types.mtx_t
    .llvm-libc-types.once_flag
    .llvm-libc-types.thrd_start_t
    .llvm-libc-types.thrd_t
    .llvm-libc-types.tss_t
    .llvm-libc-types.tss_dtor_t
)

add_gen_header(
  errno
  DEF_FILE errno.h.def
  PARAMS
    platform_errno=../config/${LIBC_TARGET_OS}/errno.h.in
  GEN_HDR errno.h
  DATA_FILES
    ../config/${LIBC_TARGET_OS}/errno.h.in
)

add_gen_header(
  signal
  DEF_FILE signal.h.def
  PARAMS
    platform_signal=../config/${LIBC_TARGET_OS}/signal.h.in
  GEN_HDR signal.h
  DATA_FILES
    ../config/${LIBC_TARGET_OS}/signal.h.in
  DEPENDS
    .llvm-libc-types.struct_sigaction
    .llvm-libc-types.__sighandler_t
)

add_gen_header(
  stdio
  DEF_FILE stdio.h.def
  GEN_HDR stdio.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-macros.file_seek_macros
    .llvm-libc-types.cookie_io_functions_t
    .llvm-libc-types.FILE
    .llvm-libc-types.size_t
)

add_gen_header(
  stdlib
  DEF_FILE stdlib.h.def
  GEN_HDR stdlib.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-types.__bsearchcompare_t
    .llvm-libc-types.__qsortcompare_t
    .llvm-libc-types.div_t
    .llvm-libc-types.ldiv_t
    .llvm-libc-types.lldiv_t
    .llvm-libc-types.size_t
    .llvm-libc-types.__atexithandler_t
)

add_gen_header(
  unistd
  DEF_FILE unistd.h.def
  GEN_HDR unistd.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-macros.file_seek_macros
    .llvm-libc-macros.unistd_macros
    .llvm-libc-types.size_t
    .llvm-libc-types.ssize_t
)

add_gen_header(
  pthread
  DEF_FILE pthread.h.def
  GEN_HDR pthread.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-types.__pthread_start_t
    .llvm-libc-types.__pthread_tss_dtor_t
    .llvm-libc-types.pthread_attr_t
    .llvm-libc-types.pthread_key_t
    .llvm-libc-types.pthread_mutex_t
    .llvm-libc-types.pthread_mutexattr_t
    .llvm-libc-types.pthread_t
)

# TODO: Not all platforms will have a include/sys directory. Add the sys
# directory and the targets for sys/*.h files conditional to the OS requiring
# them.
file(MAKE_DIRECTORY "sys")

add_gen_header(
  sys_mman
  DEF_FILE sys/mman.h.def
  GEN_HDR sys/mman.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-types.off_t
    .llvm-libc-types.ssize_t
)

add_gen_header(
  sys_stat
  DEF_FILE sys/stat.h.def
  GEN_HDR sys/stat.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-macros.sys_stat_macros
    .llvm-libc-types.mode_t
)

add_gen_header(
  sys_sendfile
  DEF_FILE sys/sendfile.h.def
  GEN_HDR sys/sendfile.h
  DEPENDS
    .llvm_libc_common_h
    .llvm-libc-types.off_t
    .llvm-libc-types.ssize_t
)

add_gen_header(
  sys_syscall
  DEF_FILE sys/syscall.h.def
  GEN_HDR sys/syscall.h
  PARAMS
    syscall_numbers=../config/${LIBC_TARGET_OS}/syscall_numbers.h.inc
  DATA_FILES
    ../config/${LIBC_TARGET_OS}/syscall_numbers.h.inc
)

if(NOT LLVM_LIBC_FULL_BUILD)
  # We don't install headers in non-fullbuild mode.
  return()
endif()

function(get_all_install_header_targets out_var)
  set(all_deps ${ARGN})
  foreach(target IN LISTS ARGN)
    get_target_property(deps ${target} DEPS)
    if(NOT deps)
      continue()
    endif()
    list(APPEND all_deps ${deps})
    get_all_install_header_targets(nested_deps ${deps})
    list(APPEND all_deps ${nested_deps})
  endforeach()
  list(REMOVE_DUPLICATES all_deps)
  set(${out_var} ${all_deps} PARENT_SCOPE)
endfunction(get_all_install_header_targets)

get_all_install_header_targets(all_install_header_targets ${TARGET_PUBLIC_HEADERS})
add_custom_target(libc-headers)
add_dependencies(libc-headers ${all_install_header_targets})
foreach(target IN LISTS all_install_header_targets)
  get_target_property(header_file ${target} HEADER_FILE_PATH)
  if(NOT header_file)
    message(FATAL_ERROR "Installable header file '${target}' does not have the "
                        "HEADER_FILE_PATH property set.")
  endif()
  file(RELATIVE_PATH relative_path ${LIBC_INCLUDE_BINARY_DIR} ${header_file})
  get_filename_component(nested_dir ${relative_path} DIRECTORY)
  install(FILES ${header_file}
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${nested_dir}
          COMPONENT ${LIBC_COMPONENT})
endforeach()
