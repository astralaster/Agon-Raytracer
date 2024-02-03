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