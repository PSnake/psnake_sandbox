#ifndef __LAUNCHER_H__
#define __LAUNCHER_H__

#include <allegro.h>

class Launcher {
    public:
        Launcher();
        ~Launcher();

        void launch_game();

    private:
        int win_w, win_h;

        int gfx_mode;
};

#endif
