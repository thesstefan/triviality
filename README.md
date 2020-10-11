# Triviality 

Trivia game written in C and Qt5. The game has three possibilities sources of data:

1. The [Open Trivia Database](https://opentdb.com). The game goes online and requests
so called question-packs under JSON form, which are parsed and then used in-game.
2. Local SQLite database
3. Local text file format 

# Installation
```bash
git clone https://github.com/thesstefan/triviality
cd triviality
qmake && make
```

# Usage
```bash
./quiz
```
# TODO:

1. [ ] Add ability to switch between data sources in-game.
2. [ ] Add time limit and time based scoring. 
3. [ ] Add new game modes (eg. Blitz) and power-ups (eg. 50/50)
4. [ ] Store user settings.
5. [ ] Implement user statistics analysis menu.
6. [ ] Improve local databases (+ contribute to [OpenTDB](https://opentdb.com)) 
7. [ ] Add sound effects.
8. [ ] Improve general aesthetics of the game.

# Gameplay
<p align="center">
  <img src="https://github.com/thesstefan/triviality/blob/readme/extra/gameplay.gif" alt="Gameplay GIF"/>
</p>
