add_library(btpclient client.cpp gateway.cpp btpclient.cpp)
target_include_directories(btpclient PUBLIC ${wfc_btp_SOURCE_DIR}/package/ ${wfc_btp_SOURCE_DIR}/libbtp/ ${CMAKE_CURRENT_SOURCE_DIR})
wci_targets(btpclient)
target_link_libraries(btpclient PUBLIC iow wjrpc wlog wflow wfc)
