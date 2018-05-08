#include "LED.h"
#include "draw.h"
#include <math.h>

void pie(struct led *buffer, struct led *pie_colors, int n, double angle) {
    int i;
    int idx1 = angle / (360.0 / (double)n);
    
    for (i = 0; i < LED_LENGTH / 2; i++) {
        buffer[i] = pie_colors[idx1];
    }
    
    angle = angle + OPP_ANGLE_CORRECTION + 180.0;
    if(angle > 360.0) angle -= 360.0;
    int idx2 = angle / (360.0 / (double)n);
    
    for (i = LED_LENGTH / 2 + 1; i < LED_LENGTH; i++) {
        buffer[i] = pie_colors[idx2];
    }
    buffer[LED_LENGTH / 2] = color_black;
}

void polar(struct led *buffer, int (*f)(double), struct led color, double angle) {
    int r1 = f(angle);
    
    angle = angle + OPP_ANGLE_CORRECTION + 180.0;
    if(angle > 360.0) angle -= 360.0;
    int r2 = f(angle);
    
    int i;
    for (i = 0; i < LED_LENGTH; i++) {
        buffer[i] = color_black;
    }
    
    if (r2 % 2 == 1) {
        buffer[LED_LENGTH / 2 + r2 / 2] = color;
    }
    if (r1 % 2 == 0) {
        buffer[LED_LENGTH / 2 - r1 / 2] = color;
    }
}

void polar_fill(struct led *buffer, int (*f)(double), struct led color, double angle) {
    int r1 = f(angle);
    
    angle = angle + OPP_ANGLE_CORRECTION + 180.0;
    if(angle > 360.0) angle -= 360.0;
    int r2 = f(angle);
    
    int i;
    for (i = 0; i < LED_LENGTH; i++) {
        buffer[i] = color_black;
    }
    
    if (r2 % 2 == 1) {
        for(i = LED_LENGTH / 2 + 1; i <= LED_LENGTH / 2 + r2 / 2; i++) {
            buffer[i] = color;
        }
    }
    if (r1 % 2 == 0) {
        for(i = LED_LENGTH / 2; i >= LED_LENGTH / 2 - r1 / 2; i--) {
            buffer[i] = color;
        }
    }
}

void polar_neg(struct led *buffer, int (*f)(double), struct led color, double angle) {
    int r = f(angle);
    
    int i;
    for (i = 0; i < LED_LENGTH; i++) {
        buffer[i] = color_black;
    }
    
    /*if (r >= 0) {
        for(i = LED_LENGTH / 2; i <= LED_LENGTH / 2 + r; i++) {
            buffer[i] = color;
        }
    } else {
        for(i = LED_LENGTH / 2; i >= LED_LENGTH / 2 - r; i--) {
            buffer[i] = color;
        }
    }*/
    if (r >= 0) {
        buffer[LED_LENGTH / 2 + r] = color;
    }
    else {
        buffer[LED_LENGTH / 2 - r] = color;
    }
}


int spiral(double angle) {
    return angle / 5.0;
}

int cardioid(double angle) {
    double t = 1.0 - cos(angle * 3.1415 / 180.0);
    return t * 36.0;
}

int cosn(double angle) {
    double t = cos(2.0 * angle * 3.1415 / 180.0);
    return t * 36.0;
}

int line(double angle) {
    /*double t;
    if(angle < 1.0 || angle > 359.0) t = 1;
    else t = 1 / sin(angle * 3.1415 / 180.0);
    return t * 10.0;*/
    
    double t;
    if(angle > 90.0) t = 0;
    else t = 1 / (sin(angle * 3.1415 / 180.0) + cos(angle * 3.1415 / 180.0));
    return t * 36.0;
}