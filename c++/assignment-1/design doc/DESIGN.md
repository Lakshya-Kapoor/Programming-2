# Calendar scheduling system

> **Note:** Use a markdown reader for better readability

## Functionalities provided

1. `addVenue`: Adding a new venue
2. `delVenue`: Deleting a venue
3. `showVenues`: Displaying all venues
4. `addEvent`: Scheduling new event in a venue
5. `delEvent`: Deleting scheduled event from a venue
6. `showEvents`: Displaying all the events scheduled on a particular date in a venue
7. `showCalendar`: Displaying all events scheduled in a venue

## Data structures used

### **1. Venue**

Represented with a struct. The calendar of a venue is an array representing all 30 days.

```c
typedef struct venue Venue;
struct venue {
    // Name of venue
    char venue_name[50];
    // Location of venue
    char venue_location[50];
    // Capacity of venue
    int venue_capacity;
    // Represents the calendar of events
    Date* calendar[31];
    // Total events scheduled in this venue
    int total_events;
};
```

### **2. Date**

The Date struct represents the list of all events on a particular day.

```c
typedef struct date Date;
struct date {
    // List of all events on a specific day
    Event* events_list[24];
    // Count of events on a specific day
    int event_count;
};
```

### **3. Event**

The Event struct contains details of events.

```c
typedef struct event Event;
struct event {
    // Event start time
    int start_hour;
    // Event end time
    int end_hour;
    // Event name
    char event_name[50];
};
```

### **4. Storing Venues**

List of all venues is stored inside a global array.

```c
// List of all venues
Venue* venues[100];
// No of created venues
int no_of_venues;
```
