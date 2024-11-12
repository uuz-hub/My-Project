# VS Project
#Our computer room reservation system is a desktop application developed in C++, designed to assist schools or institutions in efficiently managing the usage of computer rooms. This program does not require a network connection and is suitable for running in a standalone environment, suitable for small to medium-sized data center management needs.

Main functions:

User management:
Support adding, deleting, and modifying user information, including usernames, passwords, and permission levels.
The administrator user has the highest authority and can perform all operations; Ordinary users can only view and book data centers.
Computer room management:
You can add, delete, and modify data center information, including data center name, capacity, and available time period.
The system will automatically record the current usage status and reservation status of each data center.
Appointment management:
Users can check the idle time period of the computer room and make appointments according to their needs.
The system will check the legality of the reservation (such as time conflicts, data center capacity, etc.) and provide corresponding prompts.
Support viewing and canceling reserved data centers.
Data saving and loading:
The system will save all user, data center, and reservation information in local files to ensure data security and persistence.
Provide data loading function, which can automatically load previously saved data when the program starts.
Friendly user interface:
Adopting a command-line interface (CLI), providing concise and clear operation prompts and menu options.
Users can perform various operations by entering commands, and the system will respond based on the input
