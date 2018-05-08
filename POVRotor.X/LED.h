#ifndef _LED_H_
#define _LED_H_

#define LED_LENGTH 73

struct led {
    unsigned char red, green, blue;
};

extern void writeLEDs(struct led*);

#endif