project ("artxt")

add_executable(artxt 
"src/artxt.cpp"  
"src/sdlw/include/Window.hpp" 
"src/sdlw/include/Renderer.hpp" 
"src/sdlw/Window.cpp" )

# my own path to sdl
set(SDL_PATH "D:/dev/Env/SDL3")

# SDL
set(SDL_LIB "${SDL_PATH}/SDL/lib/x64/SDL3.lib")
set(SDL_INCLUDE "${SDL_PATH}/SDL/include")

# IMAGE
set(SDL_IMAGE_LIB "${SDL_PATH}/Image/lib/x64/SDL3_Image.lib")
set(SDL_IMAGE_INCLUDE "${SDL_PATH}/Image/include")

# TTF
set(SDL_TTF_LIB "${SDL_PATH}/TTF/lib/x64/SDL3_ttf.lib")
set(SDL_TTF_INCLUDE "${SDL_PATH}/TTF/include")

include_directories(
    ${SDL_INCLUDE} 
    ${SDL_IMAGE_INCLUDE} 
    ${SDL_TTF_INCLUDE}
    "src/"
) 
target_link_libraries(artxt ${SDL_LIB} ${SDL_IMAGE_LIB} ${SDL_TTF_LIB})

add_custom_command(TARGET artxt POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/libs $<TARGET_FILE_DIR:artxt>
)
add_custom_command(TARGET artxt POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/content $<TARGET_FILE_DIR:artxt>/content
)