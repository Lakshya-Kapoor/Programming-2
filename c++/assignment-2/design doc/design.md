## Olympic Calendar Scheduling System

### 1. `VenueManager` Class

- **Purpose**: Manages all venues for Olympic events.
- **Attributes**:
  - `no_of_venues`: Number of venues managed.
  - `venues_list[100]`: Array of pointers to `Venue` objects (up to 100 venues).
- **Key Methods**:
  - `addVenue()`: Adds a new venue.
  - `delVenue()`: Removes an existing venue.
  - `showVenues()`: Displays all managed venues.
  - `addEvent()`: Schedules an event at a specified venue.
  - `delEvent()`: Removes an event from a specified venue.
  - `showEvents()`: Displays all events at a venue on a specific date.
  - `showCalendar()`: Shows the full event calendar for a venue.

### 2. `Venue` Class

- **Purpose**: Represents a venue where events are held.
- **Attributes**:
  - `name`: Name of the venue.
  - `location`: Location of the venue.
  - `capacity`: Seating capacity of the venue.
  - `calendar[31]`: Array of `Day` objects, representing a calendar for events across 31 days.
- **Key Methods**:
  - `display()`: Shows the venue’s details.
  - `showCalendar()`: Displays the venue’s event calendar.

### 3. `Day` Class

- **Purpose**: Manages events scheduled on a specific day.
- **Attributes**:
  - `no_of_events`: Number of events on the day.
  - `events_list[24]`: Array of `Event` objects (up to 24 events per day).
- **Key Methods**:
  - `addEvent()`: Adds a new event to the day.
  - `delEvent()`: Removes an event from the day.
  - `showEvents()`: Displays all events scheduled on the day.

### 4. `Event` Class

- **Purpose**: Represents an individual event.
- **Attributes**:
  - `name`: Name of the event.
  - `start_time`: Start time of the event.
  - `end_time`: End time of the event.
- **Key Methods**:
  - `display()`: Shows event details.
