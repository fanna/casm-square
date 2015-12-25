#include<stdio.h>

typedef struct {
    char id_len;
    char map_type;
    char img_type;
    int  map_first;
    int  map_len;
    char map_entry_size;
    int  x;
    int  y;
    int  width;
    int  height;
    char bpp;
    char desc;
} HEADER;

void create_header(HEADER h, FILE *tga)
{
    fputc(h.map_type, tga);
    fputc(h.id_len, tga);
    fputc(h.img_type, tga);
    fputc(h.map_first % 256, tga);
    fputc(h.map_first / 256, tga);
    fputc(h.map_len % 256, tga);
    fputc(h.map_len / 256, tga);
    fputc(h.map_entry_size, tga);
    fputc(h.x % 256, tga);
    fputc(h.x / 256, tga);
    fputc(h.y % 256, tga);
    fputc(h.y / 256, tga);
    fputc(h.width % 256, tga);
    fputc(h.width / 256, tga);
    fputc(h.height % 256, tga);
    fputc(h.height / 256, tga);
    fputc(h.bpp, tga);
    fputc(h.desc, tga);
}

void color(int r, int g, int b, int a, FILE *tga);

void draw(int x, int y, int width, int height, int r, int g, int b, int a)
{
  FILE *tga;

  HEADER header;

  header.id_len = 0;
  header.map_type = 0;
  header.img_type = 2;
  header.map_first = 0;
  header.map_len = 0;
  header.map_entry_size = 0;
  header.x = 0;
  header.y = 0;
  header.width = 640;
  header.height = 480;
  header.bpp = 32;
  header.desc= 0x20;

  tga = fopen("picture.tga", "w+");

  create_header(header, tga);

  int paint_x;
  int paint_y;
  for(paint_x = 0; paint_x < 480; paint_x++)
    for(paint_y = 0; paint_y < 640; paint_y++)
    {
      if(paint_y >= x && paint_y < x + width && paint_x >= y && paint_x < y + height)
      {
        color(r, g, b, a, tga);
      }
      else
      {
        color(255, 255, 255, 0, tga);
      }
    }

  fclose(tga);
}

int main ()
{
  draw(100, 240, 160, 130, 134, 255, 111, 255);

  return 0;
}
