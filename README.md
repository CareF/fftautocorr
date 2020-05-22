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
Everything here is tested roughly on Intel i7-9750H MacBook Pro. 

For rfft with `-Ofast`:
1. Starting with Naive Cooley–Tukey FFT algorithm with radix-2 
2. Introduce memory pool double the performance

License
----------
The code is licensed under a 3-clause BSD license

Copyright (C) 2020 CareF.LM
All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.
Neither the name of the copyright holder nor the names of its contributors may
be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
