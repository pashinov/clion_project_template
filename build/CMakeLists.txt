# Сборочный файл для программы

# Минимальная версия CMake
cmake_minimum_required( VERSION 3.5 )

# Используемый в исходном коде стандарт языка C++
set ( CMAKE_CXX_STANDARD 14 )

set ( CMAKE_CXX_STANDARD_REQUIRED on )

# Устанавливаем флаги компилятора
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )

# Устанавливаем флаги компилятора
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++" )

# Устанавливаем значение переменной PROJECT
set ( PROJECT template )

# Имя проекта
project ( ${PROJECT} )

# Устанавливаем корневой путь к папке с исходниками программы.
set( SOURCE_ROOT ../src )

# Собираем исходные файлы программы
aux_source_directory( ${SOURCE_ROOT} SOURCES )

# Указываем пути, где искать заголовочники, дополнительно к стандартным путям.
include_directories( "../inc/"
        )

# Указываем путь к исполнеямому файлу
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Собираем исполняемый файл с именем template.
add_executable( ${PROJECT} ${SOURCES} )

# Test comment