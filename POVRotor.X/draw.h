#ifndef _draw_H_
#define _draw_H_

#include "LED.h"

#define OPP_ANGLE_CORRECTION 3.0

extern void pie(struct led *buffer, struct led *pie_colors, int n, double angle);
extern void polar(struct led *, int (*f)(double), struct led, double);
extern void polar_neg(struct led *, int (*f)(double), struct led, double);
extern void polar_fill(struct led *, int (*f)(double), struct led, double);
extern int spiral(double);
extern int cardioid(double);
extern int cosn(double);
extern int line(double);

#endif