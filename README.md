# Tic Tac Toe Game using SFML
![Game Screenshot](https://github.com/user-attachments/assets/0aaecf9d-2a96-410c-8f9c-f91c944f2dbc)
## Overview

This project implements a simple Tic Tac Toe game where the player competes against an AI opponent. The AI uses the minimax algorithm to make optimal moves, ensuring a challenging gameplay experience.

## Features

### Player vs AI Gameplay
The game allows you to play against an AI opponent that employs the minimax algorithm. Minimax is a recursive algorithm used for decision-making in two-player games. It evaluates possible moves by assuming the opponent plays optimally and chooses the move that maximizes the AI's chances of winning or minimizing its chances of losing.

### Interactive Interface
The interface is interactive and visually appealing, utilizing SFML for graphics rendering. Players can click on the board to place their marker (X) during their turn.

### Win/Loss Counter
Track your wins and losses against the AI within the game interface. This feature enhances replayability and allows players to keep track of their performance.

## Prerequisites

Before running the project, ensure you have the following installed:

- SFML 2.5.1 or later
- C++ compiler that supports C++11

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your/repository.git
   cd repository


Controls
Left Mouse Click: Place marker (X) on the board during your turn.
Game Over: Click on "Click here to play again!" to reset the game and start over.

### Algorithms Used:
1. Minimax Algorithm
Purpose: Decision-making algorithm for two-player games.
Objective: Find the optimal move assuming both players play perfectly.
Method: Recursively evaluates possible moves, alternating between maximizing AI's score and minimizing opponent's score.
Application: Used by AI to determine its moves in Tic Tac Toe, aiming to win or force a draw.
2. Evaluation Function
Purpose: Assess the desirability of a game state (board configuration).
Criteria: Checks for potential wins and losses in rows, columns, and diagonals.
Scoring: Assigns scores based on the likelihood of winning, losing, or drawing.
Integration: Supports Minimax by guiding optimal move selection based on current board conditions.
Application in Tic Tac Toe:
Gameplay: AI uses Minimax after player moves to decide its move.
Strategy: AI strives to maximize its chances of winning or force a draw by predicting future game states.
Challenge: Enhances gameplay by providing a competitive AI opponent that adapts intelligently to player moves.
