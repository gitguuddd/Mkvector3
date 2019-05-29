cmake_minimum_required(VERSION 3.13)
project(Obj_Duomenu_apdorojimas)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")
set(CMAKE_CXX_FLAGS "-O3 -fpermissive")

set(CMAKE_CXX_STANDARD 14)

add_executable(Obj_Duomenu_apdorojimas main.cpp Headers/Vector.h Headers/Input.h Headers/Output.h Cpps/Input.cpp Cpps/Output.cpp Headers/Mutual.h Cpps/Mutual.cpp classes/stud/stud.h classes/stud/stud.cpp classes/Timer/Timer.h classes/Humie/Humie.h classes/ImportantValues/ImportantValues.h classes/ImportantValues/ImportantValues.cpp classes/Humie/Humie.cpp)