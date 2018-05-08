#ifndef _draw_H_
#define _draw_H_

#include "LED.h"

#define OPP_ANGLE_CORRECTION 4.5

extern void pie(struct led *buffer, struct led *pie_colors, int n, double angle);

#endif