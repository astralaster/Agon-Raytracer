#pragma once

#include <stdio.h>
#include <agon/vdp_vdu.h>

uint8_t RGB888toPackedRGB222(uint8_t r, uint8_t g, uint8_t b)
{
  // 64 colors
  static const int CONVR64[4] = { 0 << 0,    // 00XXXXXX (0..63)
                                  1 << 0,    // 01XXXXXX (64..127)
                                  2 << 0,    // 10XXXXXX (128..191)
                                  3 << 0, }; // 11XXXXXX (192..255)
  static const int CONVG64[4] = { 0 << 2,    // 00XXXXXX (0..63)
                                  1 << 2,    // 01XXXXXX (64..127)
                                  2 << 2,    // 10XXXXXX (128..191)
                                  3 << 2, }; // 11XXXXXX (192..255)
  static const int CONVB64[4] = { 0 << 4,    // 00XXXXXX (0..63)
                                  1 << 4,    // 01XXXXXX (64..127)
                                  2 << 4,    // 10XXXXXX (128..191)
                                  3 << 4, }; // 11XXXXXX (192..255)
  return (CONVR64[r >> 6]) | (CONVG64[g >> 6]) | (CONVB64[b >> 6]);
}

void agon_plot_pixel(int16_t x, int16_t y, uint8_t color)
{
  char buffer_set_color[] = {18, 0, static_cast<char>(color)};
  mos_puts(buffer_set_color, sizeof(buffer_set_color), ' ');
  char buffer_plot_pixel[] = {25, 69, static_cast<char>(x & 0xFF), static_cast<char>(x >> 8), static_cast<char>(y & 0xFF), static_cast<char>(y >> 8)};
  mos_puts(buffer_plot_pixel, sizeof(buffer_plot_pixel), ' ');
}

void agon_set_video_mode(uint8_t mode)
{
  char buffer[] = {22, static_cast<char>(mode)};
  mos_puts(buffer, sizeof(buffer), ' ');
}

// Agon color palette
// GIMP Palette
// Name: Agon Light Mode 2, 64 colors
// Columns: 0
// #
//   0   0   0 Color 0
// 170   0   0 Color 1
//   0 170   0 Color 2
// 170 170   0 Color 3
//   0   0 170 Color 4
// 170   0 170 Color 5
//   0 170 170 Color 6
// 170 170 170 Color 7
//  85  85  85 Color 8
// 255   0   0 Color 9
//   0 255   0 Color10
// 255 255   0 Color11
//   0   0 255 Color12
// 255   0 255 Color13
//   0 255 255 Color14
// 255 255 255 Color15
//   0   0  85 Color16
//   0  85   0 Color17
//   0  85  85 Color18
//   0  85 170 Color19
//   0  85 255 Color20
//   0 170  85 Color21
//   0 170 255 Color22
//   0 255  85 Color23
//   0 255 170 Color24
//  85   0   0 Color25
//  85   0  85 Color26
//  85   0 170 Color27
//  85   0 255 Color28
//  85  85   0 Color29
//  85  85 170 Color30
//  85  85 255 Color31
//  85 170   0 Color32
//  85 170  85 Color33
//  85 170 170 Color34
//  85 170 255 Color35
//  85 255   0 Color36
//  85 255  85 Color37
//  85 255 170 Color38
//  85 255 255 Color39
// 170   0  85 Color40
// 170   0 255 Color41
// 170  85   0 Color42
// 170  85  85 Color43
// 170  85 170 Color44
// 170  85 255 Color45
// 170 170  85 Color46
// 170 170 255 Color47
// 170 255   0 Color48
// 170 255  85 Color49
// 170 255 170 Color50
// 170 255 255 Color51
// 255   0  85 Color52
// 255   0 170 Color53
// 255  85   0 Color54
// 255  85  85 Color55
// 255  85 170 Color56
// 255  85 255 Color57
// 255 170   0 Color58
// 255 170  85 Color59
// 255 170 170 Color60
// 255 170 255 Color61
// 255 255  85 Color62
// 255 255 170 Color63


char agon_map_color_rgb_to_agon(char color_rgb)
{
  switch (color_rgb)
  {
    case 0 : return 0;
    case 1 : return 16;
    case 2 : return 4;
    case 3 : return 12;

    case 4 : return 17;
    case 5 : return 18;
    case 6 : return 19;
    case 7 : return 20;

    case 8 : return 2;
    case 9 : return 21;
    case 10 : return 6;
    case 11 : return 22;

    case 12 : return 10;
    case 13 : return 23;
    case 14 : return 24;
    case 15 : return 14;

    case 16 : return 25;
    case 17 : return 26;
    case 18 : return 27;
    case 19 : return 28;

    case 20 : return 29;
    case 21 : return 8;
    case 22 : return 30;
    case 23 : return 31;

    case 24 : return 32;
    case 25 : return 33;
    case 26 : return 34;
    case 27 : return 35;

    case 28 : return 36;
    case 29 : return 37;
    case 30 : return 38;
    case 31 : return 39;

    case 32 : return 1;
    case 33 : return 40;
    case 34 : return 5;
    case 35 : return 41;

    case 36 : return 42;
    case 37 : return 43;
    case 38 : return 44;
    case 39 : return 45;

    case 40 : return 3;
    case 41 : return 46;
    case 42 : return 7;
    case 43 : return 47;

    case 44 : return 48;
    case 45 : return 49;
    case 46 : return 50;
    case 47 : return 51;

    case 48 : return 9;
    case 49 : return 52;
    case 50 : return 53;
    case 51 : return 13;

    case 52 : return 54;
    case 53 : return 55;
    case 54 : return 56;
    case 55 : return 57;

    case 56 : return 58;
    case 57 : return 59;
    case 58 : return 60;
    case 59 : return 61;

    case 60 : return 11;
    case 61 : return 62;
    case 62 : return 63;
    case 63 : return 15;
  }
  return 0;
}

void agon_set_palette_to_rgb()
{
  //VDU 19, l, p, r, g, b: Define logical colour (COLOUR l, p / COLOUR l, r, g, b)
  char buffer_set_palette[6]; // = {19, i, p, r, g, b};
  char r = 0, g = 0, b = 0;
  for(int i = 0; i < 64; i++)
  {
    r = 0x55 * (i / 16);
    g = 0x55 * (i / 4);
    b = 0x55 * i;
    r = 0;
    b = 0xFF;
    g = 0;
    buffer_set_palette[0] = 19;
    buffer_set_palette[1] = i;
    buffer_set_palette[2] = 255;
    buffer_set_palette[3] = r;
    buffer_set_palette[4] = g;
    buffer_set_palette[5] = b;
    mos_puts(buffer_set_palette, sizeof(buffer_set_palette), ' ');
    printf("Set palette color %d to r: %x g: %x b: %x\n", i, r, g, b);
  }
}