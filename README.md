# Avengers Battle

## Description

**Avengers Battle** is a C++ console-based simulation of a classic turn-based combat scenario between two Avengers. This program allows users to create two Avengers characters by specifying their names, health points, and attack power. The two Avengers then engage in a battle, attacking each other alternately until one or both are defeated.

This simple yet engaging project demonstrates fundamental programming concepts such as classes, object-oriented design, control flow, and input/output handling in C++. It’s a great starting point for learning how to build interactive console applications that model real-world scenarios.

---

## Features

### 1. **Avenger Character Creation**
- Each Avenger has three core attributes:
  - **Name:** A string identifier.
  - **Health:** An integer representing the current life points.
  - **Power:** An integer representing the damage dealt in each attack.
- Users input these attributes for two Avengers before the battle begins.

### 2. **Turn-Based Battle Mechanics**
- The battle proceeds in rounds.
- In each round, the current attacker deals damage equal to their power to the opponent.
- The defender’s health is reduced accordingly.
- The roles swap each round (attacker becomes defender and vice versa).
- The battle stops immediately when an Avenger’s health falls to zero or below.

### 3. **Battle Log and Visualization**
- After every attack, the program outputs the details:
  - Who attacked whom.
  - The amount of damage dealt.
  - The updated health of the defender.
- This keeps the user informed about the ongoing battle in real time.

### 4. **Winner and Draw Conditions**
- If one Avenger’s health drops to zero or less before the other’s, that Avenger loses and the other is declared the winner.
- If both Avengers’ health drops to zero or less in the same round (due to simultaneous attacks in extended versions), the battle ends in a draw.
- The program displays a clear message announcing the outcome.

---

## How It Works

1. **Initialization:**
   - The program starts by prompting the user to enter the name, health, and power for two Avengers.

2. **Battle Loop:**
   - The battle progresses in rounds.
   - In each round, the first Avenger attacks the second.
   - The program subtracts the attacker’s power from the defender’s health.
   - If the defender survives, the defender attacks back in the next round.
   - The process continues until one or both Avengers’ health reaches zero or below.

3. **End of Battle:**
   - When the battle ends, the program declares the winner or a draw.
   - The program terminates after showing the result.

---

## Design Highlights

- **Object-Oriented Approach:**  
  The `Avenger` class encapsulates all attributes and behaviors related to each character, such as attacking and health management. This makes the code modular and easy to extend.

- **Clear User Interaction:**  
  The console interface is intuitive, guiding users through inputs and clearly showing battle progress.

- **Extensible Code Base:**  
  The code structure allows adding more features easily, such as multiple Avengers, special abilities, defense mechanics, or even graphical interfaces.

---

## Build Instructions

1. Clone the repository:
    ```bash
    git clone https://github.com/your-repo/avengers-battle.git
    ```

2. Navigate to the project directory:
    ```bash
    cd avengers-battle
    ```

3. Compile the project using `make` (if a `Makefile` is included):
    ```bash
    make
    ```

   Alternatively, compile manually:
    ```bash
    g++ -o avengers_battle main.cpp
    ```

4. Run the program:
    ```bash
    ./avengers_battle
    ```

---

## Usage

When the program runs, follow the prompts:

- Input the name, health, and power values for each Avenger.
- Watch the turn-by-turn battle narration in the console.
- Observe the health updates after each attack.
- The program will announce the winner or a draw at the end.

This makes the simulation easy to interact with and understand for users of all levels.

---
