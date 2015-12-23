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

void color(int r, int g, int b, FILE *tga);

void draw(FILE *tga)
{
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
  header.bpp = 24;
  header.desc= 0x20;

  create_header(header, tga);

  int x;
  int y;
  for(x = 0; x < 480; x++)
    for(y = 0; y < 640; y++)
    {
      color(0, 255, 255, tga);
    }

  fclose(tga);
}

void draw_square(int x, int y, int width, int height, int r, int g, int b,  FILE *tga)
{
    for(; x < height; x++)
      for(; y < width; y++)
      {
        color(r, g, b, tga);
        printf("doing coloring on %d and %d \n", x, y);
        printf("width %d \n", width);
        printf("height%d \n", height);
      }
}

void animate()
{
  int frame_index;

  for(frame_index = 0; frame_index < 2; frame_index++)
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
    header.bpp = 24;
    header.desc= 0x20;

    char filename[64];
    sprintf (filename, "anim%d.tga", frame_index);
    tga = fopen(filename, "wb");

    create_header(header, tga);
    draw_square(10, 10, 30, 30, 255, 255 ,255, tga);

    fclose(tga);
  }
}

int main ()
{
  animate();

  return 0;
}
