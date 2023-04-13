FILE(GLOB ScynaSources *.cpp proto/generated/*.cc)
add_library(scyna ${ScynaSources})

target_link_libraries(scyna
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${PROTOBUF_LIBRARY}
    nats
    curl
)

target_compile_features(scyna PRIVATE cxx_std_17)