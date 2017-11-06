/* example.c - annotated example program for loadpng
 *
 * Peter Wang <tjaden@users.sf.net>
 */

#include <png.h>
#include <allegro.h>
#include "loadpng.h"


int main(int argc, char *argv[])
{
    char *filename;
    BITMAP *pic;
    PALETTE pal;
    int depth = 16;

    allegro_init();
    install_keyboard();

    /* get name of file from command line */
    if (argc < 2) {
        allegro_message("usage: %s filename.png [depth]\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    if (argc >= 3)
        depth = atoi(argv[2]);

    /* make Allegro aware of PNG file format */
    register_png_file_type();

    /* set a suitable graphics mode */
    set_color_depth(depth);
    if ((set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) < 0) &&
        (set_gfx_mode(GFX_AUTODETECT, 640, 480, 0, 0) < 0)) {
        allegro_message("Error setting video mode (640x480x%d).\n", depth);
        return 1;
    }

    /* load the PNG into a BITMAP structure */
    pic = load_png(filename, pal);
    if (!pic) {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("Error loading file `%s'.\n", filename);
        return 1;
    }

    /* if we have a palette, set it */
    if (bitmap_color_depth(pic) == 8)
        set_palette(pal);

    /* show it on the screen */
    clear(screen);
    blit(pic, screen, 0, 0, 0, 0, pic->w, pic->h);

    /* write image onto disk */
    save_bitmap("saved.png", pic, pal);

    /* any key to continue */
    readkey();

    /* The End */
    destroy_bitmap(pic);
    return 0;
}

END_OF_MAIN()
