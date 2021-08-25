// * note   frequency
// * c          261 Hz
// * d          294 Hz
// * e          329 Hz
// * f          349 Hz
// * g          392 Hz
// * a          440 Hz
// * b          493 Hz
// * C          523 Hz
// * D          587 Hz
// * E          659 Hz
// * F          699 Hz
// * G          784 Hz
// * A          880 Hz
// * B          989 Hz
uint8_t pin = 4;
uint16_t duration = 1000;
char notes[] = "GGAGcB GGAGdc GGgecBA ffecdc";

uint8_t tempos[] = {
  4, 4, 2, 2, 2, 1, 16, 
  4, 4, 2, 2, 2, 1, 16, 
  4, 4, 2, 2, 2, 2, 1, 
  16, 4, 4, 2, 2, 2, 1
};

void setup() {
  pinMode(pin, OUTPUT);

  for (uint8_t index = 0; index < sizeof(notes); index++) {
    if (notes[index] == '\s')
      delay(duration / tempos[index]);
    else
      playNotes(notes[index], duration / tempos[index]);
  }
}

void loop() {

}

void playNotes(char note, uint16_t duration) {
  char notesCollection[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B', 'c', 'd', 'e', 'f', 'g', 'a', 'b'};
  uint16_t frequencyCollection[] = { 261, 294, 329, 349, 392, 440, 493, 523, 587, 659, 699, 784, 880, 989 };

  for (uint8_t index = 0; index < sizeof(notesCollection) - 1; index++) {
    if (notesCollection[index] == note) {
      tone(pin, frequencyCollection[index], duration);
      delay(duration);
      break;
    }
  }
}



