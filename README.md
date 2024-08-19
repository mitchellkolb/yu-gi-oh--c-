

<h1 align="center">Yu-Gi-Oh</h1>

<p align="center">
  <img alt="Github top language" src="https://img.shields.io/github/languages/top/mitchellkolb/yu-gi-oh--c-?color=DE4830">

  <img alt="Github language count" src="https://img.shields.io/github/languages/count/mitchellkolb/yu-gi-oh--c-?color=DE4830">

  <img alt="Repository size" src="https://img.shields.io/github/repo-size/mitchellkolb/yu-gi-oh--c-?color=DE4830">

  <img alt="Github stars" src="https://img.shields.io/github/stars/mitchellkolb/yu-gi-oh--c-?color=DE4830" />
</p>

<p align="center">
<img
    src="https://img.shields.io/badge/C++-DE4830?style=for-the-badge&logo=c&logoColor=white"
    alt="Website Badge" />
<img
    src="https://img.shields.io/badge/Xcode-000000?style=for-the-badge&logo=apple&logoColor=white"
    alt="Website Badge" />
</p>

This is a text based recreation of the Yu-Gi-Oh! card game, written in C++. I focused on the implementation of key data structures such as stacks and queues to manage gameplay mechanics. This project shows off my knowledge of object-oriented design principles, efficient data handling, and the application of class templates.


![project image](resources/image1.png)

<details>
<summary style="color:#5087dd">Watch the Full Video Demo Here</summary>

[![Full Video Demo Here](https://img.youtube.com/vi/VidKEY/0.jpg)](https://www.youtube.com/watch?v=VidKEY)

</details>

---


# Table of Contents
- [What I Learned](#what-i-learned-in-this-project)
- [Tools Used / Development Environment](#tools-used--development-environment)
- [Team / Contributors / Teachers](#team--contributors--teachers)
- [How to Set Up](#how-to-set-up)
- [Project Overview](#project-overview)
    - [Gameplay Details](#gameplay-details)
    - [Data Structures Used](#data-structures-used)
    - [Files and Structure](#files-and-structure)
    - [Results](#results)
    - [Future Work](#future-work)
- [Acknowledgments](#acknowledgments)

---

# What I Learned in this Project
- Using C++ to design and test classes with implementations using class templates.
- Utilizing data structures like stacks and queues for card decks and player hands.
- Demonstrating knowledge in object-oriented programming, file I/O, and data management in C++ when dereferencing pointers.



# Tools Used / Development Environment
- C++
- Xcode
- Terminal
- MacOS





# Team / Contributors / Teachers
- [Mitchell Kolb](https://github.com/mitchellkolb)
- Professor. Nadra Guizani





# How to Set Up
This project was implemented on my macbook using:
- Xcode at the time. Any terminal with gcc installed will work
- Clone this repository 
- Open terminal at the codebase `~.../yu-gi-oh--c-/yugioh-codebase/`
- Run the `a.out` that is included or compile your own executable with
```zsh
g++ -o my_program main.cpp
```
- Then use `./a.out` or `./my_program` depending on whatever you named your executable.





# Project Overview
This project is a C++ implementation of the Yu-Gi-Oh! card game. The game includes designing and testing classes, implementing class templates, and utilizing data structures like stacks and queues for managing card decks and player hands. Players can create decks, add cards, and engage in battles where the game logic handles life points, attack and defense mechanics, and determines the winner.

## Gameplay Details
The gameplay involves two players who start with a deck of cards, represented using a stack. Players draw cards from their decks into their hands and place cards into attack and defense queues. The game proceeds in turns, where players choose cards from their queues to engage in battles. The outcome of each battle is determined by comparing the attack and defense points of the chosen cards, and life points are adjusted accordingly. The game continues until one player's life points are reduced to zero, determining the winner.

## Data Structures Used
In this project, I used several key data structures:
- **Stacks:** Used to represent the players' decks, where cards are drawn from the top.
- **Queues:** Used to manage the cards in attack and defense positions, ensuring that the order of play is maintained.
- **Arrays:** Used to store the players' hands, allowing them to select cards for battle.


## Files and Structure
- **`main.cpp`**: Implements the game logic and user interface, allowing players to create decks, add cards, and initiate battles.
- **`Queue.h` and `Queue.cpp`**: Define and implement the Queue class, which is used to manage the attack and defense cards in play.
- **`Stack.h` and `Stack.cpp`**: Define and implement the Stack class, which is used to manage the players' card decks.
- **`Yu_Gi_Oh_card_list_full.csv` and `Yu_Gi_Oh_Card_list.csv`**: Contain lists of cards that can be used to populate the players' decks. The full card list contains more card details that I didn't include functionality for in my game.

## Results
I successfully implemented the core gameplay mechanics, including deck management, card battles, and life point calculations. The game runs smoothly, and the logic correctly handles various scenarios, such as ties in attack and defense. I consider this programming project as one that demonstrates that I have a solid understanding of object-oriented programming and data structure utilization.

## Future Work
Future improvements could include expanding the game's rules to include more complex card effects or implementing a graphical user interface to enhance the player experience.






--- 
# Acknowledgments
This codebase and all supporting materials was made as apart of a course for my undergrad at WSU for CPTS 122 - Data Structures C/C++ in the Summer of 2020. 

