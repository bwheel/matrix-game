target_sources(
    ${EXEC_NAME}
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/components.h
    ${CMAKE_CURRENT_LIST_DIR}/globals.h
)

target_include_directories(
    ${EXEC_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

include(${CMAKE_CURRENT_LIST_DIR}/Systems/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/Components/CMakeLists.txt)