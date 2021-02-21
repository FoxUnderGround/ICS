byte letters[] = {0b100000, //a
                  0b110000, //b
                  0b100100, //c
                  0b100110, //d
                  0b100010, //e
                  0b110100, //f
                  0b110110, //g
                  0b110010, //h
                  0b010100, //i
                  0b010110, //j
                  0b101000, //k
                  0b111000, //l
                  0b101100, //m
                  0b101110, //n
                  0b101010, //o
                  0b111100, //p
                  0b111110, //q
                  0b111010, //r
                  0b011100, //s
                  0b011110, //t
                  0b101001, //u
                  0b111001, //v
                  0b010111, //w
                  0b101101, //x
                  0b101111, //y
                  0b101011  //z
                 };

//hello 110010 100010 111000 111000 101010

int pins[] = {2, 5, 8, 11, 14, 17};

byte data = 0b000000;
byte lastdata = 0b000000;
bool pressed = false;
long timepressed = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i <= 5; i++) {
    int pin = pins[i];
    pinMode(pin + 2, OUTPUT);
    pinMode(pin + 1, OUTPUT);
    pinMode(pin, INPUT);

    digitalWrite(pin + 2, LOW);
    digitalWrite(pin + 1, HIGH);

  }
}

void loop() {
  data = 0b000000;

  for (int i = 0; i <= 5; i++)
  {
    if (digitalRead(pins[i]) == HIGH)
    {
      pressed = true;
    }
  }

  if (pressed)
  {
    delay(250);
    for (int i = 0; i <= 5; i++)
    {
      data = data + (digitalRead(pins[i]) << (5 - i));
    }

    pressed = false;
  }

  for (int x = 0; x < 26; x++)
  {
    if (letters[x] == data)
    {
      Serial.println(char(0b01000001 + x));
      delay(500);
      break;
    }
  }
  //Serial.println(data, BIN);
}
