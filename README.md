# Mini-Projects-in-C
🚆 Automatic Train Platform Allocation Simulator (C)

A console-based simulation project written in C that automatically allocates railway platforms to trains based on their arrival and departure times.
The program simulates minute-by-minute time progression, dynamically assigns platforms, and visually displays the current state of the station in real time.

📌 Features

⏱️ Real-time simulation using minute-by-minute time progression

🚉 Automatic platform allocation

🕒 Handles train arrivals and departures accurately

📊 Displays live train status:

Not arrived

Waiting (no platform)

At platform

Left

🧠 Uses sorting + simulation logic

🧩 Modular code using structures

🖥️ Console animation using Sleep() and system("cls")

🛠️ Technologies Used

Language: C

Compiler: GCC / MinGW

Platform: Windows

Libraries:

stdio.h

stdlib.h

stdbool.h

windows.h

conio.h

🧩 How It Works (Logic Overview)

Train arrival and departure times are converted into minutes.

Trains are sorted by arrival time.

The simulation runs minute by minute:

Trains arrive when current time ≥ arrival time

Trains leave when current time == departure time

Free platforms are assigned to waiting trains

The screen refreshes every simulated minute to show live status.

The simulation ends when all trains have departed.

📥 Input Format

Number of platforms

Number of trains

For each train:

Train ID

Arrival time (HH MM)

Departure time (HH MM)

📤 Output

A continuously updating console table showing:

Train ID	Arrival	Departure	Platform	Status
▶️ How to Run
Compile
gcc train_simulator.c -o train_simulator

Run
train_simulator


⚠️ This project uses Windows-specific libraries (windows.h, conio.h)
It is intended to be run on Windows OS.

📷 Sample Output
Current simulated time: 09:15

ID   Arr   Dep   Plat   Status
---------------------------------------
101  09:00  09:30   1   At platform
102  09:05  09:40   -   Waiting (no platform)
103  09:10  09:25   2   At platform

📚 Concepts Learned

C Structures and Arrays

Time-based simulation

Sorting algorithms

State management

Console animation

Problem decomposition

Real-world system modeling

🎓 Academic Level

Course: B.Tech Computer Science Engineering

Semester: 1st Semester

Difficulty Level: Intermediate

Type: Mini Project / Simulation Project

🚀 Future Improvements

Priority handling for express trains

Queue visualization

Color-coded output

Cross-platform support (Linux/macOS)

GUI version

File-based input/output

👤 Author

Rishikesh N
B.Tech CSE – 1st Semester

⭐ Acknowledgements

Inspired by real-world railway scheduling and platform management systems.

📜 License

This project is open-source and free to use for learning and academic purposes.