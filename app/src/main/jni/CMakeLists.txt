cmake_minimum_required(VERSION 3.10.2)
project("rezero")

# Указываем, какие C++ файлы нужно компилировать
add_library(rezero SHARED Game.cpp android_main.cpp)

# Подключаем логирование Android
find_library(log-lib log)
target_link_libraries(rezero ${log-lib})

