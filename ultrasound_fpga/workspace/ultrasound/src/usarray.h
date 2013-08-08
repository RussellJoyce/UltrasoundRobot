#ifndef USARRAY_H_
#define USARRAY_H_

enum US_MODE {
	US_M_SINGLE, // Scan single sensor once
	US_M_COMPLETE, // Scan complete array once
};

#define US_SENSOR_COUNT 10 // Number of sensors installed on platform
#define US_SENSOR_MAP {9, 10, 11, 1, 2, 3, 4, 5, 6, 8} //Map sensor positions to sensor addresses
#define US_SAMPLE_RATE 80000 // Hz
#define US_RX_COUNT 400 // Number of waveform samples to take at US_SAMPLE_RATE in a single ranging operation
#define US_TX_COUNT 8 // Cycles of 40Khz ultrasound to transmit

#define USADCPrecision 10 // Bits
#define USADCReference 330 // Volts - expressed in hundredths

#define TRIGGER_NEAR_FAR_CHANGE 900 //  Time at which far trigger is used instead of near trigger
#define TRIGGER_BASE 160 // Default trigger voltage for distance detection (V*100)
#define TRIGGER_OFFSET_NEAR 41 // Default amount near trigger is away from base value
#define TRIGGER_OFFSET_FAR 11 // Default amount far trigger is away from base value

extern unsigned short usWaveformData[US_SENSOR_COUNT][US_RX_COUNT]; // Provide external access to sample results
extern signed short usRangeReadings[US_SENSOR_COUNT]; // Provide external access to range readings

int init_usarray();

void usarray_set_mode(enum US_MODE newMode);
enum US_MODE usarray_get_mode();

void usarray_set_sensor(unsigned char newSensor);
unsigned char usarray_get_sensor();

void usarray_set_triggers(unsigned short changever, unsigned short nearLower, unsigned short nearUpper, unsigned short farLower, unsigned short farUpper);

short usarray_get_temperature();

void usarray_measure_temp();
void usarray_scan();
void usarray_update_ranges();

#endif /* USARRAY_H_ */
