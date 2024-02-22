byte state = NOTINUSE;

#define NOTINUSE 0
#define NR1 1
#define NR2 2
#define CLEANING 3
#define UNDEFINED 4
#define TRIGGERED 5
#define MENUACTIVE 6

// 0 == not in use
// 1 == in use, number 1
// 2 == in use, number 2
// 3 == in use, cleaning
// 4 == in use, type unknown
// 5 == triggered, spray shot imminent or waiting for spray shot
// 6 == operator menu active -> if end then go to 0


// 0 -> 4 when lights turn on.
// 1 or 2 or 3 when type is known