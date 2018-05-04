# CS3081W Google Test Framework

This directory contains a combination of TA-written and student-written unit tests
for the project.  All of the tests are written on top of the Google Test testing
framework.  The Makefile will generate a new unittest execuable by compiling all
of the tests specified in the .cc files in this directory with a pre-built version
of the Google Test library (libgtest.a, libgtest_main.a).

## Compiling and Running Tests

   Running 'make all' will generate ../build/bin/unittest, which you can run directly
   as you develop your project to see how the current code works with the current
   set of tests.


## feedback-tests-iter1.cc

The CSci-3081W staff will create this file of tests.  You should never need to edit this
file.  In fact, it is important that you do not edit it.  Think of it as a contract.  

## Writing your own tests

Add to the student-tests1.cc file or rename it and/or create your own files to add your
own tests to the test suite.  
