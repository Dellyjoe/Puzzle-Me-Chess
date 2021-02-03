# Puzzle Me Chess

Author: Joseph Vitale

## Description

Create a physical chess puzzle on a chess board. This board will have user checkability and software mapped defined chess puzzles. At first there will be 3 different chess puzzles ranging from easy to hard. There will be an OLED screen to show the user where to put the prices to set up the chess puzzle. This project will also have a feature to show user hint or show asnwer. After completing the puzzle a sound will play to tell the user he/she has completed the puzzle.

## Functionality

* User show hint, LED to light up which piece to move, but not where
* User show asnwer, LED to ligh up which piece to move and where it will be moved to
* OLED to indicate where the user will place each piece
* LED light to indicate where the piece will be placed

## Limitations

* Not knowing which piece is on each 64 spots
* Not being able to set up the board for you
* Not having 50 different puzzles to choose from
* Not being able to light  each square along the perimeter
* Not having multiple colors to indicate wrong or right answer

## Larger System Chess Idea

Create an automated chess board that could play Human Vs. Human, Human Vs. Computer, and Human Vs. Chess Puzzle.

* 1. Human Vs. Human will be playable over bluetooh or in person.
* 2. Human Vs. Computer will use Stockfish chess engine ELO level (400 - 2900)
* 3. Human Vs. Chess Puzzle will haveover 50 Puzzles from ELO level (400 + 30)0)

## Functional Block Diagram

The belove picture shows the functional block diagram

![Functional Block Diagram](Pictures_readme/Functional Block Diagram.PNG)
