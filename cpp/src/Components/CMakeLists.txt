target_sources(
    ${EXEC_NAME}
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/Position2D.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Velocity2D.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Glyph.hpp
    ${CMAKE_CURRENT_LIST_DIR}/RotationInterval.hpp
    
)

target_include_directories(
    ${EXEC_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)