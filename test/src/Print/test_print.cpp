/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <Print.h>

#include <PrintMock.h>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Print::print(char)", "[Print-print-01]")
{
  PrintMock mock;

  mock.print('A');
  REQUIRE(mock._str == "A");
}

TEST_CASE ("Print::print(int, int = DEC|HEX|OCT|BIN)", "[Print-print-02]")
{
  PrintMock mock;

  int const val = -1;

  WHEN("DEC") { mock.print(val, DEC); REQUIRE(mock._str  == "-1"); }
  WHEN("HEX") { mock.print(val, HEX); REQUIRE(mock._str  == "FFFFFFFFFFFFFFFF"); }
  WHEN("OCT") { mock.print(val, OCT); REQUIRE(mock._str  == "1777777777777777777777"); }
  WHEN("BIN") { mock.print(val, BIN); REQUIRE(mock._str  == "1111111111111111111111111111111111111111111111111111111111111111"); }
}

TEST_CASE ("Print::print(unsigned int, int = DEC|HEX|OCT|BIN)", "[Print-print-03]")
{
  PrintMock mock;

  unsigned int const val = 17;

  WHEN("DEC") { mock.print(val, DEC); REQUIRE(mock._str  == "17"); }
  WHEN("HEX") { mock.print(val, HEX); REQUIRE(mock._str  == "11"); }
  WHEN("OCT") { mock.print(val, OCT); REQUIRE(mock._str  == "21"); }
  WHEN("BIN") { mock.print(val, BIN); REQUIRE(mock._str  == "10001"); }
}

TEST_CASE ("Print::print(long, int = DEC|HEX|OCT|BIN)", "[Print-print-04]")
{
  PrintMock mock;

  long const val = -1;

  WHEN("DEC") { mock.print(val, DEC); REQUIRE(mock._str  == "-1"); }
  WHEN("HEX") { mock.print(val, HEX); REQUIRE(mock._str  == "FFFFFFFFFFFFFFFF"); }
  WHEN("OCT") { mock.print(val, OCT); REQUIRE(mock._str  == "1777777777777777777777"); }
  WHEN("BIN") { mock.print(val, BIN); REQUIRE(mock._str  == "1111111111111111111111111111111111111111111111111111111111111111"); }
}

TEST_CASE ("Print::print(unsigned long, int = DEC|HEX|OCT|BIN)", "[Print-print-04]")
{
  PrintMock mock;

  unsigned long const val = 17;

  WHEN("DEC") { mock.print(val, DEC); REQUIRE(mock._str  == "17"); }
  WHEN("HEX") { mock.print(val, HEX); REQUIRE(mock._str  == "11"); }
  WHEN("OCT") { mock.print(val, OCT); REQUIRE(mock._str  == "21"); }
  WHEN("BIN") { mock.print(val, BIN); REQUIRE(mock._str  == "10001"); }
}

TEST_CASE ("Print::print(long long, int = DEC|HEX|OCT|BIN)", "[Print-print-05]")
{
  PrintMock mock;

  long long const val = -1;

  WHEN("DEC") { mock.print(val, DEC); REQUIRE(mock._str  == "-1"); }
  WHEN("HEX") { mock.print(val, HEX); REQUIRE(mock._str  == "FFFFFFFFFFFFFFFF"); }
  WHEN("OCT") { mock.print(val, OCT); REQUIRE(mock._str  == "1777777777777777777777"); }
  WHEN("BIN") { mock.print(val, BIN); REQUIRE(mock._str  == "1111111111111111111111111111111111111111111111111111111111111111"); }
}

TEST_CASE ("Print::print(unsigned long long, int = DEC|HEX|OCT|BIN)", "[Print-print-06]")
{
  PrintMock mock;

  unsigned long long const val = 17;

  WHEN("DEC") { mock.print(val, DEC); REQUIRE(mock._str  == "17"); }
  WHEN("HEX") { mock.print(val, HEX); REQUIRE(mock._str  == "11"); }
  WHEN("OCT") { mock.print(val, OCT); REQUIRE(mock._str  == "21"); }
  WHEN("BIN") { mock.print(val, BIN); REQUIRE(mock._str  == "10001"); }
}

TEST_CASE ("Print::print(double, int = 2)", "[Print-print-07]")
{
  PrintMock mock;

  WHEN ("val is a positive floating point value")
  {
    double const val = 3.1459;
    WHEN("digits = 0")           { mock.print(val, 0); REQUIRE(mock._str  == "3"); }
    WHEN("digits = 1")           { mock.print(val, 1); REQUIRE(mock._str  == "3.1"); }
    WHEN("digits = 2 (default)") { mock.print(val);    REQUIRE(mock._str  == "3.15"); }
    WHEN("digits = 3")           { mock.print(val, 3); REQUIRE(mock._str  == "3.146"); }
    WHEN("digits = 4")           { mock.print(val, 4); REQUIRE(mock._str  == "3.1459"); }
    WHEN("digits = 5")           { mock.print(val, 5); REQUIRE(mock._str  == "3.14590"); }
  }

  WHEN ("digits are negative")
  {
    double const val = 3.1459;
    WHEN("digits = -1") { mock.print(val, -1); REQUIRE(mock._str  == "3.15"); }
  }

  WHEN ("val is a negative floating point value")
  {
    double const val = -3.1459;
    WHEN("digits = 2 (default)") { mock.print(val); REQUIRE(mock._str  == "-3.15"); }
  }

  WHEN ("val is NAN")      { mock.print(NAN);      REQUIRE(mock._str  == "nan"); }
  WHEN ("val is INFINITY") { mock.print(INFINITY); REQUIRE(mock._str  == "inf"); }
}
