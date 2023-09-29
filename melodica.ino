#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8,7);
// Define the pins for the buttons and the piezo buzzer
const int buttonPin1 = 14;
const int buttonPin2 = 15;
const int buttonPin3 = 16;
const int buttonPin4 = 17;
const int buttonPin5 = 18;
const int buttonPin6 = 19;
const int buttonPin7 = 5;
const int buttonPin8 = 4;

const int buzzerPin = 3;

// Define the frequencies for each note
const int C = 262;
const int D = 294;
const int E = 330;
const int F = 349;
const int G = 392;
const int A = 440;
const int B = 494;
const int C1 = 523;
const int Br=0;

const int keyPins[] = {14, 15, 16, 17, 18, 19, 5, 4};  // pins that are connected to the keys
const int keyMapping[] = {C, D, E, F, G, A, B, C1};  //corresponding keys

//pre-defining the songs
const int intro[]={C,E,G,C1,B,A,G,C1,C1,C1};
const int odetojoy[]={E,E,F,G,G,F,E,D,C,C,D,E,E,D,D,Br,E,E,F,G,G,F,E,D,C,C,D,E,D,C,C,Br,D,D,E,C,D,F,E,C,D,F,E,D,C,D,G,Br,E,E,F,G,G,F,E,D,C,C,D,E,D,C,C,Br};
const int star_wars[]={C,Br,G,Br,F,E,D,C1,Br,G,Br,F,E,D,C1,G,Br,F,E,F,D};
const int mary[]={E,D,C,D,E,E,E,Br,D,D,D,Br,E,G,G,Br,E,D,C,D,E,E,E,E,D,D,E,D,C,C1};
const int spring[] = {C,E,E,E,D,C,G,Br,G,F,E,E,E,D,C,G,Br,G,F,E,F,G,F,E,D,Br,E,G,F,E,F,E,A,G,Br,E,G,F,E,F,E,A,G,Br,E,A,G,Br,F,E,D,C,D,Br,C};
const int buttonPin = 2; 
const int selbuttonPin = 0; // Change this to the actual pin where your button is connected
  // Change this to the actual pin where your buzzer is connected

const int numSongs = 4;
const char *songNames[] = {"OdeToJoy", "Star Wars", "Mary had a little lamb", "Spring"};
int selectedSong = 0;

int songs[4][64]={{E,E,F,G,G,F,E,D,C,C,D,E,E,D,D,Br,E,E,F,G,G,F,E,D,C,C,D,E,D,C,C,Br,D,D,E,C,D,F,E,C,D,F,E,D,C,D,G,Br,E,E,F,G,G,F,E,D,C,C,D,E,D,C,C,Br},
{C,Br,G,Br,F,E,D,C1,Br,G,Br,F,E,D,C1,G,Br,F,E,F,D},{E,D,C,D,E,E,E,Br,D,D,D,Br,E,G,G,Br,E,D,C,D,E,E,E,E,D,D,E,D,C,C1},
{C,E,E,E,D,C,G,Br,G,F,E,E,E,D,C,G,Br,G,F,E,F,G,F,E,D,Br,E,G,F,E,F,E,A,G,Br,E,G,F,E,F,E,A,G,Br,E,A,G,Br,F,E,D,C,D,Br,C}};

bool pause = false;  // for waiting for the keypress from the user

void setup() {
  // Set button pins as inputs
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT_PULLUP);   
  pinMode(selbuttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  lcd.clear();  //initialising the LCD
  lcd.setCursor(0, 0);
  
  lcd.print("HELLO THERE!");  //initializing the LCD display
  introjingle();  //intro music
  delay(1000);  //wait

  displayMenu();
  
  //initialising the buttons
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  pinMode(buttonPin7, INPUT_PULLUP);
  pinMode(buttonPin8, INPUT_PULLUP);

  // Set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
  
}

void loop() {
  //playsong();
  // Check if each button is pressed and play the corresponding note
  if (digitalRead(buttonPin1) == LOW) {
    pinMode(buttonPin1, INPUT_PULLUP);
    playToneman(C);
  } else if (digitalRead(buttonPin2) == LOW) {
    pinMode(buttonPin2, INPUT_PULLUP);
    playToneman(D);
  } else if (digitalRead(buttonPin3) == LOW) {
    pinMode(buttonPin3, INPUT_PULLUP);
    playToneman(E);
  } else if (digitalRead(buttonPin4) == LOW) {
    pinMode(buttonPin4, INPUT_PULLUP);
    playToneman(F);
  } else if (digitalRead(buttonPin5) == LOW) {
    pinMode(buttonPin5, INPUT_PULLUP);
    playToneman(G);
  } else if (digitalRead(buttonPin6) == LOW) {
    pinMode(buttonPin6, INPUT_PULLUP);
    playToneman(A);
  } else if (digitalRead(buttonPin7) == LOW) {
    pinMode(buttonPin7, INPUT_PULLUP);
    playToneman(B);
  } else if (digitalRead(buttonPin8) == LOW) {
    pinMode(buttonPin8, INPUT_PULLUP);
    playToneman(C1);
  } else {
    // No button is pressed, turn off the buzzer
    noTone1(buzzerPin);
  }

  if (digitalRead(buttonPin) == LOW) {
    //delay(100);  // Debounce delay
    
      delay(100);
      
      selectedSong +=1;       // choosing the song to be played and learnt
      if(selectedSong>=numSongs)
      {
        selectedSong=0;
      }
      
      
      displayMenu();
    }
  if (digitalRead(selbuttonPin) == LOW) {
      // If the last option is selected, play the chosen song
      Simonsays(songs[selectedSong]);
      delay(1000);  // Add a delay to show that the song is playing
      displayMenu();
  }
}

