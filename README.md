# Senha

This repository contains an implementation in C language of the game [Mastermind](https://pt.wikihow.com/Jogar-Senha).

# Authors

- David Albuquerque. (github.com/Albuquerque-David)
- Seth Ribeiro. (github.com/sunnyseth)
- Matheus Cardoso. (github.com/Cardosaum)

# Table of Content

- [How to Play](#how-to-play)
- [Dependencies](#dependencies)
- [Compilation](#compilation)
- [Running](#running)

# How to Play

MASTERMIND is a code-breaking game.
- The program itself will generate a password and the player has to guess it's sequence.
- The player must break the code and guess the password within the tries given. Each game,
        there will be a total of 8 tries and each try they has to choose 4 colors in a total of 6
        available and try to guess the password.
            
- Each time the player tries to guess and fails, both the number of right answers and tries
        left will appear on screen.

- The player hints will be displayed in the Hints section, available as B or W.
B: Some of the colors is correct, but in the wrong position.
W: Some of the colors is correct and in the right position.
            
- The player loses the game if there are no more tries left.
    
Available colors: R G Y B M C.
Example of entry (input is case insensitive): rbby or RBBY.

# Dependencies
```
gcc
make
```

# Compilation
```
git clone https://github.com/Cardosaum/ufrj-comp1-senha
cd ufrj-comp1-senha
make
```

# Running

`./bin/main` or `cd bin && ./main`
