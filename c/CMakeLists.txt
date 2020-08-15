cmake_minimum_required(VERSION 3.10)

option(ENABLE_TEST "Enable Tests" ON)

project("Project Euler" C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED true)

if (ENABLE_TEST)
    enable_testing()

    function(test_check target source_file input expected)
        if (NOT TARGET ${target}_test)
            add_executable(${target}_test ${source_file})
            target_link_libraries(${target}_test m)
        endif()
        add_test(NAME ${target}_test_${input} COMMAND ${target}_test ${input})
        set_tests_properties(${target}_test_${input} PROPERTIES PASS_REGULAR_EXPRESSION ${expected})
    endfunction(test_check)

    test_check(p001 p001.c 10 23)
    test_check(p001 p001.c 1000 233168)

    test_check(p003 p003.c 13195 29)
    test_check(p003 p003.c 600851475143 6857)

    #    test_check(p004 p004.c "10 100" 9009)
    #test_check(p004 p004.c "100 1000" 906609)

    test_check(p006 p006.c "10" 2640)
    test_check(p006 p006.c "100" 25164150)

    test_check(p007 p007.c "6" 13)
    test_check(p007 p007.c "10001" 104743)
    
    test_check(p008 p008.c "4" 5832)
    test_check(p008 p008.c "13" 23514624000)

    test_check(p009 p009.c "12" 60)
    test_check(p009 p009.c "1000" 31875000)

    test_check(p010 p010.c "10" 17)
    test_check(p010 p010.c "2000000" 142913828922)
    
    test_check(p013 p013.c "" 5537376230)
    test_check(p014 p014.c "" 837799)
    
    test_check(p016 p016.c "" 1366)

    test_check(p017 p017.c "5" 19)
    test_check(p017 p017.c "1000" 21124)
    
    test_check(p018 p018.c "" 1074)

    test_check(p019 p019.c "" 171)
    test_check(p020 p020.c "" 648) 
    test_check(p021 p021.c "" 31626)
    test_check(p022 p022.c "" 871198282)
    test_check(p023 p023.c "" 4179871)
endif()

