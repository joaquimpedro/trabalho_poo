cmake_minimum_required(VERSION 3.5)
project(poo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp sources/list.cpp headers/list.h sources/nodelist.cpp headers/nodelist.h sources/pessoa.cpp headers/pessoa.h sources/universidade.cpp headers/universidade.h sources/funcionario.cpp headers/funcionario.h sources/setor.cpp headers/setor.h sources/curso.cpp headers/curso.h sources/disciplina.cpp headers/disciplina.h sources/turma.cpp headers/turma.h sources/aluno.cpp headers/aluno.h)
add_executable(poo ${SOURCE_FILES})