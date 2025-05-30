#include <gtkmm/application.h>
#include "tictactoe_window.h"

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example.tictactoe");

    TicTacToeWindow window;

    // Shows the window and returns when it is closed.
    return app->run(window);
}