// Function to play a tone on the buzzer
void playToneauto(int frequency, int pin) {
  //delay(200);
  tone1(buzzerPin, frequency, 250);
  
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  //delay(200);
  noTone1(buzzerPin);
  
  digitalWrite(pin, HIGH);
 
 // delay(150);
 
}

void playToneman(int frequency) {
  //delay(200);
  tone1(buzzerPin, frequency, 250);
  
  
  //digitalWrite(pin, LOW);
  //delay(200);
  noTone1(buzzerPin);
  //digitalWrite(pin, HIGH);
 // delay(150);
 
}
void tone1(int buzzerPin, int frequency, int duration) {
  int period = 1000000L / frequency; // Calculate the period in microseconds
  long startTime = millis(); // Get the current time

  while (millis() - startTime < duration) {
    digitalWrite(buzzerPin, HIGH); // Turn the buzzer on
    delayMicroseconds(period / 2); // Wait for half of the period
    digitalWrite(buzzerPin, LOW); // Turn the buzzer off
    delayMicroseconds(period / 2); // Wait for the other half of the period
  }
}

//function to play the selected song
void playsong(int song[])
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Now Playing :");
  lcd.setCursor(0, 1);
  lcd.print(songNames[selectedSong]);
  for(int i=0;i<64;i++)
  {
    playToneauto(song[i],getLedPin(song[i])); //playing induvidual notes in the song
  }  
}

//finding the corresponding LED that has to glow, for a note played during playback
int getLedPin(int index) {
  switch (index) {
    case 262: return buttonPin1;
    case 294: return buttonPin2;
    case 330: return buttonPin3;
    case 349: return buttonPin4;
    case 392: return buttonPin5;
    case 440: return buttonPin6;
    case 494: return buttonPin7;
    case 523: return buttonPin8;
    default: return buttonPin1;
  }
}

void noTone1(int buzzerPin) {
  digitalWrite(buzzerPin, LOW); // Set the buzzer pin to LOW
}


//intro music
void introjingle()
{
  for(int i=0;i<10;i++)
  {
    playToneauto(intro[i],getLedPin(intro[i]));
  }
  
}

//getting the corresponding value for the note played (buton pressed)
int getinp()
{ 
  if (digitalRead(buttonPin1) == LOW) {
    playToneman(C);  //playing the note
    return C;   // returning hte number
  } else if (digitalRead(buttonPin2) == LOW) {
    playToneman(D);
    return D;
  } else if (digitalRead(buttonPin3) == LOW) {
    playToneman(E);
    return E;
  } else if (digitalRead(buttonPin4) == LOW) {
    playToneman(F);
    return F;
  } else if (digitalRead(buttonPin5) == LOW) {
    playToneman(G);
    return G;
  } else if (digitalRead(buttonPin6) == LOW) {
    playToneman(A);
    return A;
  } else if (digitalRead(buttonPin7) == LOW) {
    playToneman(B);
    return B;
  } else if (digitalRead(buttonPin8) == LOW) {
    playToneman(C1);
    return C1;
  } else {
    // No button is pressed, turn off the buzzer
    return Br;
  }
}

//The main code for our idea
void Simonsays(int song[])
{
  // play the song throughout
  playsong(song);
  delay(5000);  // break for some time

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Your turn!:");  //user should play now
  // initialising to receive inputs from the user
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(buttonPin7, INPUT);
  pinMode(buttonPin8, INPUT);
  int count = 0;
  int start = 0;  //first portion of the learning block
  int bar = 4;   // size of the learning portion
  //int length = sizeof(song)/sizeof(song[0]);
  int length=64;  //length of the song
  while (start<length)
  {
    int ans[4];
    while (count<2)  // making sure the user plays the portion correctly twice
    {
      for(int i=start;i<(start+bar);i++)    // getting the portion of the song that is to be learned
      {
        playToneauto(song[i],getLedPin(song[i])); //playing the portion slowly
        delay(200);
      }
      noTone1(buzzerPin);  //switching off the buzzer sound
      while (true)     // checking again and again 
      {
        int inp;
        for (int i=0;i<4;i++)  //receive input
        {
          while(!getinp())
          {
            inp = getinp();
            ans[i] = inp;  //receive the user input and store it
            delay(1000);
            break;
          }
        }

        
        //checking if the notes played match with correct notes
        if(ans[0] == song[start] && ans[1] == song[start+1] && ans[2] == song[start+2] && ans[3] == song[start+3])
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Good Job! Keep Going:");  //the notes indeed match
          ++count;
          break;
        }
        else{
          lcd.clear();
          lcd.setCursor(0, 0);   // the notes do not match
          lcd.print("Try Again:");
          continue;
        }
      }
    }
    start = start+bar;  // moving to the next section of the song
  }   
}

// code to control the 1602 LCD panel
void displayMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selection Menu:");
  lcd.setCursor(0, 1);
  lcd.print(songNames[selectedSong]);
}