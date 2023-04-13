add_executable(example main.cpp hello.pb.cc)

target_link_libraries(example
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${PROTOBUF_LIBRARY}
    nats
    curl
    scyna
)

target_compile_features(example PRIVATE cxx_std_17)