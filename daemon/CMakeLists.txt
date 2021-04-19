
add_executable(btpd btpd.cpp )

target_link_libraries(btpd PRIVATE wfc_btp wfcroot)

wci_targets(btpd)

add_dependencies(btpd wfc_btp wfcroot)

build_info(btpd btpd)

install(TARGETS btpd DESTINATION ${CMAKE_INSTALL_PREFIX})

