# block_game

Simple block-based game (Tetris-like) written in C++ using raylib.

**Summary**
- Small game project with Visual Studio solution and project files under the `game/` folder.
- Uses `raylib` for rendering (example `main.cpp` demonstrates a raylib window).

**Features**
- Random block generation and basic Tetris mechanics (move, rotate, clear rows).

**Build & Run (Windows)**
1. Open the solution [game.sln](game.sln) in Visual Studio (x64 target).
2. Select the `x64` platform and `Debug` (or `Release`) configuration and build the solution.
3. The executable will be in `x64/Debug/` (or `x64/Release/`). Some dynamic libraries (`raylib.dll`, `glfw3.dll`) are present in `x64/Debug/` in this repo for convenience.
4. Run the generated `game.exe`.

**Controls**
- Left arrow: move block left
- Right arrow: move block right
- Down arrow: move block down (and score small points)
- Space: rotate block

**Notes**
- This repo currently includes some build artifacts in `x64/Debug/`. The `.gitignore` added prevents new build artefacts from being committed.
- If you want to remove already-committed binaries, I can help remove them from history or delete and re-commit.

**License**
- Add a license file if you want to make this project open-source.
