Here's the updated README with the complete `vcpkg` setup and CMake build process:

---

# Setting Up the Project

## 1. Install `vcpkg`
To set up the necessary dependencies for this project, you need to install `vcpkg`. Follow these steps:

### Option 1: Download Prebuilt Release
[Download the latest release of `vcpkg` from GitHub](https://github.com/microsoft/vcpkg/releases/).

### Option 2: Clone the Repository
Alternatively, clone the `vcpkg` repository by running the following command:
```bash
git clone https://github.com/Microsoft/vcpkg.git
```

---

## 2. Build `vcpkg`
Navigate to the directory where `vcpkg` is cloned or downloaded, and run the bootstrap script:
```bash
bootstrap-vcpkg.bat
```

---

## 3. Integrate `vcpkg` with MSBuild/Visual Studio
Run the following command to integrate `vcpkg` with MSBuild or Visual Studio:
```bash
.\vcpkg integrate install
```

Set the default triplet (for x64 builds) by running:
```powershell
[System.Environment]::SetEnvironmentVariable(
  'VCPKG_DEFAULT_TRIPLET','x64-windows', 'User'
)
```

This ensures that `vcpkg` automatically uses the correct architecture for libraries.

---

## 4. Install Required Libraries
Install the necessary dependencies for the project using `vcpkg`:
```bash
.\vcpkg install sdl2 sdl2-image sdl2-ttf
```

---

## 5. Build the Project with CMake

### Step 1: Project Structure
Ensure your project structure looks like this:
```
minesweeper_game/
├── src/
│   └── main.cpp         # Your source code
├── include/             # Header files (if any)
├── CMakeLists.txt       # Your CMake configuration
├── build/               # Create this folder for building
```

### Step 2: Create the `CMakeLists.txt` File
Place the following `CMakeLists.txt` file in the root of your project (`minesweeper_game`):

```cmake
cmake_minimum_required(VERSION 3.15)
project(MinesweeperGame LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Include header files
include_directories(include)

# Add executable
add_executable(MinesweeperGame ${SOURCES})

# Find and link SDL2 libraries (via vcpkg)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

target_link_libraries(MinesweeperGame PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)
```

### Step 3: Generate the Build System
1. Open a terminal and navigate to the `minesweeper_game` directory:
   ```bash
   cd minesweeper_game
   ```

2. Create a `build/` directory:
   ```bash
   mkdir build
   cd build
   ```

3. Run the following CMake command, pointing to the `vcpkg` toolchain file:
   ```bash
   cmake -DCMAKE_TOOLCHAIN_FILE=D:/programming/vcpkg/scripts/buildsystems/vcpkg.cmake ..
   ```

This will generate the necessary build files.

### Step 4: Build the Project
Run the build process with:
```bash
cmake --build . --config Debug
```

---

## 6. Open in Visual Studio (Optional)
If you are using Visual Studio:
1. After running the CMake command, a `.sln` file will be generated in the `build/` directory.
2. Open this `.sln` file in Visual Studio.
3. Select the desired build configuration (Debug or Release).
4. Build and run the project from Visual Studio.

---

## Summary of Commands
For quick reference, here are the commands you’ll need to execute:

1. Clone `vcpkg`:
   ```bash
   git clone https://github.com/Microsoft/vcpkg.git
   cd vcpkg
   bootstrap-vcpkg.bat
   .\vcpkg integrate install
   ```

2. Set the triplet for x64 builds:
   ```powershell
   [System.Environment]::SetEnvironmentVariable(
     'VCPKG_DEFAULT_TRIPLET','x64-windows', 'User'
   )
   ```

3. Install the required libraries:
   ```bash
   .\vcpkg install sdl2 sdl2-image sdl2-ttf
   ```

4. Build the project:
   ```bash
   cd minesweeper_game
   mkdir build
   cd build
   cmake -DCMAKE_TOOLCHAIN_FILE=D:/programming/vcpkg/scripts/buildsystems/vcpkg.cmake ..
   cmake --build . --config Debug
   ```

---