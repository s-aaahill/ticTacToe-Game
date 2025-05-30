# Tic Tac Toe Game

![GitHub repo size](https://img.shields.io/github/repo-size/s-aaahill/ticTacToe-Game)
![GitHub issues](https://img.shields.io/github/issues/s-aaahill/ticTacToe-Game)
![GitHub forks](https://img.shields.io/github/forks/s-aaahill/ticTacToe-Game?style=social)
![GitHub stars](https://img.shields.io/github/stars/s-aaahill/ticTacToe-Game?style=social)
![GitHub license](https://img.shields.io/github/license/s-aaahill/ticTacToe-Game)

A simple graphical Tic Tac Toe game built using C++ and the GTKmm 3 library. This project serves as a practical example of creating GUI applications with GTKmm in C++.

---

## Features

- Interactive 3x3 grid interface  
- Two-player gameplay (Player X and Player O)  
- Real-time win and draw detection  
- Clean and responsive GTK-based GUI

---


## Getting Started

### Prerequisites

Ensure you have the following installed on your system:

- A C++ compiler (e.g., `g++`)
- GTKmm 3 development libraries

On Ubuntu or Debian-based systems, you can install the necessary packages using:

```bash
sudo apt update
sudo apt install libgtkmm-3.0-dev
````

---

## Building the Application

### Clone the repository:

```bash
git clone https://github.com/s-aaahill/ticTacToe-Game.git
cd ticTacToe-Game
```

### Compile the source code:

```bash
g++ main.cpp tictactoe_window.cpp -o ticTacToeGame `pkg-config --cflags --libs gtkmm-3.0`
```

---

## Running the Application

After building, run the application with:

```bash
./ticTacToeGame
```

---

## Project Structure

* `main.cpp`: Entry point of the application
* `tictactoe_window.h`: Header file for the main game window class
* `tictactoe_window.cpp`: Implementation of the game window and logic

---

## Contributing

Contributions are welcome! If you have suggestions for improvements or new features, feel free to fork the repository and submit a pull request.

---
