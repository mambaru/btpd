
add_executable(converter main.cpp)
target_link_libraries(converter PUBLIC btpclient)

add_executable(btpc_merge btpc_merge.cpp)
target_link_libraries(btpc_merge PUBLIC btpclient)

wci_utils(converter btpc_merge)
