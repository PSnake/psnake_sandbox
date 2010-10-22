#include "launcher.h"


Launcher::Launcher() {
    gfx_mode = GFX_AUTODETECT_WINDOWED;
    win_w = 800;
    win_h = 600;
}

Launcher::~Launcher() {

}


void Launcher::launch_game() {
    /*
    initialize allegro and its subsystems
    */
    if ( allegro_init() ) {
        allegro_message( "cannot initialize allegro\n" );
        return;
    }

    set_window_title( "RotWorldIvasion");

    if ( set_gfx_mode( gfx_mode, win_w, win_h, 0, 0 ) ) {
        allegro_message( "video error: %s\n", allegro_error );
        return;
    }

    /** temp */
    //set text background color to bright blue
    text_mode(makecol(0, 0, 255));

    //prints yellow "Hello World!!!" in middle of screen
    textout_centre(screen, font, "Hello World!!!", win_w/2,
                 win_h/2, makecol(255, 255, 0));

    //Wait for a key to be pressed
    while (!keypressed()) {}

}
