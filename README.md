# ✨ Eter - A Strategic Duel of Wizards 🧙‍♂️🔥

Eter is a **turn-based strategy game** for two players, inspired by classic games like **Tic-Tac-Toe** and **Connect 4**, but with unique mechanics that add a **magical** and **strategic twist**. Players place and stack numbered cards on a dynamic board while using powerful spells to alter the game flow! 🃏✨

---
## 🎥 Presentation Video
[Watch the Game in Action!](https://www.youtube.com/watch?v=rY9JToN2-tw)

---
## 📜 Basic Rules

🔹 **Game Board**: A dynamic 3x3 or 4x4 grid.  
🔹 **Cards**: Each player has numbered cards (1 to 4) and a special "Eter" card.  
🔹 **Placement Options**:
   - **On an empty space** (adjacent to another card).
   - **On top of another card**, if the value is strictly higher.  
🔹 **The Eter Card**: Has a fixed value of 1, cannot be covered, and contributes to winning conditions.  
🔹 **Winning Conditions**:
   - A player aligns a row, column, or diagonal with their visible cards.  
   - The board is fully occupied.  
   - A player has no more playable cards.  
   - If none of the above, the player with the highest visible score wins! 🏆

---
## ⚡ Key Features

🎮 **Game Modes:**  
- 🧙‍♂️ **Duel of Wizards** – A competitive mode with magic spells.  
- 🏋️ **Training Mode** – Practice and refine strategies.  

🪄 **Magic Powers:**  
- 🔥 Destroy an opponent's card.  
- 🌀 Remove an entire row or column.  
- 🕶️ Cover an opponent's card.  
- ⏳ Create a trap hole on the board.  
- 🎭 Swap your stack of cards.  
- 🔄 Move the opponent’s stack.  
- 📦 Shift the board’s edges.

💥 **Explosion Mechanic**: If the board gets too crowded, players can trigger **strategic explosions** that rearrange the cards, changing the game’s flow! 💣

---
## 🛠️ Dependencies

🔹 **Qt Framework** – For the graphical interface.  
🔹 **Standard Template Library (STL)** – Data management and game logic.  

---
## 📂 Project Structure

📌 **Core Game Files:**  
- `Eter.cpp` – UI Initialization and menu management.  
- `Game.cpp` – Game logic, player turns, and win conditions.  
- `DuelOfWizards.cpp` – Implements the Duel of Wizards mode and magic abilities.  
- `Explosion.cpp` – Handles explosion mechanics.  

📌 **Key Components:**  
- `Card.h` – Represents game cards.  
- `Match.h` – Manages the current game session.  
- `Table.h` – Implements the game board and interactions.  
- `Player.h` – Tracks players, scores, and card sets.  
- `Gamemode.h` – Defines available game modes and rules.

---
## 🎮 How to Play

1️⃣ Launch the game and select a mode.  
2️⃣ Strategically place your cards and use magical powers.  
3️⃣ Outsmart your opponent and claim victory! 🏆

---
## 👨‍💻 Author

Project developed by **Ciprian Dumitrașc**. 🚀

---
⚔️ *Master the art of strategy and magic in Eter!* 🔮
