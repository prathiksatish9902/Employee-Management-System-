cmake_minimum_required(VERSION 3.16)

project(project_demo LANGUAGES C)

add_executable(project_demo main.c
    employee.h
    add_employee.h
    add_employee.c
    delete_employee.h
    delete_employee.c
    main_menu.h
    main_menu.c
    display_employees.h
    display_employees.c
    update_employee.h
    update_employee.c
    search_employee.h
    search_employee.c
    sort_by_name.h
    sort_by_name.c
    sort_by_department.h
    sort_by_department.c
    sort_by_designation.h
    sort_by_designation.c
    save_and_load_file.h
    save_and_load_file.c)

include(GNUInstallDirs)
install(TARGETS project_demo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
