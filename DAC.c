#define F_CPU (3333333UL) /* 3.33 MHz (needed for delay) */
#define VREF_STARTUP_MICROS (25) /* VREF Startup time */
#include <avr/io.h>
#include <util/delay.h>
void VREF_init(void);
void DAC0_init(void);
void VREF_init(void)
{
VREF.CTRLA |= VREF_DAC0REFSEL_4V3_gc; // Voltage reference is 4.3V for wider range.
VREF.CTRLB |= VREF_DAC0REFEN_bm; // DAC0 reference enable: enabled
_delay_us(VREF_STARTUP_MICROS); // VREF start delay= 25 ms
}

void DAC0_init(void)
{
/* Disable digital input buffer */
PORTA.PIN6CTRL &= ~PORT_ISC_gm;
PORTA.PIN6CTRL |= PORT_ISC_INPUT_DISABLE_gc;
/* Disable pull-up resistor */
PORTA.PIN6CTRL &= ~PORT_PULLUPEN_bm;
/* Enable DAC, Output Buffer, Run in Standby */
DAC0.CTRLA = DAC_ENABLE_bm | DAC_OUTEN_bm | DAC_RUNSTDBY_bm;
}
int main(void)
{
VREF_init();
DAC0_init();
DAC0.DATA = 0xC2; //DAC value for desired output voltage = 3.3V (Vout x 256/Vref,
3.3x256/4.34= 194 in dec. Convert to hex=0xC2)
while (1)
{
}
}
