#include "tictactoe_window.h"
#include <iostream> // For debugging, optional

TicTacToeWindow::TicTacToeWindow()
    : m_vbox(Gtk::ORIENTATION_VERTICAL, 5),
      m_current_player('X'),
      m_game_over(false) {

    set_title("GTKmm Tic-Tac-Toe");
    set_default_size(300, 350);
    set_border_width(10);

    // Add main VBox to the window
    add(m_vbox);

    // --- Create Game Grid ---
    m_grid.set_row_spacing(5);
    m_grid.set_column_spacing(5);
    m_vbox.pack_start(m_grid, Gtk::PACK_EXPAND_WIDGET);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int index = i * 3 + j;
            m_cell_buttons[index] = Gtk::manage(new Gtk::Button()); // GTKmm manages memory
            m_cell_buttons[index]->set_label(" ");
            m_cell_buttons[index]->set_size_request(80, 80); // Make buttons squarish
            m_cell_buttons[index]->get_child()->set_name("cell_button_label"); // For potential CSS
             // Use sigc::bind to pass the index to the handler
            m_cell_buttons[index]->signal_clicked().connect(
                sigc::bind(sigc::mem_fun(*this, &TicTacToeWindow::on_cell_button_clicked), index)
            );
            m_grid.attach(*m_cell_buttons[index], j, i, 1, 1);
        }
    }

    // --- Create Status Label ---
    m_vbox.pack_start(m_status_label, Gtk::PACK_SHRINK);

    // --- Create Reset Button ---
    m_reset_button.set_label("Reset Game");
    m_reset_button.signal_clicked().connect(sigc::mem_fun(*this, &TicTacToeWindow::on_reset_button_clicked));
    m_vbox.pack_start(m_reset_button, Gtk::PACK_SHRINK);

    // Initialize game state
    initialize_game();

    // Show all widgets
    show_all_children();
}

TicTacToeWindow::~TicTacToeWindow() {
    // Gtk::manage handles deletion of widgets added with it
}

void TicTacToeWindow::initialize_game() {
    m_board_state.fill(' '); // Reset board state to empty
    m_current_player = 'X';
    m_game_over = false;

    for (int i = 0; i < 9; ++i) {
        m_cell_buttons[i]->set_label(" ");
        m_cell_buttons[i]->set_sensitive(true); // Enable button
        // Clear any previous styling if you were applying it
        auto context = m_cell_buttons[i]->get_style_context();
        context->remove_class("winning-cell"); // Example if you add CSS
    }
    update_status_label();
}

void TicTacToeWindow::update_status_label() {
    if (m_game_over) {
        // Status already set by end_game()
        return;
    }
    Glib::ustring msg = "Player ";
    msg += m_current_player;
    msg += "'s turn";
    m_status_label.set_text(msg);
}

void TicTacToeWindow::on_cell_button_clicked(int index) {
    if (m_game_over || m_board_state[index] != ' ') {
        return; // Do nothing if game is over or cell is not empty
    }

    m_board_state[index] = m_current_player;
    m_cell_buttons[index]->set_label(Glib::ustring(1, m_current_player));
    m_cell_buttons[index]->set_sensitive(false); // Disable after click

    if (check_win()) {
        Glib::ustring winner_msg = "Player ";
        winner_msg += m_current_player;
        winner_msg += " wins!";
        end_game(winner_msg);
    } else if (check_draw()) {
        end_game("It's a draw!");
    } else {
        // Switch player
        m_current_player = (m_current_player == 'X' ? 'O' : 'X');
        update_status_label();
    }
}

bool TicTacToeWindow::check_win() {
    // Winning combinations (indices)
    const int win_conditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (const auto& condition : win_conditions) {
        if (m_board_state[condition[0]] == m_current_player &&
            m_board_state[condition[1]] == m_current_player &&
            m_board_state[condition[2]] == m_current_player) {
            // Optional: Highlight winning cells
            // for (int i=0; i<3; ++i) {
            //     m_cell_buttons[condition[i]]->get_style_context()->add_class("winning-cell");
            // }
            return true;
        }
    }
    return false;
}

bool TicTacToeWindow::check_draw() {
    for (char cell_state : m_board_state) {
        if (cell_state == ' ') {
            return false; // Game is not over yet, empty cell found
        }
    }
    return true; // All cells filled, no winner means draw
}

void TicTacToeWindow::end_game(const Glib::ustring& message) {
    m_game_over = true;
    m_status_label.set_text(message);
    // Disable all cell buttons
    for (int i = 0; i < 9; ++i) {
        m_cell_buttons[i]->set_sensitive(false);
    }
}

void TicTacToeWindow::on_reset_button_clicked() {
    initialize_game();
}
