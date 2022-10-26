set(GTEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/gtest)
include_directories(${GTEST_DIR}/include)

# add_executable(testMatrice
#     TestMatrice.cpp
# )

add_executable(testFilehandler
    TestFilehandler.cpp
)

add_executable(testErrorHandler
    TestErrorHandler.cpp
)

add_executable(testDataConverter
    TestDataConverter.cpp
)

# target_link_libraries(testMatrice PUBLIC declutter pthread ${GTEST_DIR}/lib/libgtest_main.a ${GTEST_DIR}/lib/libgtest.a)
target_link_libraries(testFilehandler PUBLIC declutter pthread ${GTEST_DIR}/lib/libgtest_main.a ${GTEST_DIR}/lib/libgtest.a)
target_link_libraries(testErrorHandler PUBLIC declutter pthread ${GTEST_DIR}/lib/libgtest_main.a ${GTEST_DIR}/lib/libgtest.a)
target_link_libraries(testDataConverter PUBLIC declutter pthread ${GTEST_DIR}/lib/libgtest_main.a ${GTEST_DIR}/lib/libgtest.a)