#ifndef PLATE_H
#define PLATE_H
float _plate_initialPressure;
// https://www.firgelliauto.com/blogs/news/18090523-how-to-use-an-arduino-with-firgelli-automations-linear-actuators
inline void plate_init() {
  pinMode(PLATE_A, OUTPUT);
  pinMode(PLATE_B, OUTPUT);

  _plate_initialPressure = analogRead(PLATE_LOAD_SENSOR_PIN) * 1.10;
}

inline void plate_insert() {
  digitalWrite(PLATE_A, HIGH);
  digitalWrite(PLATE_B, LOW);
}

inline void plate_retract() {
  digitalWrite(PLATE_A, LOW);
  digitalWrite(PLATE_B, HIGH);
}

inline void plate_stop() {
  digitalWrite(PLATE_A, LOW);
  digitalWrite(PLATE_B, LOW);
}

inline bool plate_isTouching() {
  return _plate_initialPressure < analogRead(PLATE_LOAD_SENSOR_PIN);
}
#endif
