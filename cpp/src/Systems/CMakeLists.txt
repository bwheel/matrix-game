target_sources(
    ${EXEC_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/ISystem.hpp
    
    ${CMAKE_CURRENT_LIST_DIR}/FallSystem.hpp
    ${CMAKE_CURRENT_LIST_DIR}/FallSystem.cpp

    ${CMAKE_CURRENT_LIST_DIR}/RenderSystem.hpp
    ${CMAKE_CURRENT_LIST_DIR}/RenderSystem.cpp
    
    
    ${CMAKE_CURRENT_LIST_DIR}/RotationSystem.hpp
    ${CMAKE_CURRENT_LIST_DIR}/RotationSystem.cpp
)

target_include_directories(
    ${EXEC_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)