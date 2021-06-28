#include <stdio.h>

#define on 1
#define off 0

#define open 1
#define closed 0

typedef enum State {
    S0, S1, S2, S3, S4, S5
} State;

typedef enum Event {
    E1, E2, E3, E4
} Event;

int LEDLeft = off;
int LEDRight = off;
int doorLeft = closed;
int doorRight = open;
int state = S0;

void changeState(Event event);
void setState(State state);

int main() {

    return 0;
}

void changeState(Event event) {
    switch (state) {
        case S0:
            if(event == E1) setState(S1);
            else if(event == E3) setState(S3);
            break;
        case S1:
            if(event == E2) setState(S2);
            else if(event == E4) setState(S0);
            break;
        case S2:
            if(event == E3) setState(S0);
            else if(event == E4) setState(S5);
            break;
        case S3:
            if(event == E2) setState(S4);
            else if(event == E4) setState(S0);
            break;
        case S4:
            if(event == E1) setState(S0);
            else if(event == E4) setState(S5);
            break;
        case S5:
            if(event == E3) setState(S0);
            break;
        default:
            break;
    }
}

void setState(State s) {
    state = s;

    if(s == S0) {
        LEDLeft = off;
        LEDRight = off;
        doorLeft = closed;
        doorRight = closed;
        return;
    }

    if(s == S1) {
        LEDLeft = off;
        LEDRight = on;
        doorLeft = open;
        doorRight = closed;
        return;
    }

    if(s == S2) {
        LEDLeft = on;
        LEDRight = on;
        doorLeft = closed;
        doorRight = open;
        return;
    }

    if(s == S3) {
        LEDLeft = on;
        LEDRight = off;
        doorLeft = open;
        doorRight = closed;
        return;
    }

    if(s == S4) {
        LEDLeft = on;
        LEDRight = on;
        doorLeft = closed;
        doorRight = open;
    }

    if(s == S5) {
        LEDLeft = on;
        LEDRight = on;
        doorLeft = closed;
        doorRight = closed;
    }
}



