# Triviality 

Trivia game written in C++ and Qt5 as a learning exercise. The project is made with a strong
emphasis on the MVC design pattern and general OOP principles to facilitate further extensibility.

The game has three possibile sources of data:

1. The [Open Trivia Database](https://opentdb.com). The game goes online and requests
so called question-packs under JSON form, which are parsed and then used in-game.
2. Local SQLite database.
3. Local text file format. 

# Installation and Usage
The game needs simply needs Qt5 installed. Once Qt5 is installed, 
it can be easily compiled and ran using the provided `qmake` file, in your preferred IDE or, assuming a 
bash environment, by executing
```bash
git clone git@github.com:thesstefan/triviality.git && cd triviality
qmake && make
./quiz
```

# Gameplay
<p align="center">
  <img src="https://github.com/thesstefan/triviality/blob/master/extra/gameplay.gif" alt="Gameplay GIF"/>
</p>

# TODO:
1. [ ] Add ability to switch between data sources in-game.
2. [ ] Add time limit and time based scoring. 
3. [ ] Add new game modes (eg. Blitz) and power-ups (eg. 50/50).
4. [ ] Store user settings.
5. [ ] Implement user statistics analysis menu.
6. [ ] Improve local databases (+contribute to [OpenTDB](https://opentdb.com)) .
7. [ ] Add sound effects.
8. [ ] Improve general aesthetics of the game.
