#! /bin/bash
rm -r build/*
(cd build; cmake ..)
(cd build; make install)
(cd build; make)
