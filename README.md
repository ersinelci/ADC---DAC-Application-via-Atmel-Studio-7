# ADC-DAC-Application-via-Atmel-Studio-7

ADC and DAC Application for ATTiny414 

# DAC (Digital to Analog Converter)

Digital to Analog Converter is a device that transforms digital data into an analog signal. According to
the Nyquist – Shannon sampling theorem, any sampled data can be reconstructed perfectly with
bandwith and Nyquist criteria. A DAC can reconstruct data into an analog signal with precision.

The ATTiny 414 DAC features is important to implement it. So I studied on data sheet and tried to
learn DAC features of ATTiny414. The DAC features an 8-bit resistor string type DAC, and uses internal
voltage references as the upper limit for conversion. DAC Block diagram shown as below:

![alt text](https://user-images.githubusercontent.com/25690715/109986546-e8989b80-7d16-11eb-956d-a43329a1d9bc.png)

Voltage reference for DAC peripheral supports five different voltages:
• 0.55V (default)
• 1.1V
• 1.5V
• 2.5V
• 4.3V

For getting desired voltage output from DAC, calculations that are necessary should be done so the
conversion formula is:
𝐷𝐴𝑇𝐴 = 𝑉𝑂𝑈𝑇𝑋 256 𝑉𝑅𝐸𝐹 = 3.3𝑋 256 4.3 = 194 = 0𝑋𝐶2 𝑖𝑛 ℎ𝑒𝑥𝑎𝑑𝑒𝑐𝑖𝑚𝑎l.
So, for the project I need 3.3 V output so I calculated with this formula and converted into
hexadecimal for selecting DAC input. Also DAC0.DATA is the register that i stored the data.

# ADC (Analog to Digital Converter)

![alt text](https://user-images.githubusercontent.com/25690715/109987928-192d0500-7d18-11eb-9a6f-ac6d4917d84c.png)

The ADC peripheral of ATTiny414 produces 10-bit results. Selectable voltage references from the internal Voltage Reference (VREF)
peripheral, VDD supply voltage, or external VREF pin (VREFA). I used reference voltage (VREF) internal peripheral for the example below. (0.55V)
The conversion formula is 1023 𝑥 𝑉𝐼𝑁 𝑉𝑅𝐸𝐹 = 𝑅𝐸𝑆 where VIN is input voltage and VREF is the reference.

To operate ADC,
• Configure the resolution by writing to the Resolution Selection (RESSEL) bit in the
Control A (ADCn.CTRLA) register.
• Configure a voltage reference by writing to the Reference Selection (REFSEL) bit in
the Control C (ADCn.CTRLC) register. The default is the internal voltage reference of
the device (VREF, as configured there).
• Configure the CLK_ADC by writing to the Prescaler (PRESC) bit field in the Control C
(ADCn.CTRLC) register.
• Configure an input by writing to the MUXPOS bit field in the MUXPOS
(ADCn.MUXPOS) register
• Enable the ADC by writing a ‘1’ to the ENABLE bit in ADCn.CTRLA
• The digital input buffer should be disabled on the pin used as input for the ADC to
disconnect the digital domain from the analog domain to obtain the best possible
ADC results. This is configured by the PORT peripheral.



