# Car Acceleration Computation using C and x86-64 Assembly (Scalar SIMD)

This project implements a car acceleration calculator that computes acceleration values based on initial velocity, final velocity, and time using both C and x86-64 Assembly. The goal is to measure performance while applying **scalar SIMD floating-point instructions** in Assembly.

---

## Problem Description

A car's performance is measured through acceleration over a 1 KM distance. Each test provides:

- Initial velocity (**Vi**) in KM/H
- Final velocity (**Vf**) in KM/H
- Time (**T**) in seconds

The formula used:

Acceleration = (Vf - Vi) / T
With velocities converted from KM/H to m/s:

The output acceleration values are rounded and returned as integers.

## Input Format

- Number of rows `Y` (number of cars)
- A Y x 3 matrix of single-precision float values
  - Column 1: Initial Velocity (Vi) in KM/H
  - Column 2: Final Velocity (Vf) in KM/H
  - Column 3: Time (T) in seconds

Example:

0.0, 62.5, 10.1
60.0, 122.3, 5.5
30.0, 160.7, 7.8



##  Output

Integer acceleration values (m/s²) for each car, one per line:

Example:
2
3
5

