# Smart-Campus-Parking-System
# Smart Campus Parking System

A simple C program that manages a campus parking lot and, most importantly, lets vehicle owners check whether a slot is free before they drive in.

We built it for our college mini hackathon. The lot has 30 fixed slots, and the program keeps track of which ones are occupied, which vehicles are parked, and when they came in.

## What it does
- Registers a vehicle with its number and entry hour, and assigns the first free slot
- Stops the same vehicle from being parked twice
- Shows a "Parking is Full!" message when all 30 slots are taken
- Calculates the fee on exit (Rs. 10 per hour, minimum Rs. 10) and prints a receipt
- Shows total, occupied and available slots at any time

## How to run
```bash
gcc mini_hackathon_code.c -o parking
./parking
```

Then pick an option from the menu:
1. Vehicle Entry
2. Vehicle Exit
3. Check Available Slots
4. Exit Program

## Possible improvements
- Support overnight parking (right now hours are 0-23 only)
- Better handling of invalid input
- A database or file to store records permanently
- A mobile or web version

## Team
parking.c
