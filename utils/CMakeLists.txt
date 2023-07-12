
add_subdirectory(libbtpclient)
add_subdirectory(btp_transfer)

add_executable(udpstat udpstat.cpp)
wci_utils(udpstat)
