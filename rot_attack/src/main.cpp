#include <allegro.h>

#include "launcher.h"

int main(int argc, char* argv[]) {
    Launcher launcher();
    launcher.launch_game();

    return 0;
    //Allegro will automatically deinitalize itself on exit
}
END_OF_MAIN()
