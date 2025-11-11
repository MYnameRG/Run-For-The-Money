🏃‍♂️ Run for the Money:

A console-based adventure game written in C.
Developed by Rohit Gupta

🎮 Overview:

Run for the Money is a simple terminal-based game where you control a player (*) to collect money ($) inside a bordered grid.
Your goal is to move around, grab as many $ symbols as possible, and earn a high score — without hitting the walls!

The game demonstrates:
1. Console graphics rendering using 2D arrays
2. Player movement control
3. Randomized money (fruit) spawning
4. Score tracking
5. Delay-based animation

⚙️ Features:
✅ Dynamic game grid (80x16)
✅ Player movement (W, A, S, D)
✅ Randomized coin (money) placement
✅ Scoreboard display
✅ Boundary protection (cannot cross walls)
✅ Delay-based smooth rendering

🧠 How It Works:
The game uses a 2D array (char a[ROWS][COLS]) to represent the console screen.
1. # represents the border
2. * is the player character
3. $ represents money to collect
When you move the player and reach a $, your score increases by 5 points.
The fast_output() and slow_output() functions handle screen rendering with different speeds.

⌨️ Controls:
Key	Action
W	Move Up
A	Move Left
S	Move Down
D	Move Right
Ctrl + C	Exit Game

🧩 Game Logic Flow:
1. Initialize Grid:
Fills the grid with blank spaces.

3. Draw Boundaries:
Adds walls (#) around the edges.

4. Place Player:
Randomly positions the player (*).

5. Spawn Money:
Randomly places $ symbols within the grid.

6. Listen for Input:
Waits for key presses to move the player.

7. Update Score:
If player touches a $, increment score and respawn new $.

🛠️ Setup & Run Instructions:

**Requirements**
1. A C compiler (e.g., GCC or Turbo C)
2. conio.h compatible environment (Windows or DOSBox)
3. Terminal/console window

**Compile**
gcc run_for_money.c -o run_for_money

**Run**
./run_for_money

(If you’re using Turbo C or DOSBox, simply compile and run inside the IDE.)

