#include <stdio.h>
#include <string.h>

// Structure to store details of one vehicle
typedef struct
{
    char vehicleNumber[20]; // Registration number
    int entryHour;          // Vehicle entry time
    int isParked;           // 1 = Parked, 0 = Empty
} Vehicle;

// Array of structures representing 30 parking slots
Vehicle parking[30] = {0};

// Function to register a new vehicle
void vehicleEntry()
{
    char newVehicleNumber[20]; // Stores input temporarily
    int i, j; // i finds empty slot, j checks duplicates

    printf("\nEnter Vehicle Number: ");
    scanf("%19s", newVehicleNumber);

    // Check all slots for duplicate vehicle numbers
    for(j = 0; j < 30; j++)
    {
        // Only check slots containing vehicles
        if(parking[j].isParked == 1)
        {
            // strcmp returns 0 when strings are equal
            if(strcmp(parking[j].vehicleNumber, newVehicleNumber) == 0)
            {
                printf("Vehicle Already Parked!\n");
                return; // Stop vehicle entry
            }
        }
    }

    // Find the first empty parking slot
    for(i = 0; i < 30; i++)
    {
        if(parking[i].isParked == 0)
        {
            break; // Empty slot found
        }
    }

    // If i reaches 30, all slots are occupied
    if(i == 30)
    {
        printf("Parking is Full!\n");
        return;
    }

    // Store vehicle number in the empty slot
    strcpy(parking[i].vehicleNumber, newVehicleNumber);

    printf("Enter Entry Hour (0-23): ");
    scanf("%d", &parking[i].entryHour);

    // Check whether entry time is valid
    if(parking[i].entryHour < 0 || parking[i].entryHour > 23)
    {
        printf("Invalid Entry Time!\n");
        return;
    }

    // Mark the slot as occupied
    parking[i].isParked = 1;

    // Actual slot number is index + 1
    printf("\nVehicle Entry Successful!\n");
    printf("Assigned Parking Slot: %d\n", i + 1);
}

// Function to remove a vehicle and calculate fee
void vehicleExit()
{
    char exitVehicleNumber[20]; // Vehicle number to search
    int i, exitHour, parkingFee;

    printf("\nEnter Vehicle Number: ");
    scanf("%19s", exitVehicleNumber);

    // Search all parking slots for the vehicle
    for(i = 0; i < 30; i++)
    {
        // Check only occupied slots
        if(parking[i].isParked == 1)
        {
            // Check whether vehicle numbers match
            if(strcmp(parking[i].vehicleNumber, exitVehicleNumber) == 0)
            {
                printf("Enter Exit Hour (0-23): ");
                scanf("%d", &exitHour);

                // Exit time must be valid and not before entry
                if(exitHour < parking[i].entryHour || exitHour > 23)
                {
                    printf("Invalid Exit Time!\n");
                    return;
                }

                // Parking charge is Rs. 10 per hour
                parkingFee = (exitHour - parking[i].entryHour) * 10;

                // Minimum parking charge is Rs. 10
                if(parkingFee == 0)
                {
                    parkingFee = 10;
                }

                printf("\n----- PARKING RECEIPT -----\n");
                printf("Vehicle Number: %s\n", parking[i].vehicleNumber);
                printf("Parking Slot: %d\n", i + 1);
                printf("Parking Fee: Rs. %d\n", parkingFee);

                // Free the slot for the next vehicle
                parking[i].isParked = 0;

                printf("Vehicle Exit Successful!\n");
                return; // Exit completed
            }
        }
    }

    // Executed if no matching vehicle was found
    printf("Vehicle Not Found!\n");
}

// Function to display parking availability
void availableSlots()
{
    int occupied = 0; // Counts parked vehicles

    // Check all 30 parking slots
    for(int i = 0; i < 30; i++)
    {
        // Increase count if the slot is occupied
        if(parking[i].isParked == 1)
        {
            occupied++;
        }
    }

    printf("\n----- PARKING STATUS -----\n");
    printf("Total Slots: 30\n");
    printf("Occupied Slots: %d\n", occupied);
    printf("Available Slots: %d\n", 30 - occupied);
}

int main()
{
    int choice; // Stores user's menu choice

    // Display menu repeatedly until user selects 4
    while(1)
    {
        printf("\n===== SMART CAMPUS PARKING SYSTEM =====\n");
        printf("Press 1 for Vehicle Entry\n");
        printf("Press 2 for Vehicle Exit\n");
        printf("Press 3 to Check Available Slots\n");
        printf("Press 4 to Exit the Program\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Execute the function based on user's choice
        switch(choice)
        {
            case 1:
                vehicleEntry();
                break;

            case 2:
                vehicleExit();
                break;

            case 3:
                availableSlots();
                break;

            case 4:
                printf("Thank you for using Smart Parking!\n");
                return 0; // Terminate the program

            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }
}
