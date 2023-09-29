<!-- You have some errors, warnings, or alerts. If you are using reckless mode, turn it off to see inline alerts.
* ERRORs: 0
* WARNINGs: 0
* ALERTS: 4 -->

**RISC-V Product Development Hackathon:**

Team Name: Melodica          			
Team Members:  Sujay Samuel S,
               Samuel Robinson R

**Stage 1-Product Idea Submission Form**



1. **Product Title**

**“Melody Master Jr”- Unlock the world of Music!!**



2. **What does your product do?**
          - Plays Music

          - Teaches kids to play the piano


	      - Provides Interactive OLED interface for song selection


          - Features illuminated keys


          - Upload new songs using mobile application Via Bluetooth



3. **What all interfaces of the board will be used in the product ?**

    We will be using GPIO PINS for the Speaker Output, Key input and LED Output, UART protocol for the Bluetooth connection and I2C for the OLED display and EEPROM.

4. **Does the product utilise sensors?**
* No
5. **Block Diagram**
![alt_text](images/image3.jpg "image_tooltip")

6. **Algorithm flowchart**

    
![alt_text](images/image4.jpg "image_tooltip")


7. **Algorithm of the product in bullet points.**

_        _



1. User selects song from main menu:

    The user begins by choosing a song they'd like to learn from an array of songs that are stored in the memory. Also new songs can be loaded onto the toy by an app via bluetooth.

2. Play song to be learnt once for trial:

    The song is played once to provide the user with an initial listening experience. It also gives the user a feel for how the song should sound.     

3. Play a portion of the song once:

    Next, a section of the song is played to familiarize the user with a part of the melody. This is for the user to get a better understanding of the portion of the song.

4. User inputs notes to match the predetermined sequence:

    This is the learning phase. The user attempts to play the notes they heard, trying to match the provided sequence. 

5. Compare if sequence is correct: 

    The system stores the user’s key-strokes and then checks if the user's input matches the expected sequence of notes. The user is evaluated based on whether the timing is correct and if the notes played by the user match that determined by the song. 

6. If not request user to repeat again: 

    If there's an error, the user is encouraged to try again, until they get the sequence right twice. This is to ensure that the user 

7. Move to next portion of the piece once the user gets sequence correct twice:

    Once the user successfully reproduces the sequence twice, they progress to the next part of the song. This is mainly to make sure the user gets a good grip of the song.

8. Keep repeating till the entire song is complete:

    The learning process continues, segment by segment, until the entire song is learned.

9. Make the user play the song once through and encourage the user to play correctly:

    The user is then made to play the entire song as a whole after consolidating all the learnings of the individual parts of the songs

10.  User can upload new songs via bluetooth, and delete to conserve memory.
8. **Rough sketch of the final product.**

    
![alt_text](images/image1.jpg "image_tooltip")


9. **Rough sketch of the Internal product **

    
![alt_text](images/image5.png "image_tooltip")

