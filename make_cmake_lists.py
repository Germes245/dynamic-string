import sys

name_of_project = None

if len(sys.argv) == 1: name_of_project = input("имя проекта: ")
else: name_of_project = sys.argv[1]

#print(name_of_project)
with open("CMakeLists.txt", "w") as file:
    print("""cmake_minimum_required(VERSION 3.10)
project(""", name_of_project, """)

set(CMAKE_C_STANDARD 11)

# Пути вывода (можно оставить как есть)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Собираем список исходников
file(GLOB SOURCE_FILES "src/*.c")

# Создаём разделяемую (динамическую) библиотеку
add_library(""", name_of_project, """ SHARED ${SOURCE_FILES})
target_include_directories(""", name_of_project, """ PRIVATE include)

include(GNUInstallDirs)

# Устанавливаем библиотеку и заголовки
install(TARGETS """, name_of_project, """
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/""", name_of_project, ')', sep="", end="", file=file)