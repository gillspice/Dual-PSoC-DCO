# Dual-PSoC-DCO


Oscillator has 
- A main CV input
- A range modifier CV input
- A Coarse tune CV input
- A fine tune CV input

These 4 inputs are fed into a 12-bit SAR ADC

There is also a FM input (intended to support through-zero audio rate FM), 16-bit 48kHz

The oscillator frequency is determined by the period of a 32-bit count down timer with a clock of 24MHz

The oscillator supports a 10V range, 1V/octave.  Each CV input has a 5V range.  The total 10V range is over 13 bits.

The conversion from CV ADC counts, which is linear to voltage, to timer period is done via a lookup table.  After the target period is calculated based on the CV inputs, it is modulated by the value from the FM input. The code used to generate the lookup table can be found here:  https://github.com/rbultman/audio-generators

The TC output of the 32-bit timer is fed into a 4 bit up/down counter.  This was added in an attempt to imrpove the through zero FM behavior (the polarity of the FM input controls up vs down counting).
In addition to setting the counter period based on the CV inputs, the counter value is updated based on the change in period, again with the intent for improve 'through zero' FM behavior

For triangle and saw waveforms an idac is fed into a capacitor to achieve the voltage ramp.
