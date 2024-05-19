cmake_minimum_required(VERSION 3.15)
project(todo C)

add_executable(todo)

target_sources(
    todo
    PRIVATE
        main.c
        edit.c
        list.c
        finish.c
        add.c
        buffer.c
        io.c
        edit.h
        list.h
        finish.h
        add.h
        buffer.h
        io.h
        consts.h
)


target_link_libraries(todo PRIVATE -lm)