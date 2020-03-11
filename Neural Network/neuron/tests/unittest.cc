// Copyright 2005, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A sample program demonstrating using Google C++ testing framework.

// This sample shows how to write a simple unit test for a function,
// using Google C++ testing framework.
//
// Writing a unit test using Google C++ testing framework is easy as 1-2-3:


// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include "gtest/gtest.h"
#include "../src/apprentissage/apprentissage.hpp"
#include <iostream>

namespace {

// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.
//
// <TechnicalDetails>
//
// In Google Test, tests are grouped into test cases.  This is how we
// keep test code organized.  You should put logically related tests
// into the same test case.
//
// The test case name and the test name should both be valid C++
// identifiers.  And you should not use underscore (_) in the names.
//
// Google Test guarantees that each test you define is run exactly
// once, but it makes no guarantee on the order the tests are
// executed.  Therefore, you should write your tests in such a way
// that their results don't depend on their order.
//
// </TechnicalDetails>

TEST(Utils, ReadFile) {
  // This test is named "Negative", and belongs to the "FactorialTest"
  // test case.
  EXPECT_EQ(readFile("training/iris_training/iris0"),"5.1,3.5,1.4,0.2,Iris-setosa");
  EXPECT_EQ(readFile("this/file/does/not/exist"),"");
  EXPECT_EQ(readFile("training"),"");
}

TEST(Utils, getRand) {
  // This test is named "Negative", and belongs to the "FactorialTest"
  // test case.
  EXPECT_TRUE(getRand(0,4) <= 4);
  EXPECT_TRUE(getRand(0, 4) >= 0);
  EXPECT_TRUE(getRand(-12, -1) <= -1);
}

TEST(Iris, Constructor) {
  Iris ir(3);
  EXPECT_EQ(ir.get_label(), 0);

  ir = Iris(145);
  EXPECT_EQ(ir.get_label(), 1);

  ir = Iris(150);
  EXPECT_EQ(ir.get_label(), '\n');
}

TEST(Iris, Operator) {
  Iris ir(3);
  EXPECT_EQ(ir[0], 4.6);

  ir = Iris(145);
  EXPECT_EQ(ir[1], 3.0);

  EXPECT_EQ(ir[4], 0);

  ir = Iris(150);
  EXPECT_EQ(ir[-1], 0);
}

TEST(Iris, Label) {
  Iris ir(3);
  EXPECT_EQ(ir.get_label(), 0);

  ir = Iris(145);
  EXPECT_EQ(ir.get_label(), 1);

  ir = Iris(150);
  EXPECT_EQ(ir.get_label(), '\n');
}

TEST(Image, Operator) {
  Image im(3);
  EXPECT_EQ(im[0], 0);

  im = Image(145);
  EXPECT_EQ(im[420], 0);

  EXPECT_EQ(im[327], 0);

  im = Image(150);
  EXPECT_EQ(im[-1], 0);
}

TEST(Image, Label) {
  Image im(3);
  EXPECT_EQ(im.get_label(), 1);

  im = Image(145);
  EXPECT_EQ(im.get_label(), 5);

  im = Image(15000);
  EXPECT_EQ(im.get_label(), 5);

  im = Image(59999);
  EXPECT_EQ(im.get_label(), 8);
}

TEST(Tanh, Operator) {
  Tanh tan;
  EXPECT_DOUBLE_EQ(tan(2), tanh(2));

  EXPECT_DOUBLE_EQ(tan(1), tanh(1));
  
  EXPECT_EQ(tan(20), 1);
}

TEST(Tanh, Prim) {
  Tanh tan;
  EXPECT_DOUBLE_EQ(tan.prim(1) , 1 - pow(tanh(1),2));
}

TEST(Perceptron, Constructor) {
  Tanh tan;
  Perceptron perc = Perceptron(4, &tan, 9);
  EXPECT_TRUE(perc.get_poids(3) <= 1 && perc.get_poids(3) >= -1);
}

TEST(Apprentissage, image) {
    int inputSize = 60000;
    int indice = getRand(0, inputSize);

    Tanh tan;
    NN1 n(IMAGE, 10);
    Image image(indice);
    Apprentissage pattern(&n, IMAGE, inputSize);


    pattern.apprendre_base(100000, 1);
    double rate = pattern.evaluer();
    rate /= inputSize;
    std::cout << "Rate   : " << rate * 100 << "% out of " << inputSize << " tests" << std::endl;
    EXPECT_GT(rate, 0.1);

    std::cout << image.print();
    char result = '0' + n.evaluation(image);
    char expected = '0' + image.get_label();
    EXPECT_EQ(result, expected);
  }
}  // namespace