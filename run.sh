#!/usr/bin/env bash
if [ -z $OUT ]
then
  OUT=main.out
fi

if [ -z $SOURCE ]
then
  SOURCE=main.cpp
fi

if [ -e $OUT ]; then
    rm $OUT
fi

g++ $SOURCE -o $OUT -lglut -lGLU -lGL

if [ -e $OUT ]
then
  ./$OUT
fi
