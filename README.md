# LogCore

A minimal and extensible logging module written in C++.  
Supports output to console (with colors) and to a `.txt` log file.  
Designed to be easily integrated into other projects.

---

## 🔧 Features

- Console logging with color-coded levels (Debug, Warning, Error)
- Optional logging to file (`log.txt`)
- Simple and clean API
- Easily extendable (e.g. for OpenGL, ImGui, etc.)

---

## 📁 Project Structure

- log_core/
- log.h # Public interface
- log.cpp # Core implementation



---

## ⚙️ How to Use

1. Clone or copy the `log_core` directory into your project.
2. Include the header:

## ! Example !

- #include "log_core/log.h"
- 
-    Initialize and use:

- init_log();
- log_msg(LogLevel::DEBUG, "Initialization complete", LogOutput::CONSOLELOG);
- shutdown_log();
