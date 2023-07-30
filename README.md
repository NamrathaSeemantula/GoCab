# GoCab

**Description:**

The provided code implements a simple cab booking system in C++. It allows users to sign up, login, and book a cab for their desired destinations. The code utilizes classes for handling data structures like Queues, Maps, and Binary Search Trees (BSTs) to manage drivers and their availability.

**Key Features:**
1. **User Registration and Login:** Users can sign up with a unique username, user ID, and password. Upon successful registration, their information is stored in a hash table for later authentication during login.

2. **Maps and Locations:** The system employs a map data structure to manage locations and their corresponding IDs. It also uses another map to maintain reverse mapping from location ID to location names.

3. **Drivers and Availability:** Driver details, including ID, name, phone number, and rating, are stored in a BST. The system uses queues to track drivers available at different locations. When a user books a cab, the code efficiently selects the nearest available driver.

4. **Shortest Path (Dijkstra's Algorithm):** To calculate the distance between the source and destination locations, the code uses Dijkstra's algorithm to find the shortest path in a weighted graph representing the city's locations.

5. **Cab Booking Process:** After the user provides the source and destination, the system calculates the fare and displays details like the distance, estimated arrival time, and an OTP for authentication.

6. **Cancellation Option:** Users can cancel their ride before the driver arrives, and the system ensures the driver's availability is updated accordingly.

**Usage Instructions:**
1. When running the program, the user can choose to sign up (if new) or log in (if already registered).
2. After successful login, the user can book a cab by providing the source and destination locations.
3. The system displays the estimated fare, distance, driver details, and OTP for authentication.
4. If the user decides to cancel the ride, the system handles the cancellation and updates driver availability.

