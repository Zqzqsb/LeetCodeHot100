add_rules("mode.debug", "mode.release")

add_includedirs("cpp")

target("test")
    set_kind("binary")
    add_files("test.cpp")
    set_languages("c++17")

target("two-sum")
    set_kind("binary")
    add_files("cpp/0001.two-sum/*.cpp")
    set_languages("c++2a")