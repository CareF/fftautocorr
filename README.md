A auto-correlation calculator based on FFT
==========================================

Often times people calculate FFT for convolution and auto-correlation 
rather than if they really need Fourier transform. There have already 
been a lot of wheels for FFT but all the famous ones are not designed 
in a way that is simple (yet still efficient) enough to integrate into
codes just for auto-correlation purposes: they usually require a large
planner and spend a lot of time dealing with complicated dividing-and-
conquer strategies, which is not necessary for auto-correlation purposes
because we have the freedom to pad zeros in the end. 

This piece of code is pure C and does a simple auto-correlation with
FFT for real double inputs.

Speed record
============
Everything here is tested roughly on Intel i7-9750H MacBook Pro, compiled with 
clang 11.
