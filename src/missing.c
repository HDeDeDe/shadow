////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
// ImageAsCode exporter v1.0 - Image pixel data exported as an array of bytes         //
//                                                                                    //
// more info and bugs-report:  github.com/raysan5/raylib                              //
// feedback and support:       ray[at]raylib.com                                      //
//                                                                                    //
// Copyright (c) 2018-2022 Ramon Santamaria (@raysan5)                                //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////

// Image data information
#define MISSING_WIDTH    32
#define MISSING_HEIGHT   32
#define MISSING_FORMAT   4          // raylib internal pixel format

static unsigned char MISSING_DATA[3072] = { 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff,
0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0,
0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff,
0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff, 0xff, 0x0, 0xff };
