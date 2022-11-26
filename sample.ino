void setup() {
  Serial.begin(115200);
}

String data = "";

int indexX, indexY, indexAst;
String x, y;

void loop() {
  //  format: ,1,-10*
  //  format: ,x,y*
  if (Serial.available() > 0) {
    char d = Serial.read();
    Serial.println(d);

    //  * means the end of the data
    if (d == '*') {
      Serial.println(data);

      indexX = data.indexOf(',');
      indexY = data.indexOf(',', indexX + 1);
      indexAst = data.indexOf('*');
      x = data.substring(indexX + 1, indexY);
      y = data.substring(indexY + 1, indexAst - 1);

      Serial.print("X: ");
      Serial.println(x);
      Serial.print("Y: ");
      Serial.println(y);

      data = "";
    } else {
      data += d;
    }
  }
}
