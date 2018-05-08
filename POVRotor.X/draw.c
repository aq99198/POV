#include "LED.h"
#include "draw.h"

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
    struct led black = {0, 0, 0};
    buffer[LED_LENGTH / 2] = black;
}