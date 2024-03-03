#include <iostream>
#include <string>

void gameOver() {
    std::cout << "Game Over" << std::endl;
}

void startGame() {
    std::cout << "Start Game" << std::endl;
}

void continueGame() {
    std::cout << "Continue Game" << std::endl;
}

void moveLeft() {
    std::cout << "Move Left" << std::endl;
}

void moveRight() {
    std::cout << "Move Right" << std::endl;
}

void moveUp() {
    std::cout << "Move Up" << std::endl;
}

void moveDown() {
    std::cout << "Move Down" << std::endl;
}

void jump() {
    std::cout << "Player Jump" << std::endl;
}

void update() {
    std::cout << "Update Game World" << std::endl;
}

void drawGameGraphics() {
    std::cout << " =============++++++ Drawing Game World +===+++++======="
              << std::endl;
}

void spawnEnemy(int enemyID) {
    std::cout << "Spawning Enemy " << enemyID << std::endl;
}
int main() {
    std::cout << "Welcome to Part 3 of c++ for Games dev" << std::endl;

    // Conditions and If statements in C++
    // Conditions  are used make decisions based on certain Criteria.

    // less than : a < c
    // less than or equal  a <= b
    // Greater than : a > d
    // Greater than or equal: f  >= g
    // Equal to : w ==w ;
    // Not equal to : w != e;
    // if - > is used to execute a block of code if a certain condition is met.

    unsigned int health = 0;  // int -2b to 2b , unsigned int -> 4b +

    std::cout << "Enter player health" << std::endl;
    std::cin >> health;

    // if statement
    if (health <= 0) {
        gameOver();
    }

    else if (health >= 10 && health <= 15) {
        startGame();
    }

    // Else statement
    //  it execute a block code if the "if statement" is false ;

    else {
        continueGame();
    }

    // Short Hand if Else statement - > Ternary operator
    //  bool isPlayerHealthMedian = (condition) ? true : false;

    bool isPlayerHealthMedian = (health >= 15) ? true : false;
    std::string isPlayerOk = (health > 5) ? "OK" : "Bad";

    if (isPlayerHealthMedian) {
        continueGame();
    }
    std::cout << "Status of Player Health: " << isPlayerOk << std::endl;

    // Switches Statement in C++
    // The switch statement is used to execute different blocks of code
    // depending on the value of a variable.
    //  switch (expression) {
    //     case x:
    //     // code block
    //     break;

    //     case y:
    //     // code block
    //     break;

    //     default:
    //     // code block

    //  }

    // The break Keyword is used to break out of the switch block

    // The default keyword specifies some code to run if there is no case match

    char direction = 'b';
    // Player movement direction =  w : up , A: left , s: down , d: right, y:
    // Jump Up

    std::cout << "Enter Player Movement Direction" << std::endl;
    std::cin >> direction;

    switch (direction) {
        case 'W':
            moveUp();

            break;
        case 'A':
            moveLeft();
            break;
        case 'S':
            moveDown();
            break;
        case 'D':
            moveRight();
            break;
        case 'Y':
            jump();
            break;
        default:
            std::cout << "Player is not moving" << std::endl;
            break;
    }

    // Loops in C++
    // Loops are used to repeat a block of code multiple times.

    // While Loop:
    // The While loop is used to repeat a block while a certain condition is
    // true; while(condition) {
    //     // block of code
    // }

    bool isPlayerAlive = (health < 0) ? true : false;
    while (isPlayerAlive) {
        update();
        drawGameGraphics();
        health--;
    }

    // Do-While loop
    // The do-while loop is similar to the while loop, but it executes the block
    // of code at least once before checking the condition

    // do {
    //     block of code
    // }
    //  while (condition);

    do {
        update();
        drawGameGraphics();
    } while (isPlayerAlive);

    // For Loop:
    // The for loop is used to repeat a block of code a fixed number of times.
    // for(int i = 0; i < 10; i++) { block code }

    // Continue
    // The continue statement is used to skip to the next iteration of a loop

    int numberOfEnemiesInGame = 10;

    // Matrix , Vectors
    for (int i = 0; i < numberOfEnemiesInGame; i++) {
        spawnEnemy(i);
        for (int j = 0; j < numberOfEnemiesInGame; j++) {
            spawnEnemy(i + j);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0) {
            continue;
        }
        std::cout << i << std::endl;
    }
}