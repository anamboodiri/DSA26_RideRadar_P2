# RideRadar

RideRadar is a C++ application that helps users find the best used vehicle from a large dataset based on their personal preferences.  
The program filters, scores, and sorts vehicles, while comparing the performance of **Merge Sort** and **Cycle Sort**.

---

## Features

- Loads a large CSV dataset of used cars
- Allows users to filter vehicles by:
	- Manufacturer
	- Model
	- Year range
	- Mileage range
	- Transmission
	- Drivetrain
	- Price range
- Scores matching vehicles
- Sorts results using:
	- Merge Sort
	- Cycle Sort
- Displays top recommended vehicles
- Compares runtime of both algorithms

---

## How to Build and Run

### Using CLion
1. Open the project folder in CLion
2. Let CMake load automatically
3. Build and run the executable

### Using Terminal

From the project root:

```bash
mkdir build
cd build
cmake ..
make
./DSA26_RideRadar_P2
```

### Dataset Requirement

The dataset file must be located at:

`../resources/Data/carsEdit.csv`

If the file is missing or the path is incorrect, the program will not run properly.

### How to Use the Program
- Run the program
- Enter vehicle preferences when prompted
- Press Enter to skip optional text fields
- View the filtered and sorted results
- Compare runtime between Merge Sort and Cycle Sort

### Project Structure (Main Components)
- DatasetLoader → Loads CSV data
- Filter → Applies user preference filters
- Scoring → Assigns scores to vehicles
- Sorting → Implements Merge Sort and Cycle Sort
- UI → Handles terminal interaction
- main.cpp → Controls program flow

### Team Members
- Name: Archit Namboodiri
  GitHub: anamboodiri
- Name: Ahan Soni
  GitHub: ahansoni
- Name: Andrew Pliscofsky
  GitHub: PippyHonk

### Repository

Project Repository:
https://github.com/anamboodiri/DSA26_RideRadar_P2

---

## Example Usage

After running the program, the user will be prompted to enter vehicle preferences.

**Example:**

```
Enter manufacturer (or leave blank): Toyota
Enter model (or leave blank): Camry
Enter minimum year: 2018
Enter maximum year: 2023
Enter minimum mileage: 0
Enter maximum mileage: 60000
Enter transmission (or leave blank): Automatic
Enter drivetrain (or leave blank): FWD
Enter minimum price: 15000
Enter maximum price: 30000
```

The program will then:

- Filter matching vehicles
- Score the results
- Sort using Merge Sort and Cycle Sort
- Display the top recommended vehicles
- Show runtime comparison of both algorithms
