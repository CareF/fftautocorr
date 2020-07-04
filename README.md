A auto-correlation calculator based on FFT
==========================================

This is a plain C implementation for calculating auto-correlation of real 
double inputs using FFT.

## Motivation

Often times people calculate FFT for convolution and auto-correlation rather
than if they really need the Fourier transform. There have already been a lot of
wheels for FFT but all the famous ones are not designed in a way that is simple
(yet still efficient) enough to integrate into codes just for auto-correlation
purposes: they usually require a large planner and spend a lot of time dealing
with complicated dividing-and-conquer strategies, which is not necessary for
auto-correlation purposes because we have the freedom for choosing the padding
length. 

## Acknowledgment

The FFT part of the program was modified from
[pocketfft](https://gitlab.mpcdf.mpg.de/mtr/pocketfft).
