# Philosophers - A Threading and Mutex Project

This project explores the basics of threading and the use of mutexes in C programming by simulating the classic "Dining Philosophers" problem.

## Overview
The program models a scenario where philosophers sit at a round table, alternating between eating, thinking, and sleeping. Each philosopher requires two forks (one on their left and one on their right) to eat, and the simulation ensures proper synchronization to prevent data races and starvation.

## Key Features
- **Thread-based Implementation**: Each philosopher is implemented as a thread, with forks represented as shared resources protected by mutexes.
- **Synchronization**: Mutexes are used to coordinate access to forks, ensuring thread-safe operations.
- **Real-time Logging**: State changes (e.g., eating, thinking, sleeping, and dying) are logged with timestamps for clear tracking of events.

## Requirements
The program ensures that:
- Philosophers do not starve.
- Forks are correctly shared between philosophers using mutexes.
- The simulation avoids data races.
- Messages are displayed in a consistent and non-overlapping manner.

## How to Run
The program takes the following arguments:
1. `number_of_philosophers`: Total number of philosophers (and forks).
2. `time_to_die` (ms): Maximum time a philosopher can go without eating before dying.
3. `time_to_eat` (ms): Time a philosopher spends eating.
4. `time_to_sleep` (ms): Time a philosopher spends sleeping.
5. `[number_of_times_each_philosopher_must_eat]` (optional): Stops the simulation once all philosophers have eaten this many times.

### Example
To compile the program, use the provided `Makefile`:
```bash
make
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]


