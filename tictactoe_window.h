#ifndef TICTACTOE_WINDOW_H
#define TICTACTOE_WINDOW_H

#include <gtkmm.h>
#include <vector>
#include <array> // For a fixed-size board

class TicTacToeWindow : public Gtk::Window {
public:
    TicTacToeWindow();
    virtual ~TicTacToeWindow();

protected:
    // Signal handlers:
    void on_cell_button_clicked(int index);
    void on_reset_button_clicked();

private:
    void initialize_game();
    void update_status_label();
    bool check_win();
    bool check_draw();
    void end_game(const Glib::ustring& message);

    // Member widgets:
    Gtk::Box m_vbox;         // Main vertical box
    Gtk::Grid m_grid;        // Grid for game cells
    std::array<Gtk::Button*, 9> m_cell_buttons; // Buttons for cells
    Gtk::Label m_status_label; // To show game status
    Gtk::Button m_reset_button; // To reset the game

    // Game state:
    std::array<char, 9> m_board_state; // ' ' for empty, 'X', 'O'
    char m_current_player;
    bool m_game_over;
};

#endif // TICTACTOE_WINDOW_H
