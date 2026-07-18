int STBY = 9;
int AIN1 = 6;
int AIN2 = 5;
int BIN1 = 10;
int BIN2 = 11;
int resetTime = 500;

long timeStart = millis();
String action = "";

long getTime() {
  return millis() - timeStart;
}

void reset(bool timeReset = false) {
  action = "";
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(STBY, HIGH);
  if (timeReset) timeStart = millis();
}

void forward() {
  reset();
  delay(resetTime);
  action = "forward";
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void backward() {
  reset();
  delay(resetTime);
  action = "backward";
  //Serial.println(action);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void left() {
  reset();
  delay(resetTime);
  action = "left";
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void right() {
  reset();
  delay(resetTime);
  action = "right";
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void control(String direction, long start, long end) {
  long time = getTime();
  bool change = time >= start && time < end && action != direction;
  if (change) {
    if (direction == "forward") forward();
    else if (direction == "backward") backward();
    else if (direction == "left") left();
    else if (direction == "right") right();
    else if (direction == "") reset();
    else if (direction == "reset") reset(true);
  }
}

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  Serial.begin(9600);
  reset(true);

}

void loop() {
  control("forward", 0, 2800);
  control("right", 2800, 3550);
  control("forward", 3550, 15200);
  control("left", 15200, 16400);
  control("backward", 16400, 21000);
  control("", 21000, 25000);
}
