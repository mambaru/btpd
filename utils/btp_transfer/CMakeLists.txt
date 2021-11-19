
add_executable(btp_stat btp_stat.cpp)
target_link_libraries(btp_stat PUBLIC btpclient)

add_executable(btp_transfer btp_transfer.cpp)
target_link_libraries(btp_transfer PUBLIC btpclient)

wci_utils(btp_stat btp_transfer)
